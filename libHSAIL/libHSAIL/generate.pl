# University of Illinois/NCSA
# Open Source License
#
# Copyright (c) 2013, Advanced Micro Devices, Inc.
# All rights reserved.
#
# Developed by:
#
#     HSA Team
#
#     Advanced Micro Devices, Inc
#
#     www.amd.com
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal with
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is furnished to do
# so, subject to the following conditions:
#
#     * Redistributions of source code must retain the above copyright notice,
#       this list of conditions and the following disclaimers.
#
#     * Redistributions in binary form must reproduce the above copyright notice,
#       this list of conditions and the following disclaimers in the
#       documentation and/or other materials provided with the distribution.
#
#     * Neither the names of the LLVM Team, University of Illinois at
#       Urbana-Champaign, nor the names of its contributors may be used to
#       endorse or promote products derived from this Software without specific
#       prior written permission.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
# CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE
# SOFTWARE.
use v5.10;
use Carp;
use strict;
use Data::Dumper;
$Data::Dumper::Sortkeys = 1;
use Getopt::Long;

my $dk_root;
my $re2c_path;
my $touch_path;
my $nohdl;
my $nore2c;
die unless GetOptions("nore2c!" => \$nore2c, "nohdl!" => \$nohdl, "re2c=s" => \$re2c_path, "dk=s" => \$dk_root, "touch=s" => \$touch_path);
$dk_root //= $ENV{DK_ROOT};
if (defined $dk_root) { $re2c_path //= "$dk_root/re2c/re2c"; }
$re2c_path //= "re2c";
my $indir = $ARGV[0];
my $outdir = $ARGV[1];
$indir && $outdir or die "Usage: generate.pl <input directory> <output directory>";
mkdir $outdir;

my $struct = undef;
my $enum = undef;

my $structs = +{};
my $typedefs = +{};
my $enums = +{};
my $gvalues = +{};
my $prevenum = undef;
my %preprops = ();

my $wrapperImpls = "";
my %scanner;
my $entity;
my $utilities = +{};
my $phantomof = undef;

sub Name2MACRO {
    my $t = $_[0];
    $t=~s/[A-Z]/_$&/g;
    return uc($t);
}

sub MACRO2Name {
    my $t = $_[0];
    $t=~s/_([^_])([^_]*)/$1.lc($2)/ge;
    return $t;
}

do {
    open F,"<$indir/Brig_new.hpp" or die;
    local $/ = undef;
    $_ = <F>;
    close F;
};
#use re 'debug';

sub gvalue($) {
  my $val = $gvalues->{$_[0]};
  if ($val =~ /^[0-9]+$/ or $val =~ /^0x[0-9a-f]+$/i) {
    return $val;
  } else {
    return eval($val);
  }
}

sub parseError() {
        my $pos = pos($_);
    my $text = substr($_, 0, $pos, "");
    my $ln = 1;
    my $lpos = 0;
    while($text =~ /\G[^\n]*\n/gc) { $ln++; $lpos = pos($text); }
    my $col = $pos - $lpos + 1;
    die "Parse error at line $ln, col $col : $_";
}

#
# This does not pretend to be a full-featured C parser. It only parses a subset of C
# declarations used in the BRIG header.
#

while(pos($_) < length($_)) {
    # whitespace: skip
    if (m/\G\s+/gc) {
    }
    # end of struct/enum
    elsif (m/\G\}\s*(\w*)\s*;/gc) {
        if ($struct) {
            my $name = $struct->{name};
            $struct = $entity = undef;
        } elsif ($enum) {
            $enum = $entity = undef;
        } else {
            parseError;
        }
    }
    # struct field
    elsif ($struct && /\G(?<type>\w+)\s+(?<name>\w+)(?:\s*\[(?<size>\d+)\])?(?:\:\s*(?<width>\d+))?;/gc) {
        $entity = +{%+,%preprops}; %preprops=();
        if ($phantomof) {
            $entity->{phantomof} = $phantomof;
            $phantomof = undef;
        }
        push @{$struct->{fields}}, $entity;
    }
    # enum element
    elsif ($enum && /\G(?<name>\w+)\s*(?:=\s*(?<val>[^,\n}\/]+))?\s*,?/gc) {
        $entity = +{%+,%preprops};
        %preprops=();
        push @{$enum->{entries}}, $entity;
        my $val = $entity->{val};
        $val =~ s/([0-9]+)u\b/$1/g;
        my $was = "";
        if ($val !~ /^[0-9]+$/ and $val !~ /^0x[0-9a-f]+$/i) {
          $val =~ s/(\b[a-z_][a-z_0-9]+\b)/gvalue(\"$1\")/ig;
        };
        if ($val !~ /\S/) {
          if (defined $prevenum) {
            $val = "gvalue(\"$prevenum\") + 1";
          } else {
            $val = 0;
          }
        }
        $gvalues->{$entity->{name}} = $val;
        $prevenum = $entity->{name};
    }
    # typedef
    elsif (!$struct && !$enum && /\Gtypedef\s+(?<type>\w+)\s+(?<name>\w+)\s*;/gc) {
        $typedefs->{$2} = $entity = +{%+,%preprops};
        %preprops=();
    }
    # first line of struct
    elsif (!$struct && !$enum && /\Gstruct\s+(\w+)\s*\{/gc) {
        $structs->{$1} = $struct = $entity = +{%preprops};
        %preprops=();
        my $name = $1;
        $struct->{name} = $struct->{rawbrig} = $name;
    }
    # first line of enum
    elsif (!$struct && !$enum && /\Genum\s+(?<name>\w+)\s*\{/gc) {
        $enums->{$1} = $enum = $entity = +{%+,%preprops};
        $prevenum = undef;
        %preprops=();
    }
    # //.ignore{ ..... //} completely ignores the whole block of text
    elsif(m{\G//\.ignore\{.*?//\}}gsc) {
        # do nothing
    }
    elsif(m{\G//\.alias\s+(\w+)\s*\:\s*(\w+)\s*\{}gc) {
        my $name = "Brig".$1;
        my $parent = "Brig".$2;
        $structs->{$name} = $struct = $entity = +{%preprops};
        %preprops=();
        $struct->{name} = $name;
        $struct->{parent} = $parent;
        $struct->{rawbrig} = $structs->{$parent}->{rawbrig};
    }
    # manually add list attributes to the preceding entity
    elsif(m{\G//\+(\w++)\s*([^\n]*)}gc) {
        push @{$entity->{$1}}, $2;
    }
    # comments which will be added to the following entity
    elsif(m{\G(///[^\n]*+)}gc) {
        push @{$preprops{comments}}, $&;
    }
    # attributes in different formats:
    # 1) as a word, .attr=word
    # 2) as quoted string, .attr="some text"
    # 3) as a block of perl code .attr={ ... code ... }
    # Note that perl code cannot be followed with any other attributes on the same line
    elsif(m{\G//\.(?<key>\w++)(?:\=(?<quotedstr>\"(?:[^"\\]++|\\.)*+\")|\=(?:\$(?<vars>\w+(?:\$\w)*))?\{(?<code>[^\n]++)|\=(?<val>[^\{\$\"]\S*)|(?!\=))}gc) {
        #print STDERR "$& $1:$2:$3:$4:$5\n";
        #print STDERR Dumper(\%+),"\n";
        $entity->{$+{key}}
        = exists($+{quotedstr}) ? eval($+{quotedstr})
        : exists($+{code}) ? do {
            local $@;
            local $_;
            my @vars = split /\$/, $+{vars};
            $entity->{$+{key}."#deps"} = [@vars];
            my $subcode = 'sub { my ($x,$o) = @_; ';
            for my $var (@vars) {
                $subcode .= "my \$$var=\$x->{$var}; ";
            }
            $subcode .= $+{code};
            chomp $subcode;
            my $x=eval $subcode;
            die "$subcode\n$@" if $@;
            $x
        }
        : exists($+{val}) ? $+{val}
        : "true";
    }
    # so-called "phantom fields" which exist in wrappers only.
    # they are essentially aliases to preceding fields
    elsif (m{\G//\^\^}gc) {
        $phantomof = $entity;
        while($phantomof->{phantomof}) {
            $phantomof = $phantomof->{phantomof};
        }
    }
    elsif (m{\G//(?!\.)([^\n]*)}gc) {
    # push @{$entity->{comments}}, $1;
    }
    elsif (m{\G/\*(.*?)\*/}gsc) {
    # push @{$entity->{comments}}, $1;
    }
    else {
        parseError;
    }
};

sub make;

make "enums0_dump.pl", \&makePrint, Data::Dumper->Dump([$enums], ["enums"]);
make "structs0_dump.pl", \&makePrint, Data::Dumper->Dump([$structs], ["structs"]);
make "typedefs0_dump.pl", \&makePrint, Data::Dumper->Dump([$typedefs],["typedefs"]);

#
# List of attributes currently used:
# struct.wname: C++ wrapper name
#     (if not defined, autoderived from BRIG struct name)
# struct.enum: BRIG kind
#     (if not defined, autoderived from BRIG struct name)
# struct.isroot: true if struct has no parent
# struct.parent: parent name
#     (if not defined, autoderived by stripping BRIG struct name)
# struct.fields: list of struct fields
#

my $textIncludeItems = "#include \"HSAILItems.h\"\n";
my $textBeginNamespace = "namespace HSAIL_ASM {\n\n";
my $textEndNamespace = "\n} // namespace HSAIL_ASM\n";
my $textLicense = '';
open F, "<$0"; # open this script as a text file
# read the license and translate perl comments into C++ comments
while((my $line = <F>) =~ s/^#/\/\//) {
    $textLicense .= $line;
}
close F;

#### POSTPROCESSING ####

my @wstructs = grep { !$_->{nowrap} } values %$structs;

for my $s (@wstructs) {
    my $sname = $s->{name};
    if (!$s->{wname}) {
        ($s->{wname} = $sname) =~ s/^Brig//;
    }
    $s->{enum} //= "BRIG_KIND".Name2MACRO($s->{wname});
    next if $s->{isroot};
    if (!$s->{parent}) {
        $sname =~ /^(Brig[A-Z][a-z]+)/ or die "$sname";
        if ($1 eq "BrigInst") {
            $s->{parent} = "BrigInstBase";
        } else {
            $s->{parent} = $1;
        }
    }
    die "$sname: bad parent: $s->{parent}" unless exists $structs->{$s->{parent}};
}

sub calcAttr {
    my ($entriesKey, $object, $attrKey) = @_;
    my $cs = \$object->{"$attrKey#calcState"};
    next if $$cs eq 'done';
    die "circular attribute dependencies in $object->{name}" if $$cs eq 'working';
    $$cs = 'working';
    for my $dep (@{$object->{"$attrKey#deps"}}) {
        calcAttr($entriesKey, $object, $dep);
    }
    $$cs = 'done';
    for my $entry (@{$object->{$entriesKey}}) {
        local $_ = $entry->{name};
        next if exists $entry->{$attrKey};
        my $val = $object->{$attrKey}->($entry, $object);
        next unless defined $val;
        $entry->{$attrKey} = $val;
    }
}

sub calcAttrs {
    my ($objs, $entriesKey) = @_;
    for my $object (values %$objs) {
        for my $attrKey (grep { ref $object->{$_} eq "CODE" } keys %$object) {
            calcAttr($entriesKey, $object, $attrKey);
        }
    }
}

calcAttrs $enums, "entries";
calcAttrs $structs, "fields";

for my $s (@wstructs) {
    my $p = $s;
    my %seen;
    while(!$p->{isroot}) {
        die "$p->{name}: loop detected" if $seen{$p}++;
        my $pp = $structs->{$p->{parent}};
        die "$s->{name}: bad parent of $p->{name}: $p->{parent}" unless $pp;
        $p = $pp;
        $p->{children}->{$s->{name}} = $s;
    }
    for my $f (@{$s->{fields}}) {
        $f->{skip} //= 1 if $f->{name} =~ /^reserved/;
        if (!$f->{wname}) {
            $f->{wname} = $f->{name};
            $f->{wname} =~ s/^[cdos]_//;
        }
        my $ftype = $f->{type};
        my $e;
        if (!$f->{enum} and $ftype=~/^(.*?)[0-9]+_t$/ and ($e = $enums->{$1})) {
            $f->{enum} = $e->{name};
            $f->{defValue} //= $e->{defValue} if exists $e->{defValue};
        }
        if ($typedefs->{$ftype}) {
            my $tt = $typedefs->{$ftype};
            $f->{wtype} //= $tt->{wtype} if exists $tt->{wtype};
            $f->{wtype} //= "EnumValRef<Brig::$f->{enum},$tt->{type}>" if exists $f->{enum};
            $f->{wtype} //= "ValRef<$tt->{type}>";
            $f->{defValue} //= $tt->{defValue} if exists $tt->{defValue};
        }
        $f->{wtype} //= "ValRef<$f->{type}>";
        if (!$f->{acc}) {
            $f->{acc} = $f->{wtype};
            $f->{acc} =~ s/^./lc($&)/e;
        }
        # HACK
        $f->{acc} =~ s/(valRef)<.*?>/$1/;
    }
}

my @sortedStructs;
for (my @q = sort { $b->{wname} cmp $a->{wname} } grep { $_->{isroot} } @wstructs; @q; ) {
    my $s = pop @q;
    push @q, sort { $b->{wname} cmp $a->{wname} } grep { $_->{parent} eq $s->{name} } @wstructs;
    push @sortedStructs, $s;
}
#### END OF POSTPROCESSING ####

sub makeHSAILInitBrig {
    printf $textLicense;
    for my $s (@sortedStructs) {
        printf "void ".$s->{wname}."::initBrig() {\n";
        if (!$s->{generic} && !$s->{standalone}) {
          print "  initBrigBase(sizeof(Brig::",$s->{rawbrig},"), Brig::",$s->{enum},");\n";
        }
        if (!$s->{isroot}) {
          my $pwname = $structs->{$s->{parent}}->{wname};
          print "  $pwname","::initBrig();\n";
        }
        for my $f (@{$s->{fields}}) {
            next if $f->{phantomof};
            next if $f->{name} eq "base";
            my $fname = $f->{name};
            my $ftype = $f->{type};
            if ($structs->{$f->{type}}) {
                print "  $f->{wname}().initBrig();\n";
                next;
            }

            my $rhs;
            $rhs //= "sizeof(Brig::".$s->{name}.")"
                            if ($fname eq "byteCount");
            $rhs //= "Brig::".$s->{enum}    if ($fname eq "kind");
            $rhs //= $f->{defValue}         if (exists $f->{defValue});

            if ($rhs ne undef) {
                my $lhs = "brig()->$fname";
                if ($f->{size}) {
                    print "  for (int i=0;i<$f->{size};i++) {\n";
                    print "    ${lhs}[i] = $rhs;\n";
                    print "  }\n"
                } else {
                    print "  $lhs = $rhs;\n";
                }
            }
        }
        printf "}\n\n";
    };
};

sub makeSwitch($$%) {
    my ($attrKey, $ename, %options) = @_;
    my $fn = $options{fn} // ($ename =~ /^(?:Brig)?(.)(.*)/ and lc($1).$2."2str");
    my $proto = $options{proto} // "const char* $fn(unsigned arg)";
    my $arg = $options{arg} // "arg";
    my $context = $options{context};
    my $defaultCode = $options{default} // "return NULL";
    my $text = \$utilities->{$options{incfile} // "BrigUtilities"};
    $wrapperImpls .= "$proto;\n" unless $options{incfile};
    $$text .= "$proto {\n";
    $$text .= "  using namespace Brig;\n";
    $$text .= "  $options{pre}\n" if $options{pre};
    $$text .= "  switch( $arg ) {\n";
    my $e = $enums->{$ename} or die "makeSwitch: bad enum: $ename";
    for my $entry (sort { $a->{name} cmp $b->{name} } @{$e->{entries}}) {
        my $entryName = $entry->{name};
        my $attrValue = $entry->{$attrKey};
        next unless defined $attrValue;
        next if $entry->{skip};
        next if $entry->{"no_".$attrKey};
        $attrValue="\"$attrValue\"" if $proto=~/^(?:const\s+)?char\s*\*/;
        my $attrCode = "return $attrValue";
        my $scanner = $options{scanner} || $options{token};
        my $token = $entry->{$options{tokenpfx}."token"} || $options{token};
        if ($scanner && $attrValue ne '""') {
            my $tokenText = $attrValue;
            my $block;
            if ($token) {
                # HACK: modifier token ids have an underscore as prefix.
                # This underscore is stripped from token id and added to token text.
                if ($token=~s/^_//) {
                  $tokenText =~ s/^"/"_/; $tokenText .= "/EOMOD"; $scanner = "_mods_";
                } else {
                  $tokenText .= ($scanner eq "Instructions") ? "/EOMOD" : "/EOKW";
                }
                $block = sprintf "%-50s %-30s", "brigId = Brig::$entryName;", "return $token; ";
                if ($context) {
                    $scanner{$scanner}->{$tokenText}->{$context} = $block;
                } else {
                    $scanner{$scanner}->{$tokenText} = $block;
                }
            } else {
                $block = sprintf "%-40s", "return Brig::$entryName; ";
                $scanner{$scanner}->{$tokenText} = $block;
            }

        }
        if (defined($attrCode) && $attrCode ne $defaultCode) {
            if ($options{reverse}) {
#                print STDERR "$attrCode $entryName\n";
                $attrCode =~ s/^return\s*//;
                $entryName =~ s/^/return /;
                $$text .= sprintf "    case %-30s : %s;\n", $attrCode, $entryName;
            } else {
                $$text .= sprintf "    case %-30s : %s;\n", $entryName, $attrCode;
            }
        }
    }
    $$text .= "$options{post}    default : $defaultCode;\n    }\n}\n\n";
}

sub filterHashByPrefix {
    my $hash = shift;
    my $prefix = shift;
    my @keys = keys %$hash;
    return tokenpfx=>$prefix."_", map { $_=~/^${\$prefix}_(.*)/ ? ($1 => $hash->{$_}) : () } @keys;
}

sub makeMnemo {
    my $e = $enums->{shift()};
    my $attrKey = shift;
    return unless $e->{$attrKey};
    makeSwitch $attrKey, $e->{name}, filterHashByPrefix($e, $attrKey);
}

sub generateBrigUtilities {
    for my $en (sort keys %$enums) {
        for my $attrKey (sort keys %{$enums->{$en}}) {
            if ($attrKey eq "mnemo" or $attrKey=~s/_switch$//) {
                makeMnemo $en, $attrKey;
            }
        }
    }
    for my $en (sort keys %$enums) {
        next if $enums->{$en}->{nodump};
        makeSwitch "name", $en, proto=>"const char* anyEnum2str( Brig::$en arg )", default=>"return \"??\"";
    }
}

sub printComments {
    my $cc = $_[0];
    my $pfx = $_[1] // "";
    return unless defined $cc;
    for my $c (@$cc) {
        print "$pfx$c\n";
    }
}

sub makeWrappers {
    printf $textLicense;
    print map { "class $_->{wname};\n" } grep { !$_->{nowrap} } @sortedStructs;
    print "\n\n";

    for my $s (@sortedStructs) {
        next if $s->{nowrap};

        my $sname   = $s->{name};
        my $swname  = $s->{wname};
        my $parent  = $s->{isroot} ? undef : $structs->{$s->{parent}};
        my $pwname  = $s->{isroot} ? "ItemBase" : $parent->{wname};

        printComments($s->{comments});

        print "class $swname : public $pwname {\n";

        if ($s->{children}) {
            print "    // children: ",join(",",sort keys %{$s->{children}}),"\n";
        }

        print "public:\n";

        if ($s->{isroot} && !$s->{standalone}) {
            print "\n\ttypedef $swname Kind;\n" ;
            print "\n\tenum { SECTION = Brig::",$s->{section}," };\n";
        }

        print "\n\t/// accessors\n";
        my $findex = -1;
        for my $f (@{$s->{fields}}) {
            ++$findex;
            next if $f->{skip};
            my ($fname,$ftype,$helper,$wname,$wtype) = @{$f}{qw(name type acc wname wtype)};
            next if $fname eq "base";
            my $args = "()";
            my $fldvalue = $fname;
            if ($f->{phantomof}) {
                $fldvalue = $f->{phantomof}->{name};
            }
            if ($f->{size}) {
                $args = "(int index)";
                $fldvalue = $fldvalue."[index]";
            }
            my $constness = "";
            printComments $f->{comments}, "\t";

            if ($f->{wspecial}) {
                my $specialType = $f->{wspecial};
                if ($f->{wspecialgeneric}) {
                    printf("\t%-50s %s;\n","template<typename T> $specialType<T>","$wname()$constness");
                    $wrapperImpls .= "template<typename T> inline $specialType<T> ${\$swname}::$wname()$constness { return $specialType<T>(*this); }\n";
                } else {
                    printf("\t%-50s %s;\n","$specialType","$wname()$constness");
                    $wrapperImpls .= "inline $specialType ${\$swname}::$wname()$constness { return $specialType(*this); }\n";
                }
            }

            printf("\t%-50s %s;\n", $wtype, "$wname$args$constness");
            $wrapperImpls .= "inline $wtype ${\$swname}::$wname$args$constness { return $helper(&brig()->$fldvalue); }\n";

            if (defined $f->{hcode}) {
                my $t = "\t".join("\n\t", @{$f->{hcode}})."\n";
                $t =~ s/KLASS/$swname/g;
                print $t;
            }
            if (defined $f->{implcode}) {
                my $t = join("\n", @{$f->{implcode}})."\n";
                $t =~ s/KLASS/$swname/g;
                $wrapperImpls .= $t;
            }
        }


        print "\n\n\t/// constructors\n";
        print "\t$swname()                           : $pwname() { } \n";
        print "\t$swname(MySection* s, Offset o)     : $pwname(s, o) { } \n";
        my @children = $s->{children} ? sort grep { !$_->{generic} } values %{$s->{children}} : ($s);
        if (!$s->{standalone}) {
            print "\t$swname(BrigContainer* c, Offset o) : $pwname(&c->sectionById(SECTION), o) { } \n";
        }

        if (!$s->{standalone}) {
            print "\n\t/// assignment\n";
            print "\tstatic bool isAssignable(const ItemBase& rhs) {\n\t\treturn ",
                join("\n\t\t    || ", (map { "rhs.kind() == Brig::".$_->{enum} } sort { $a->{enum} cmp $b->{enum} } @children ))
                ,";\n\t}\n";
            print "\t$swname(const ItemBase& rhs) { assignItem(*this,rhs); } \n";
            print "\t$swname& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }\n";
        } else {
            print "\t$swname(const $swname& rhs) : ItemBase(rhs) { } \n";
            print "\t$swname& operator=(const $swname& rhs) { reset(rhs); return *this; }\n";
        }

        print "\n\t/// raw brig access\n";
        print "\ttypedef Brig::$s->{rawbrig} BrigStruct;\n";
        print "\t      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }\n";
        print "\tconst BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }\n";
        print "\tvoid initBrig(); \n";

        if ($s->{isroot} && !$s->{standalone}) {
            print "\n\t/// root utilities\n";
            print "\tOffset  brigSize() const { return brig()->byteCount; }\n";
            print "\t$swname next() const { return $swname(section(), brigOffset() + brigSize()); }\n";
        }

        if (!$s->{generic}) {
            print "\n\t/// final utilities\n";
            print "\tstatic const char *kindName() { return \"$s->{wname}\"; }\n";
        }

        print "};\n\n";
    }
};

sub makeDispatchByItem {
    printf $textLicense;
    for my $s (@sortedStructs) {
        next if $s->{nowrap};
        next unless $s->{generic};
        print "template <typename RetType, typename Visitor>\n";
        print "RetType dispatchByItemKind_gen($s->{wname} item,Visitor& vis) {\n";
        print "\tusing namespace Brig;\n";
        print "\tswitch(item.kind()) {\n";
        for my $c (sort { $a->{enum} cmp $b->{enum} } values %{$s->{children}}) {
            next if $c->{generic};
            print "\tcase $c->{enum}: return vis($c->{wname}(item));\n";
        }
        print "\tdefault: assert(false); break;\n\t}\n";
        print "\treturn RetType();\n}\n\n";
    }
}

sub makePropAccessors {
    printf $textLicense;
    my @roots = grep { $_->{isroot} } @sortedStructs;
    my %tns = ();
    for my $s (@sortedStructs) {
        for my $f (@{$s->{fields}}) {
            next if $f->{name} =~ /^(kind|operands|reserved|opcode|type|size)$/;
            my $tn = "$f->{type} $f->{name}";
                        $tns{$tn} = 1;
        }
    }
    for my $tn (sort keys %tns) {
        print "## tn: $tn\n";
        for my $root (@roots) {
            next if $root->{standalone};
            next unless $root->{name} eq "BrigInst"; ##
            for my $s (@sortedStructs) {
                next unless grep { $_ eq $s->{name} } @{$root->{children}};
                my $n = 0;
                for my $f (@{$s->{fields}}) {
                    my $ftn = "$f->{type} $f->{name}";
                    next unless $ftn eq $tn;
                    printf "[%d] %s %s::%s\n", $n++, $f->{type}, $s->{name},$f->{name};
                }
            }
            }
    }
}

sub makeEnumFlds {
    my $pfx = "";
    for my $s (@sortedStructs) {
        next if $s->{nowrap};
        print "template <typename Visitor> void enumerateFields_gen($s->{wname} obj, $pfx Visitor & vis) {\n";
        if (!$s->{isroot}) {
           print "  enumerateFields_gen(",$structs->{$s->{parent}}->{wname},"(obj), vis);\n";
        }
        for my $f (@{$s->{fields}}) {
            next if $f->{skip} || $f->{novisit};
            die if $f->{wspecialgeneric};
            next if $f->{name} eq "byteCount" or $f->{name} eq "kind" or $f->{name} eq "base";
            my $acc = "obj.$f->{wname}";
            if ($f->{size}) {
                my $size = $f->{size};
                if ($size <= 1 || $f->{wspecial}) {
                    print "  vis($acc(),\"$f->{name}\");\n";
                } else {
                    print "  for (unsigned i=0;i<$size;i++) {\n    vis($acc(i),\"$f->{name}\", i);\n  }\n";
                }
            } elsif ($structs->{$f->{type}}) {
                print "  enumerateFields($acc(), vis);\n";
            } else {
                print "  vis($acc(),\"$f->{name}\");\n";
            }
        }
        print "}\n\n";
    }
}

sub makeStaticChecks {
    printf $textLicense;
    for my $s (@sortedStructs) {
        my $sn = "Brig::".$s->{name};
        my @fields = grep { !exists $_->{phantomof} } @{$s->{fields}};
        my $n = @fields;
        for(my $i = 0; $i < $n; ++$i) {
            last if $fields[$i]->{noaligncheck};
            my $fn = $fields[$i]->{name};
            my $err = "\"bad alignment in $sn\"";
            if ($i == 0) {
                print "static_assert(offsetof($sn, $fn) == 0, $err);\n";
            }
            if ($i > 1) {
                my $pfn = $fields[$i-1]->{name};
                print "static_assert(offsetof($sn, $pfn)+sizeof((($sn","*)0)->$pfn) == offsetof($sn,$fn), $err);\n";
            }
            if ($i == $n - 1) {
                print "static_assert(offsetof($sn, $fn)+sizeof((($sn","*)0)->$fn) == sizeof($sn), $err);\n";
            }
        }
        print "\n";
    }
}

################################################################################
################################################################################
################################################################################
# Generation of low-level BRIG validator (a part of Validator component)

sub fieldsInclParents {
  my ($s, $pfx) = @_;
  return ($s->{isroot} ? () : fieldsInclParents($structs->{$s->{parent}}, 'base.'.$pfx)),
         map { [$pfx . $_->{name}, $_] } grep { $_->{name} ne "base" } @{$s->{fields}};
}

sub cpp
{
    my $txt = shift;
    $txt =~ s/^\s+\|//gm;
    return $txt;
}

sub makeValidatorFunc {
    my ($name, $suff, $filter) = @_;
    $suff //= "Fields";
    $filter //= '^*$';

    print cpp(<<"EOT");
        |
        |
        |bool ValidatorImpl::ValidateBrig${name}${suff}($name item) const
        |{
        |    using namespace Brig;
        |
        |    unsigned kind = item.kind();
        |
        |    switch (kind)
        |    {
EOT

    for my $s (@sortedStructs) {

        my $structName = $s->{name};

        next if $s->{generic};
        next if $s->{standalone};
        next unless $structName =~ /^Brig$name/;

        $structName =~ s/^Brig//;
        my $enumName = $s->{enum};

        print cpp(<<"EOT");
            |       case $enumName:
            |       {
            |           $structName it = item;
            |
EOT

        for my $it (fieldsInclParents($structs->{$s->{rawbrig}})) {
            my ($brigAcc, $f) = @$it;

            next if $f->{phantomof};
            next if $f->{name} =~ /^(byteCount|kind|base)$/;
            next if $f->{wtype} !~ $filter;

            my $fieldType = $f->{type};

            if ($fieldType =~ /^Brig/ && $fieldType !~ /^BrigUInt64$/) {
                $fieldType =~ s/^(.*?)[0-9]+_t$/$1/;
            } else {
                $fieldType = "fld_" . ucfirst($f->{name});
            }

            if ($f->{size} && $f->{size} > 1) {
                print  "           for (unsigned i = 0; i < $f->{size}; i++) {\n";
                printf "               validate_%s(item, it.brig()->%s[i], \"%s\", \"%s\");\n", $fieldType, $brigAcc, $structName, $f->{name};
                print  "           }\n"
            } else {
                printf "           validate_%s(item, it.brig()->%s, \"%s\", \"%s\");\n", $fieldType, $brigAcc, $structName, $f->{name};
            }
        }

        print cpp(<<"EOT");
            |       }
            |       break;
            |
EOT

    }

    print cpp(<<"EOT");
        |    default:
        |        return false; // not found
        |
        |    } // switch
        |
        |    return true; // found and validated
        |}
EOT

}

sub makeBrigValidator {
    printf $textLicense;

    makeValidatorFunc("Directive");
    makeValidatorFunc("Inst");
    makeValidatorFunc("Operand");
};

################################################################################
################################################################################
################################################################################
# Generation of code to enumerate/read/write/print instruction properties
# Generated code is a part of Validator and TestGen components

my %brigInst;
my %brigProps;

sub getPropName {
    return "PROP_" . uc(shift());
}

sub registerInst {
    my ($inst, $enum) = @_;

    die "Brig instruction redefinition" if (%brigInst && $brigInst{$inst});

    $brigInst{$inst} = {'id' => $enum, 'props' => ()};
}

sub registerProp {
    my ($inst, $prop, $type, $acc) = @_;

    push @{$brigInst{$inst}{'props'}}, $prop;

    if ($brigProps{$prop}) {
        my ($t, $a) = @{$brigProps{$prop}};
        die "Instruction '$inst': property '$prop' type mismatch: defined as '$type' and '$t'" if $t ne $type;
        die "Instruction '$inst': property '$prop' struct mismatch: defined in '$acc' and '$a'" if $a ne $acc;
        return;
    }
    $brigProps{$prop} = [$type, $acc];
}

sub registerSubItemProps {

    my ($inst, $name, $type) = @_;

    for my $s (@sortedStructs) {

        next if $s->{generic};
        next unless $s->{name} =~ /^$type/;

        for my $f (@{$s->{fields}}) {
            next if $f->{name} =~ /^allBits$/;

            die "unexpected array" if $f->{size};
            registerProp($inst, $f->{name}, $f->{type}, $name . "()." . $f->{name} . '()');
        }
    }
}

sub registerInstProps {

    for my $s (@sortedStructs) {

        next if $s->{generic};
        next if $s->{standalone};
        next unless $s->{name} =~ /^BrigInst/;

        my $inst = $s->{name};
        my $enum = $s->{enum};

        registerInst($inst, $enum);

        for my $it (fieldsInclParents($s)) {
            my ($brigAcc, $f) = @$it;
            next if $f->{name} =~ /^(byteCount|kind|operands|reserved|base)$/;

            die "unexpected array" if $f->{size};

            if ($f->{prop}) { # This is a special case: ".prop=..." may be used to resolve conflicts
                registerProp($inst, $f->{prop}, $f->{type}, $f->{name} . '()');
            } elsif ($f->{acc} =~ /^subItem</) {
                registerSubItemProps($inst, $f->{name}, $f->{type});
            } else {
                registerProp($inst, $f->{name}, $f->{type}, $f->{name} . '()');
            }
        }
    }
}

sub makeBrigProps {
    printf $textLicense . "\n";

    registerInstProps();

    print cpp(<<"EOT");
        |enum
        |{
        |    BRIG_PROP_MIN_ID = 0,
        |
        |    // Brig instruction properties
        |
EOT

    for my $prop (sort keys %brigProps) {
        my ($type, $acc) = @{$brigProps{$prop}};
        print "    " . getPropName($prop) . ",";
        print " " x (20 - length($prop));
        print "// type = " . $type . ",";
        print " " x (30 - length($type));
        print " acc = " . $acc . "\n";
    }

    print cpp(<<"EOT");
        |
        |    EXT_PROP_MIN_ID
        |};
EOT


    for my $inst (sort keys %brigInst) {
        my $id = $brigInst{$inst}{'id'};
        print cpp(<<"EOT");
            |
            |//enum ${inst}Props // $id
            |//{
EOT
        for my $prop (@{$brigInst{$inst}{'props'}}) {
            print "//    " . getPropName($prop) . ",\n";
        }

        print cpp(<<"EOT");
            |//};
            |
EOT
    }
}

sub genPropVisitor {
    my ($generator, $visitAll) = @_;

    print cpp(<<"EOT");
        |{
        |    using namespace Brig;
        |    using namespace HSAIL_PROPS;
        |
        |    switch(inst.kind())
        |    {
EOT

    for my $inst (sort keys %brigInst) {
        my $id = $brigInst{$inst}{'id'};
        my $name = $inst;
        $name =~ s/^Brig//;

        print cpp(<<"EOT");
            |        case $id:
            |        {
            |            $name it = inst;
            |
EOT

        if (!$visitAll) {
            print cpp(<<"EOT");
                |            switch(propId)
                |            {
EOT
        }

        for my $prop (@{$brigInst{$inst}{'props'}}) {
            my ($type, $acc) = @{$brigProps{$prop}};
            my $propName     = getPropName($prop);

            $generator->($prop);
        }

        if (!$visitAll) {
            print cpp(<<"EOT");
                |            default:
                |                assert(ignoreErrors);
                |                break;
                |            }
EOT
        }

        print cpp(<<"EOT");
            |        }
            |        break;
            |
EOT

    }

    print cpp(<<"EOT");
        |        default:
        |            assert(false); // Invalid format
        |            break;
        |    }
EOT
}

sub makeBrigPropsFastAcc {
    printf $textLicense . "\n";
    for my $prop (sort keys %brigProps) {
        my ($type, $acc) = @{$brigProps{$prop}};
        my $propGetter = 'get' . ucfirst($prop);

        print "template<class T> static unsigned $propGetter(T inst) { assert(inst); return inst.$acc; }\n";
    }
}

sub genPropGetter {
    my $prop = shift;
    my ($type, $acc) = @{$brigProps{$prop}};
    my $propName     = getPropName($prop);
    print "            case $propName: return it.$acc;\n";
}

sub genPropSetter {
    my $prop = shift;
    my ($type, $acc) = @{$brigProps{$prop}};
    my $propName     = getPropName($prop);
    if ($type eq 'bool') {
        print "            case $propName: it.$acc = (val != 0); break;\n";
    } else {
        print "            case $propName: it.$acc = val; break;\n";
    }
}

sub makeBrigPropsAcc {
    printf $textLicense . "\n";

    print "void setBrigProp(Inst inst, unsigned propId, unsigned val, bool ignoreErrors)\n";
    genPropVisitor(\&genPropSetter, 0);
    print "}\n\n";

    print "unsigned getBrigProp(Inst inst, unsigned propId, bool ignoreErrors, unsigned defaultVal)\n";
    genPropVisitor(\&genPropGetter, 0);
    print "    assert(ignoreErrors);\n    return defaultVal;\n}\n";
}

sub genPropLogger {
    my $prop = shift;
    my ($type, $acc) = @{$brigProps{$prop}};
    my $propName     = getPropName($prop);
    print "            visitProp(inst, $propName, it.$acc);\n";
}

sub makeBrigPropsVisitor {
    printf $textLicense . "\n";

    print "void visitBrigProps(Inst inst)\n";
    genPropVisitor(\&genPropLogger, 1);
    print "}\n\n";
}

sub makeBrigPropsName {
    printf $textLicense . "\n";

    print cpp(<<"EOT");
        |static const char* getBrigPropName(unsigned prop)
        |{
        |    switch(prop)
        |    {
EOT

    for my $prop (sort keys %brigProps) {
        my $propName     = getPropName($prop);
        print "    case $propName: return \"$prop\";\n";
    }

    print cpp(<<"EOT");
        |    default:
        |        assert(false);
        |        return "";
        |    }
        |}
EOT

}

sub makeBrigInstUtils {
    printf $textLicense . "\n";

    print cpp(<<"EOT");
        |Inst appendInst(BrigContainer &container, unsigned instFormat)
        |{
        |    using namespace Brig;
        |
        |    switch(instFormat)
        |    {
EOT

    for my $inst (sort keys %brigInst) {
        my $id = $brigInst{$inst}{'id'};
        my $name = $inst;
        $name =~ s/^Brig//;

        print "    case $id: return container.append<$name>();\n";
    }

    print cpp(<<"EOT");
        |    default:
        |        assert(false);
        |        return Inst();
        |    }
        |}
EOT

}

sub makeLLVMEnums {
    printf $textLicense . "\n";

    for my $en (sort { $a->{name} cmp $b->{name} } values %$enums) {
      my $tdtype = $en->{tdtype} // "i32";
      my $tddef = $en->{tddef};
      my $tdname = $en->{tdname} // $en->{name};
      print "def $tdname : ";
      if (defined($tddef)) {
        print "OperandWithDefaultOps<$tdtype, (ops ($tdtype $tddef))> {\n";
      } else {
        print "Operand<$tdtype> {\n";
      }
      print "  let PrintMethod = \"print$tdname\";\n";
      my @names = map { $_->{name} } @{$en->{entries}};
      next unless @names;
      my $cprefix = @names[0];
      $cprefix =~ s/^(.*_).*/$1/;
      for my $n (@names) {
        chop $cprefix while
            (substr($n,0,length($cprefix)) ne $cprefix
            or substr($n,length($cprefix)) !~ /^[a-z_]/i);
      }
      for my $n (@names) {
        my $nn = substr($n,length($cprefix));
        print "  int $nn = ",gvalue($n),";\n";
      }
      print "}\n\n";
    }
}

sub makeLLVMPrinters {
    for my $en (sort { $a->{name} cmp $b->{name} } values %$enums) {
      next unless $en->{print};
      my $tdname = $en->{tdname} // $en->{name};
      print "void HSAILInstPrinter::print$tdname";
      print "(const MCInst *MI, unsigned OpNo, raw_ostream &O) {\n";
      print "  switch(MI->getOperand(OpNo).getImm()) {\n";
      for my $i (@{$en->{entries}}) {
        next if $i->{skip};
        my $text;
        if (exists $i->{print}) { $text = $i->{print} ne "" ? "\"$i->{print}\"" : "" }
        elsif (exists $i->{mnemo}) { $text = $i->{mnemo} ne "" ? "\"_$i->{mnemo}\"" : ""; }
        if ($text eq "") { next; }
        print "    case ",$i->{name},": O << $text; break;\n";
      }
      print "  }\n";
      print "}\n\n";
    }
}


################################################################################
################################################################################
################################################################################

sub makeHSAILBrigInitializers {
    printf $textLicense;
    for my $s (@sortedStructs) {
        next if $s->{nowrap};
        next if $s->{generic};
    }
};

sub makePrint {
    printf $textLicense;
    print @_;
}

sub makePreprocess {
    open I, "<".shift;
    while(<I>) {
        if (s/^\@//) {
            eval $_; die $@ if $@;
        } else {
            print;
        }
    }
    close I;
}

my %outFileList;

sub make {
    my ($fn,$sub,$mode) = (shift,shift,">");
    if ($fn =~ s/^[<>|]+//) { $mode = $&; }
    $fn = "$outdir/$fn";
    my $tfn = "$fn.tmp";
    $outFileList{$fn} = $tfn;
    open STDOUT, $mode, $tfn or die "Could not open $mode $fn";
    $sub->(@_);
    close STDOUT;
}


make "HSAILInitBrig_gen.hpp", \&makeHSAILInitBrig;

generateBrigUtilities;
for my $u (keys %$utilities) {
    make "HSAIL${\$u}_gen.hpp", \&makePrint, $utilities->{$u};
}

make "HSAILItems_gen.hpp", \&makeWrappers;
make "HSAILItemImpls_gen.hpp", \&makePrint, $wrapperImpls;
make "HSAILVisitItems_gen.hpp", \&makeDispatchByItem;
make ">>HSAILVisitItems_gen.hpp", \&makeEnumFlds;
make "HSAILBrigStaticChecks_gen.hpp", \&makeStaticChecks;
make "HSAILBrigValidation_gen.hpp", \&makeBrigValidator;
make "HSAILBrigProps_gen.hpp", \&makeBrigProps;
make "HSAILBrigPropsAcc_gen.hpp", \&makeBrigPropsAcc;
make "HSAILBrigPropsFastAcc_gen.hpp", \&makeBrigPropsFastAcc;
make "HSAILBrigPropsVisitor_gen.hpp", \&makeBrigPropsVisitor;
make "HSAILBrigPropsName_gen.hpp", \&makeBrigPropsName;
make "HSAILBrigInstUtils_gen.hpp", \&makeBrigInstUtils;
make "HSAILEnums.td", \&makeLLVMEnums;
make "HSAILOperandPrinters.inc", \&makeLLVMPrinters;

for my $s (values %scanner) {
    my $text;
    for my $tt (sort keys %$s) {
        my $v = $s->{$tt};
        if (ref $v) {
            $v = "switch(ctx) {\n" .
                 join("", map { "\tcase $_: $v->{$_}\n" } sort keys %$v) .
                 "\tdefault: return EEmpty; }";

        }
        $text .= sprintf "    %-20s  { %-40s }\n", $tt, $v;
    }
    $s = $text;
}

make "HSAILScannerRules_gen.re2c", \&makePreprocess, "$indir/HSAILScannerRules.re2c";

sub runTool {
    my ($tool,$args,$out) = @_;
    $outFileList{$out} = "$out.tmp";
    my $cl = "$tool $args >$out.tmp";
    print STDERR "$cl\n";
    system($cl)==0 or die "running $tool failed";
}

runTool("$^X -I \"@INC[0]\" $indir/HDLProcessor.pl -target=validator", "<$indir/HSAILBrigInstr.hdl", "$outdir/HSAILInstValidation_gen.hpp")
    unless $nohdl;
runTool($re2c_path, "-i --no-generation-date $outdir/HSAILScannerRules_gen.re2c.tmp", "$outdir/HSAILScannerRules_gen_re2c.hpp")
    unless $nore2c;

for my $s (values %$structs) {
    if ($s->{children}) { $s->{children} = [ sort keys %{$s->{children}} ] }
}

make "HSAILPropAccessors_gen.hpp", \&makePropAccessors;

make "gvalues_dump.pl", \&makePrint, Data::Dumper->Dump([$gvalues], ["gvalues"]);
make "enums_dump.pl", \&makePrint, Data::Dumper->Dump([$enums], ["enums"]);
make "structs_dump.pl", \&makePrint, Data::Dumper->Dump([$structs], ["structs"]);
make "typedefs_dump.pl", \&makePrint, Data::Dumper->Dump([$typedefs],["typedefs"]);

$/ = undef;
for my $fn (keys %outFileList) {
    my $tfn = $outFileList{$fn};
    my $data;
    my $tdata;
    if (open F, "<:raw", $fn) { $data = <F>; close F; } # else { print STDERR "failed to open\n"; }
    if (defined $data and open F, "<:raw", $tfn) {
        $tdata = <F>; close F;
        if ($data eq $tdata) {
            print STDERR "$fn is up to date\n";
            unlink $tfn;
            next;
        }
    }
    print STDERR "updating $fn\n";
    unlink $fn;
    rename $tfn, $fn;
}

if ($touch_path) {
    open F, ">$touch_path" or die "Failed to touch $touch_path";
    close F;
}
