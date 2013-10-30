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
use Getopt::Long;

my $dk_root;
my $re2c_path;
my $touch_path;
die unless GetOptions("re2c=s" => \$re2c_path, "dk=s" => \$dk_root, "touch=s" => \$touch_path);
$dk_root //= $ENV{DK_ROOT};
if (defined $dk_root) { $re2c_path //= "$dk_root/re2c/re2c"; }
$re2c_path //= "re2c";
my $indir = $ARGV[0];
my $outdir = $ARGV[1];
$indir && $outdir or die "Usage: generate.pl <input directory> <output directory>";
mkdir $outdir;
my $unionMode = undef;

my $struct = undef;
my $enum = undef;

my $structs = +{};
my $typedefs = +{};
my $enums = +{};
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
while(pos($_) < length($_)) {
	if (m/\G\s+/gc) {
	} elsif (m/\G\}\s*(\w*)\s*;/gc) {
		if ($struct) {
			if ($unionMode) {
				$unionMode = undef; $struct->{trailingUnionName} = $1;
			} else {
				$struct = $entity = undef;
			}
		} elsif ($enum) {
			$enum = $entity = undef;
		} else {
			die;
		}
		} elsif ($struct && !$unionMode && /\Gunion\s*\{/gc) {
			$unionMode = 1;
		} elsif ($struct && /\G(?<type>\w+)\s+(?<name>\w+)(?:\s*\[(?<size>\d+)\])?(?:\:\s*(?<width>\d+))?;/gc) {
		$entity = +{%+,%preprops}; %preprops=();
		if ($unionMode) { $entity->{trailingUnion} = 1; }
		if ($phantomof) {
			$entity->{phantomof} = $phantomof;
			$phantomof = undef;
		}
		push @{$struct->{fields}}, $entity;
	} elsif ($enum && /\G(?<name>\w+)\s*(?:=\s*(?<val>[^,\n}\/]+))?\s*,?/gc) {
		$entity = +{%+,%preprops};
		%preprops=();
		push @{$enum->{entries}}, $entity;
	}
	elsif (!$struct && !$enum && /\Gtypedef\s+(?<type>\w+)\s+(?<name>\w+)\s*;/gc) {
		$typedefs->{$2} = $entity = +{%+,%preprops};
		%preprops=();
	}
	elsif (!$struct && !$enum && /\Gstruct\s+(?:ALIGN\((\d+)\)\s*)?(\w+)\s*\{/gc) {
		$structs->{$2} = $struct = $entity = +{%preprops};
		%preprops=();
		my $name = $2;
		$struct->{name} = $name;
		$struct->{align} = $1;
	}
	elsif (!$struct && !$enum && /\Genum\s+(?<name>\w+)\s*\{/gc) {
		$enums->{$1} = $enum = $entity = +{%+,%preprops};
		%preprops=();
	}
	elsif(m{\G(///[^\n]*+)}gc) {
		push @{$preprops{comments}}, $&;
	}
	elsif(m{\G//\.(\w++)(?:\=(\"(?:[^"\\]++|\\.)*+\")|\=(?:\$(\w+(?:\$\w)*))?\{([^\n]++)|\=([^\{\$\"]\S*)|(?!\=))}gc) {
#		print STDERR "$& $1:$2:$3:$4:$5:$6:$7\n";
		$entity->{$1}
		= defined($2) ? eval($2)
		: defined($4) ? do {
			local $@;
			local $_;
			my ($attrKey, $vars, $code) = ($1, $3,$4);
			my @vars = split /\$/, $vars;
			$entity->{"$attrKey#deps"} = [@vars];
			chomp $code;
			my $subcode = 'sub { my ($x,$o) = @_; ';
			for my $var (@vars) {
				$subcode .= "my \$$var=\$x->{$var}; ";
			}
			$subcode .= $code;
#			print STDERR "$vars :: $code :: $subcode\n";
			my $x=eval $subcode;
			die "$subcode\n$@" if $@;
			$x
		}
		: defined($5) ? $5
		: "true";
	}
	elsif (m{\G//\^\^}gc) {
		$phantomof = $entity;
		while($phantomof->{phantomof}) {
			$phantomof = $phantomof->{phantomof};
		}
	}
	elsif (m{\G//(?!\.)([^\n]*)}gc) {
#		push @{$entity->{comments}}, $1;
	}
	elsif (m{\G/\*(.*?)\*/}gsc) {
		# do nothing #push @{$entity->{comments}}, $1;
	}
	else {
		my $pos = pos($_);
		my $text = substr($_, 0, $pos, "");
		my $ln = 1;
		my $lpos = 0;
		while($text =~ /\G[^\n]*\n/gc) { $ln++; $lpos = pos($text); }
		my $col = $pos - $lpos + 1;
		die "Parse error at line $ln, col $col : $_";
	}
};

my $textIncludeItems = "#include \"HSAILItems.h\"\n";
my $textBeginNamespace = "namespace HSAIL_ASM {\n\n";
my $textEndNamespace = "\n} // namespace HSAIL_ASM\n";
my $textLicense = '';
open F, "<$0";
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
	$s->{enum} //= "BRIG".Name2MACRO($s->{wname});
	next if $s->{isroot};
	if (!$s->{parent}) {
		$sname =~ /^(Brig[A-Z][a-z]+)/ or die;
		$s->{parent} = $1;
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
		next if $s->{generic};
		printf "void ".$s->{wname}."::initBrig() {\n";
		for my $f (@{$s->{fields}}) {
			next if $f->{trailingUnion};
			next if $f->{phantomof};
			my $fname = $f->{name};
			my $ftype = $f->{type};
			if ($structs->{$f->{type}}) {
				print "  $f->{wname}().initBrig();\n";
				next;
			}

			my $rhs;
			$rhs //= "sizeof(Brig::".$s->{name}.")" 
							if ($fname eq "size");
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
		$attrValue="\"$attrValue\"" if $proto=~/^(?:const\s+)?char\s*\*/;
		my $attrCode = "return $attrValue";
		my $scanner = $options{scanner} || $options{token};
		my $token = $entry->{$options{tokenpfx}."token"} || $options{token};
		if ($scanner && $attrValue ne '""') {
			if ($token) {
				my $tokenText = $attrValue;
				# HACK: modifier token ids have an underscore as prefix.
				# This underscore is stripped from token id and added to token text.
				if ($token=~s/^_//) { $tokenText =~ s/^"/"_/; }
				$scanner{$scanner} .= sprintf "    %-20s  { %-40s %-30s }\n",
					$tokenText, "m_brigId = Brig::$entryName;", "return m_token = $token;";
			} else {
				$scanner{$scanner} .= sprintf "    %-20s  { %-40s }\n",
					$attrValue, "return Brig::$entryName;";

			}
		}
		if (defined($attrCode) && $attrCode ne $defaultCode) {
			$$text .= sprintf "    case %-30s : %s;\n", $entryName, $attrCode;
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
		for my $attrKey (keys %{$enums->{$en}}) {
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
	my $cc = $_[0]->{comments};
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
		my %pfields = map { ($_->{name},1) } @{$parent->{fields}};
		my $pwname  = $s->{isroot} ? "ItemBase" : $parent->{wname};

		printComments($s);

		print "class $swname : public $pwname {\n";

		if ($s->{children}) {
			print "    // children: ",join(",",keys %{$s->{children}}),"\n";
		}

		print "public:\n";

		print "\n\ttypedef $swname Kind;\n" if ($s->{isroot} && !$s->{standalone});

		print "\n\t/// accessors\n";
		my $findex = -1;
		for my $f (@{$s->{fields}}) {
			++$findex;
			next if $f->{skip};
			my ($fname,$ftype,$helper,$wname,$wtype) = @{$f}{qw(name type acc wname wtype)};
			if($pfields{$fname}) {
				next if $s->{isroot};
				my $pf = $parent->{fields}->[$findex];
				if ($pf->{name} ne $fname or $pf->{type} ne $ftype) {
					die "Parent mismatch: $sname $findex=$ftype $fname $parent->{name} $findex = $pf->{type} $pf->{name}"
				}
				if ($pf->{wname} eq $wname and $pf->{wtype} eq $wtype) {
					next;
				} else {
					push @{$f->{comments}}, "// overridden, was $pf->{wtype} $pf->{wname}"
				}
			}
			my $args = "()";
			my $fldvalue = $fname;
			if ($f->{phantomof}) {
				$fldvalue = $f->{phantomof}->{name};
			}
			if ($f->{trailingUnion}) {
				if ($s->{trailingUnionName}) {
					$fldvalue = $s->{trailingUnionName}.".".$fldvalue;
				}
			}
			if ($f->{size}) {
				$args = "(int index)";
				$fldvalue = $fldvalue."[index]";
			}
			my $constness = "";
			printComments $f, "\t";

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
		}


		print "\n\n\t/// constructors\n";
		print "\t$swname()                           : $pwname() { } \n";
		print "\t$swname(MySection* s, Offset o)     : $pwname(s, o) { } \n";
		my @children = $s->{children} ? grep { !$_->{generic} } values %{$s->{children}} : ($s);
		if (!$s->{standalone}) {
			print "\t$swname(BrigContainer* c, Offset o) : $pwname(&(c->section<Kind>()), o) { } \n";
		}

		if (!$s->{isroot}) {
			print "\n\t/// assignment\n";
			print "\tstatic bool isAssignable(const Kind& rhs) {\n\t\treturn ",
				join("\n\t\t    || ", (map { "rhs.brig()->kind == Brig::".$_->{enum} } @children ))
				,";\n\t}\n";
			print "\t$swname(const Kind& rhs) { assignItem(*this,rhs); } \n";
		} else {
			print "\n\t/// assignment\n\tstatic bool isAssignable(const $swname& rhs) { return true; } \n" unless ($s->{standalone});
		}

		my $swkind = $s->{isroot} ? $swname : "Kind";
		if (!$s->{standalone}) {
			print "\t$swname& operator=(const $swkind& rhs) { assignItem(*this,rhs); return *this; }\n";
		} else {
			print "\t$swname& operator=(const $swkind& rhs) { reset(rhs); return *this; }\n";
		}

		print "\n\t/// raw brig access\n";
		print "\ttypedef Brig::$sname BrigStruct;\n";
		print "\t      BrigStruct* brig()       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }\n";
		print "\tconst BrigStruct* brig() const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }\n";

		if ($s->{isroot} && !$s->{standalone}) {
			print "\n\t/// root utilities\n";
			print "\tOffset  brigSize() const { return brig()->size; }\n";
			print "\t$swname next() const { return $swname(section(), brigOffset() + brigSize()); }\n";
		}

		if (!$s->{generic}) {
			print "\n\t/// final utilities\n";
			print "\tstatic const char *kindName() { return \"$s->{wname}\"; }\n";
			print "\tvoid initBrig(); \n";
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
		print "\tswitch(item.brig()->kind) {\n";
		for my $c (sort { $a->{enum} cmp $b->{enum} } values %{$s->{children}}) {
			next if $c->{generic};
			print "\tcase $c->{enum}: return vis($c->{wname}(item));\n";
		}
		print "\tdefault: assert(false); break;\n\t}\n";
		print "\treturn RetType();\n}\n\n";
	}
}

sub makeEnumFlds {
	my $pfx = "";
	for my $s (@sortedStructs) {
		next if $s->{nowrap} or $s->{generic};
		print "template <typename Visitor> void enumerateFields_gen($s->{wname} obj, $pfx Visitor & vis) {\n";
		for my $f (@{$s->{fields}}) {
			next if $f->{skip} || $f->{novisit};
			die if $f->{wspecialgeneric};
			next if $f->{name} eq "size" or $f->{name} eq "kind";
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
make "HSAILBrigStaticChecks_gen.hpp", \&makePrint, "";
make "HSAILScannerRules_gen.re2c", \&makePreprocess, "$indir/HSAILScannerRules.re2c";

sub runTool {
	my ($tool,$args,$out) = @_;
	$outFileList{$out} = "$out.tmp";
	my $cl = "$tool $args >$out.tmp";
	print STDERR "$cl\n";
	system($cl)==0 or die "running $tool failed";
}

runTool("$^X $indir/HidelProcessor.pl -target=validator", "<$indir/HSAILBrigInstr.hdl", "$outdir/HSAILInstValidation_gen.hpp");
runTool($re2c_path, "-i --no-generation-date $outdir/HSAILScannerRules_gen.re2c.tmp", "$outdir/HSAILScannerRules_gen_re2c.hpp");

for my $s (values %$structs) {
	if ($s->{children}) { $s->{children} = [ keys %{$s->{children}} ] }
}

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
