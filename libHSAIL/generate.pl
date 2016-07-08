# University of Illinois/NCSA
# Open Source License
#
# Copyright (c) 2013-2015, Advanced Micro Devices, Inc.
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

################################################################################
################################################################################
################################################################################
################################################################################
#
# LIST OF ATTRIBUTES CURRENTLY USED:
# 
# typedefs:
#       name:       typedef name                    (GENERATED AUTOMATICALLY)
#       type:       base type                       (GENERATED AUTOMATICALLY)
#       wtype:      wrapper type
#       defValue:   default value
# 
# enums:
#       name:       enum name                       (GENERATED AUTOMATICALLY)
#       entries:    list of enum constants          (GENERATED AUTOMATICALLY)
#       cplen:      length of c++ name (for LLVM)   (GENERATED AUTOMATICALLY)
#
# enum.entry:
#       name:       constant name                   (GENERATED AUTOMATICALLY)
#       mnemo:      HSAIL name
#       val:        value of the constant in text format (may refer other constants, e.g. C1 + C2
#
# structs:
#       name:       struct name                     (GENERATED AUTOMATICALLY)
#       parent:     parent name                     (if not defined, autoderived by stripping BRIG struct name)
#       rawbrig:    mapping to brig structure
#       wname:      C++ wrapper name                (if not defined, autoderived from BRIG struct name)
#       enum:       BRIG kind                       (if not defined, autoderived from BRIG struct name)
#       isroot:     true if struct has no parent
#       nowrap:     need no wrapper
#       generic:    generic type = has children     (Code, Inst, Directive, Operand, DirectiveExecutable)
#       standalone: helper struct                   (does not belong to Brig type heirarchy (Inst/Directive/Operand))
#       fields:     list of struct fields           (GENERATED AUTOMATICALLY)
#
# struct.field:
#       name:       field name                      (GENERATED AUTOMATICALLY)
#       type:       field type                      (GENERATED AUTOMATICALLY)
#       size:       array size                      (for arrays only)
#       wname:      wrapper name
#       wtype:      wrapper type
#       enum:       enum name
#       acc:        accessor
#       defValue:   default value
#       phantomof:  phantom fileds like "bool ftz"
#
################################################################################
################################################################################
################################################################################
################################################################################
# 
# STEPS IN PROCESSING BRIG DEFINITIONS AND METAINFORMATION
#
# step 1: parse and record brig definitions
# step 2: parse and record metainformation 
# step 3: dump rusults if required (see $genextra)
# step 4: extract 'license' text
# step 5: create proxy structs for bit fields
# step 6: for each struct, set 'wname', 'enum' and 'parent' props if not 
#         already defined. Also set 'generic' property if proxy has children
# step 7: compute values of enum properties which are specified by Perl code
#           for each enum E:
#             for each key K which maps to a reference to a subroutine R
#                compute all props K depends on
#                for each entry I in enum E
#                   local $_ = $I{'name'};
#                   $I{$K} = R(%I); 
# step 8: for each enum, compute 'cplen' prop which is max length of prefix w/o 
#         digits common for all enum constants
# step 9: compute default field props unless they are specified explicitly
# step 10: sort structs which require wrappers so that parents precede children
# 
################################################################################
################################################################################
################################################################################
################################################################################

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
my $genextra;

die unless GetOptions("genextra!" => \$genextra, "nore2c!" => \$nore2c, "nohdl!" => \$nohdl, "re2c=s" => \$re2c_path, "dk=s" => \$dk_root, "touch=s" => \$touch_path);

$dk_root //= $ENV{DK_ROOT};
if (defined $dk_root) { $re2c_path //= "$dk_root/re2c/re2c"; }
$re2c_path //= "re2c";
my $indir = $ARGV[0];
my $outdir = $ARGV[1];
$indir && $outdir or die "Usage: generate.pl <input directory> <output directory>";
mkdir $outdir;

################################################################################
# GLOBALS

my $struct = undef;             # struct which is being parsed (refers structs)
my $enum = undef;               # enum which is being parsed (refers enums)

my $typedefs = +{};             # brig typedefs
my $enums = +{};                # brig enums
my $structs = +{};              # brig structs
my @sortedStructs;              # brig structs which require wrappers (sorted from roots to leaves)

my $gvalues = +{};              # a mapping of enum constants to their values (used to evaluate their actual values in case of cross-refs, e.g. X = Y) 
my $prevenum = undef;           # name of previous enum element in the current enum. Used to compute constant values when they are specified implicitly, e.g. enum e { A, B, C };
my %preprops = ();

my $wrapperImpls = "";
my %scanner;
my $entity;                     # a reference to the hash describing an entity being parsed
my $utilities = +{};
my $phantomof = undef;

################################################################################
# CONSTANTS

my $BRIG_FILE_NAME      = 'Brig.h';
my $META_FILE_NAME      = 'BrigMeta.info';
my $BRIG_STRUCT_PREFIX  = 'Brig';
my $BRIG_ENUM_PREFIX    = 'BRIG_';
my $BITMASK_FIELD_NAME  = 'allBits';
my $BITVAL_REF          = 'BitValRef';
my $ENUMVAL_REF         = 'EnumValRef';
my $VAL_REF             = 'ValRef';
my $VAL_REF_ACC         = 'valRef';         # FIXME: bad name
my $SUBITEM             = 'subItem';
my $BRIG_INST           = 'BrigInst';
my $BRIG_INST_BASE      = 'BrigInstBase';

my $BRIG_ACC            = 'brig()';
my $INIT_BRIG           = 'initBrig';
my $INIT_BRIG_BASE      = 'initBrigBase';

sub proxy2kind
{
    my ($wname) = @_;

    return $BRIG_ENUM_PREFIX . "KIND" . Name2MACRO($wname);
}

################################################################################
# HELPERS

sub Name2MACRO {                ### BrigInstMem --> BRIG_INST_MEM
    my $t = $_[0];
    $t=~s/[A-Z]/_$&/g;
    return uc($t);
}

sub M2N {                       ### INST_MEM --> InstMem
    return MACRO2Name('_' . $_[0]);
}

sub MACRO2Name {                ### _INST_MEM --> InstMem
    my $t = $_[0];
    $t=~s/_([^_])([^_]*)/$1.lc($2)/ge;
    return $t;
}

sub gvalue($) {                                                     ### compute value of a enum constant
  my $val = $gvalues->{$_[0]};
  if ($val =~ /^[0-9]+$/ or $val =~ /^0x[0-9a-f]+$/i) {             ### constant value is specified inline, e.g. CNST = 1
    return $val;
  } else {
    return eval($val);                                              ### constant value is specified via other constants, e.g. CNST = CNST1 + 2
  }
}

sub parseError {
    my ($fname, $reason) = @_;
    $reason //= '';

    my $pos = pos($_);
    my $text = substr($_, 0, $pos, "");
    my $ln = 1;
    my $lpos = 0;
    while($text =~ /\G[^\n]*\n/gc) { $ln++; $lpos = pos($text); }
    my $col = $pos - $lpos + 1;
    die "$fname parse error at line $ln, col $col : $reason \n$_";
}

sub brigParseError { parseError($BRIG_FILE_NAME, @_); }
sub metaParseError { parseError($META_FILE_NAME, @_); }

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 1 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# Parse and record brig definitions
#
# This does not pretend to be a full-featured C parser. It only parses a subset of C
# declarations used in the BRIG header.
#

do {
    open F,"<$indir/$BRIG_FILE_NAME" or die "Cannot open $BRIG_FILE_NAME";
    local $/ = undef;
    $_ = <F> . "\n";
    close F;
};
#use re 'debug';

while(pos($_) < length($_)) {
    
    if (m/\G\s+/gc) {                                                                   ### skip whitespace
    }

    elsif (m{\G/\*(.*?)\*/}gsc) {                                                       ### skip /* ... */
    }
    
    elsif (m/\G\/\/[^\n]*?\n/gc) {                                                      ### skip C++ comments
    }
    
    elsif (m/\G#ifdef\s*__cplusplus.+?#endif\W/gcs) {                                   ### skip "#ifdef __cplusplus ... #endif"
    }

    elsif (m/\G#\w+[^\n]*/gc) {                                                         ### skip preprocessor directives
    }
    
    elsif (m/\G\}\s*(\w*)\s*;/gc) {                                                     ### end of struct/enum
        if ($struct) {
            my $name = $struct->{name};
            $struct = $entity = undef;
        } elsif ($enum) {
            $enum = $entity = undef;
        } else {
            brigParseError();
        }
    }
                                                                                        ### struct field

    elsif ($struct && /\G(?<type>\w+)\s+(?<name>\w+)(?:\s*\[(?<size>\d+)\])?(?:\:\s*(?<width>\d+))?;/gc) {
        $entity = +{%+,%preprops}; %preprops=();
        if ($phantomof) {
            $entity->{phantomof} = $phantomof;
            $phantomof = undef;
        }
        push @{$struct->{fields}}, $entity;
    }
    
    elsif ($enum && /\G(?<name>\w+)\s*(?:=\s*(?<val>[^,\n}\/]+))?\s*,?/gc) {            ### enum element
        
        $entity = +{%+,%preprops};
        %preprops=();
        push @{$enum->{entries}}, $entity;

        my $val = $entity->{val};
        $val =~ s/([0-9]+)u\b/$1/g;                                 # remove all 'u' suffices after constants

        if ($val !~ /^[0-9]+$/ and $val !~ /^0x[0-9a-f]+$/i) {      # if element value is not a numeric constant,
            $val =~ s/(\b[a-z_][a-z_0-9]+\b)/gvalue(\"$1\")/ig;     # wrap all identifiers with 'gvalue' for further evaluation
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
    
    elsif (!$struct && !$enum && /\Gtypedef\s+(?<type>\w+)\s+(?<name>\w+)\s*;/gc) {     ### typedef T1 T2
        $typedefs->{$2} = $entity = +{%+,%preprops};
        %preprops=();
    }
    
    elsif (!$struct && !$enum && /\Gtypedef\s+(?<type>\w+)\s*?\*\s*?(?<name>\w+)\s*;/gc) { ### typedef T1* T2
        $typedefs->{$2} = $entity = +{%+,%preprops};
        # FIXME: this type is not currently supported, should be ignored
        %preprops=();
    }
    
    elsif (!$struct && !$enum && /\Gstruct\s+(\w+)\s*\{/gc) {                           ### first line of a struct
        $structs->{$1} = $struct = $entity = +{%preprops};
        %preprops=();
        my $name = $1;
        $struct->{name} = $struct->{rawbrig} = $name;
    }
    
    elsif (!$struct && !$enum && /\Genum\s+(?<name>\w+)\s*\{/gc) {                      ### first line of a enum
        $enums->{$1} = $enum = $entity = +{%+,%preprops};
        $prevenum = undef;
        %preprops=();
    }
    
    elsif (!$struct && !$enum && /\Genum\s+\s*\{/gc) {                                  ### first line of a noname enum
        $enums->{'_noname_'} = $enum = $entity = +{%+,%preprops};
        $prevenum = undef;
        %preprops=();

        # FIXME: properties for noname enums are hardcoded as they cannot be specified in meta information

        $enums->{'_noname_'}->{'nodump'} = 1;
        $enums->{'_noname_'}->{'nollvm'} = 1;
    }

    else {
        brigParseError();
    }
};

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 2 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# Parse and record meta-information
#

do {
    open F,"<$indir/$META_FILE_NAME" or die "Cannot open $META_FILE_NAME";
    local $/ = undef;
    $_ = <F> . "\n";
    close F;
};

sub delType
{
    my ($name) = @_;

    metaParseError("unknown type '$name'")  unless ($enums->{$name} || $structs->{$name} || $typedefs->{$name});

    delete $enums->{$name};
    delete $structs->{$name};
    delete $typedefs->{$name};
}

sub makeAlias
{
    my ($name, $parent) = @_;

    metaParseError("unknown parent '$parent'") unless $structs->{$parent};
    metaParseError("redefinition of '$name'")  if     $structs->{$name};

    my %alias =
    (
        name    => $name,
        parent  => $parent,
        rawbrig => $structs->{$parent}->{rawbrig},
    );

    $structs->{$name} = \%alias;
}

sub setProp
{
    my ($name, $prop, $val) = @_;

    ($prop, $val) = split('=', $prop) if ($prop =~ /=/);
    $prop = "mnemo_$prop" if $prop =~ /^ (token | scanner | context) $/x;
    $val //= 'true';

    $enums->{$name}{$prop}    = $val if $enums->{$name};
    $structs->{$name}{$prop}  = $val if $structs->{$name};
    $typedefs->{$name}{$prop} = $val if $typedefs->{$name};
}

sub setCurrentEntity
{
    my ($name) = @_;

    $entity = undef;
    $entity = $enums->{$name}       if $enums->{$name};
    $entity = $structs->{$name}     if $structs->{$name};
    $entity = $typedefs->{$name}    if $typedefs->{$name};
}

sub purify
{
    my ($name) = @_;

                                    # FIXME: optimize for HSAIL 1.1 by analyzing type name
    $name =~ s/BRIG_[^_]+?_//;

    return $name;
}

sub BrigStruct
{
    my ($name) = @_;

    return $structs->{$BRIG_STRUCT_PREFIX . $name}->{rawbrig};
}

# Perl code in metadata
#
# Syntax:
#   prop = <... perl code ...>
# 
# Perl code may use properties prop1, prop2, ... 
# 
# This is translated to the following code:
# 
#   sub { 
#       my ($x,$o) = @_;
#
#       my $prop1 = $x->{$prop1};
#       my $prop2 = $x->{$prop2};
#       ...
#       my $propN = $x->{$propN};
#                                   ### see 'calcAttrs' for initialization of '$_' 
#       $_        = purify($_);     ### strip name of a prefix common for all elements (and make lowercase for enums)
#
#       ... perl code ...
#   }
#
sub genPendingProp
{
    my ($prop, $code) = @_;

    die unless $entity;

    my %vars = ();                                           ### create list of properties this code depends on
    while($code =~ /\$([A-Za-z]\w*\b)/gc) { $vars{$1} = 1; } ### NB: filter out duplicates
    my @vars = keys %vars;

    my $arg;
    if ($entity->{'fields'}) {      # struct
        $arg = 'purify($_)';
    }
    else {                          # enum
        $arg = 'lc(purify($_))';
    }
                                                            ### for code in the form "(key1 ? val1, key2 ? val2, ...)"
    if ($code =~ /^\(/) {                                   ### transform it to a hash-based mapping
        $code =~ s/\?/=>/g;                                 ###    (key1 ? val1, key2 ? val2, * ? dflt) --> (key1 => val1, key2 => val2, '*' => dflt)
        $code =~ s/\*/'*'/g;
        $code = '$_ = ' . $arg . '; my %switch_ = ' . $code . '; exists($switch_{$_}) ? $switch_{$_} : exists($switch_{\'*\'}) ? $switch_{\'*\'} : undef();';
    }
    else {
        $code = ' $_ =' . $arg . ';' . $code;
    }

    local $_;
    local $@;                                       ### pending exception

    $entity->{$prop . "#deps"} = [@vars];           ### record list of properties this code depends on

    my $subcode = 'sub { my ($x, $o) = @_; ';       ### generate perl code which computes property value

    for my $var (@vars) {
        $subcode .= "my \$$var = \$x->{$var}; ";
    }
    $subcode .= $code . ' }';

    #print STDERR "GENERATING '$subcode'\n";

    $entity->{$prop} = eval $subcode;               ### compile code and return a reference to it (used in calcAttrs)
    die "$subcode\n$@" if $@;                       ### if 'eval' failed, the reason can be found in $@
}

sub genPendingProto
{
    my ($code, $incfile) = @_;

    die unless $entity;

    push @{$entity->{'hcode'}}, $code;
}

sub genPendingImpl
{
    my ($code, $incfile) = @_;

    die unless $entity;

    push @{$entity->{'implcode'}}, $code;
}

sub genPendingSwitch
{
    my ($code, $incfile) = @_;

    die unless $entity;
                                                        # Parse switch template in the following syntax:
                                                        #   <function prototype> { switch(<arg>)  { case <val>: return <key>; default: <dflt>; } }
                                                        # for example:
                                                        #   bool isArrayType(unsigned type) { switch(type)  { case $_: return $array; default: return false;          } }
    if ($code =~ /  ^                       \s*
                    (?<proto> \S[^{]*?)     \s*
                    {                       \s*
                    switch                  \s*
                    \(                      \s*
                    (?<arg> \S[^{]*?)       \s*
                    \)                      \s*
                    {                       \s*
                    case                    \s*
                    \$ (?<val> \w+\b)       \s*
                    :                       \s*
                    return                  \s*
                    \$ (?<key> \w+\b)       \s*
                    ;                       \s*
                    default                 \s*
                    :                       \s*
                    (?<default> \S[^}]*?)   \s*
                    ;                       \s*
                    }                       \s*
                    }                       \s*
                    $
                 /x) {
    
        my $proto   = $+{proto};
        my $arg     = $+{arg};
        my $key     = $+{key};
        my $val     = $+{val};
        my $default = $+{default};

        #print STDERR "SWITCH: \n";
        #print STDERR "         proto  : '$proto'\n";
        #print STDERR "         arg    : '$arg'\n";
        #print STDERR "         key    : '$key'\n";
        #print STDERR "         val    : '$val'\n";
        #print STDERR "         default: '$default'\n";

        if ($key eq '_') {
            ($key, $val) = ($val, $key);
            $entity->{$key . '_reverse'}    = 'true';
        }

        if ($key eq '_') {
            metaParseError('switch cannot map $_ to itself');
        }

        $entity->{$key . '_sw2_'}      = 'true';    # FIXME: labelled to avoid autogenerated 'mnemo' functions when one is defined in meta.info
        $entity->{$key . '_switch'}    = 'true';
        $entity->{$key . '_proto'}     = $proto;
        $entity->{$key . '_arg'}       = $arg;
        $entity->{$key . '_default'}   = $default;

        $entity->{$key . '_incfile'}   = $incfile     if $incfile;

    }
    else {
        metaParseError("invalid switch description");
    }
}

sub parseTrailingProps
{
    local ($_) = @_;

    #print STDERR "TRAILING PROPS: $_\n";

    my @props = ();

    return @props if /^\s+$/;

    while(pos($_) < length($_)) {
    
        if (m/      \G \s*                          # WORD = '...'
                    (\w+) \s* 
                    = \s* 
                    \' ([^\"]*) \' \s*
             /gcx) {
             push @props, "$1=$2";
        }
        elsif (m/   \G \s*                          # WORD = TEXT
                    (\w+) \s* 
                    = \s* 
                    (\S+) \s*
                /gcx) {
             push @props, "$1=$2";
        }
        elsif (m/   \G \s*                          # WORD
                    (\w+) \b \s* 
                /gcx) {
             push @props, $1;
        }
        else {
            metaParseError("invalid syntax of trailing options");
        }
    }
    return @props;
}

my %pending;

sub startPending
{
    my ($kind, $prop, $val) = @_;
    
    completePending();

    $val =~ s/\s+$//;
    $val =~ s/^\s+//;

    $pending{'kind'} = $kind;
    $pending{'prop'} = $prop;
    $pending{'val'}  = $val;
}

sub appendPending
{
    my ($val) = @_;
    
    metaParseError("trailing line without a header") unless $pending{'kind'};

    $pending{'val'}  .= "\n" . $val;
}

sub completePending
{
    if ($pending{'kind'}) {
        
        #print STDERR "ADDED PROPERTY '", $pending{'kind'}, "'-'", $pending{'prop'}, "'-'", $pending{'val'}, "  '\n";
        
        if ($pending{'kind'} eq 'defProp') {
            genPendingProp($pending{'prop'}, $pending{'val'});
        }
        elsif ($pending{'kind'} eq 'switch') {
            genPendingSwitch($pending{'val'}, $pending{'prop'});
        }
        elsif ($pending{'kind'} eq 'proto') {
            genPendingProto($pending{'val'}, $pending{'prop'});
        }
        elsif ($pending{'kind'} eq 'impl') {
            genPendingImpl($pending{'val'}, $pending{'prop'});
        }
        else {
            metaParseError('unknown code generator ' . $pending{'kind'});
        }

        undef %pending;
    }
}

$entity = undef;
while(pos($_) < length($_)) {
    
    if (m/\G[ \t]*\r?\n/gc) {                                                       ### skip empty lines
    }

    elsif (m/\G[ \t]*#.*?\n/gc) {                                                  ### skip empty lines with comments
    }
    
                                                                                        ### ignore  NAME                    // comment
                                                                                        ### type    NAME          props     // comment
                                                                                        ### bitmask NAME          type bits // comment
                                                                                        ### proxy   NAME : PARENT props     // comment
                                                                                        ### proxy   NAME          props     // comment
                                                                                        ### alias   NAME : PARENT props     // comment
    elsif (m/ \G 
              (?<kind> \w+) [ \t]+ 
              (?<name> \w+) \b
              (?: 
                    [ \t]*? : [ \t]*? (?<parent> \w+ ) [ \t]*?
                | 
                    [ \t]*? 
              )
              (?: 
                    [ \t]* (?<list> \w+ .*? )
                | 
                    [ \t]*
              )
              (?: 
                    [ \t]* \# [^\n]*?
                | 
                    [ \t]*
              )
              \r?\n
            /gcx) {

        my $kind = $+{kind};
        my $name = $BRIG_STRUCT_PREFIX . $+{name};
        my $parent = exists($+{parent})? ($BRIG_STRUCT_PREFIX . $+{parent}) : undef;

        my $propList = exists($+{list})? $+{list} : "";
        $propList =~ s/\#.*$//;

        my @props = parseTrailingProps($propList);

        completePending();
        setCurrentEntity($name);
        
        #print STDERR "TYPE: $kind $name $propList\n";

        if ($kind eq 'type') {
            metaParseError("'type' does not accept a parent") if ($parent);
            setProp($name, 'nowrap') if $structs->{$name};
        }
        elsif ($kind eq 'bitmask') {    #FIXME: add validation of props and optimize all 'bitmask' code
            metaParseError("'bitmask' does not accept a parent")   if $parent;
            metaParseError("missing 'bitmask' properties")         unless $propList;
            metaParseError("unknown 'bitmask' typedef '$name'")    unless $typedefs->{$name};

            $propList =~ s/\s+/,/g;
            $typedefs->{$name}{'bitmask'} = $propList;
            @props = ();
        }
        elsif ($kind eq 'proxy') {

            metaParseError("unknown parent '$parent'") if ($parent && !$structs->{$parent});

            if ($parent) {
                setProp($name, 'parent', $parent);
                setProp($name, 'isroot') if $structs->{$parent}{'nowrap'};      # FIXME: make 'isRoot' derived from 'standalone'?
            }
            else {
                setProp($name, 'isroot');                                       # FIXME: make 'isRoot' derived from 'standalone'?
                setProp($name, 'standalone');
            }
        }
        elsif ($kind eq 'alias') {
            metaParseError("missing parent name")      unless $parent;
            metaParseError("unknown parent '$parent'") unless $structs->{$parent};

            makeAlias($name, $parent);

            setProp($name, 'isroot') if $structs->{$parent}{'nowrap'};          # FIXME: make 'isRoot' derived from 'standalone'?
        }
        elsif ($kind eq 'ignore') {
            metaParseError("'ignore' does not accept a parent") if ($parent);
            metaParseError("'ignore' does not accept a list of properties") if (@props);
            delType($name);
        }
        else {
            metaParseError('unknown metainfo kind');
        }

        for my $prop (@props) { 
            setProp($name, $prop);
        }
    }

                                                                                        ###     PROP = VAL  // comment
    elsif (m/ \G 
              [ \t]+
              (?<prop> \w+) [ \t]* 
              = [ \t]*
              (?<val> .*)
              \r?\n
            /gcx) {

        my $prop = $+{prop};
        my $val  = $+{val};

        $val =~ s/#.*$//;

        startPending('defProp', $prop, $val);
    }

                                                                                        ###     :GEN(FILENAME) CODE // comment
                                                                                        ###     :GEN           CODE // comment
    elsif (m/ \G 
              [ \t]+ 
              : [ \t]*
              (?<kind> \w+) [ \t]*
              (?: 
                    \(              [ \t]*
                    (?<fname> \w+ ) [ \t]*
                    \)              [ \t]*
                | 
                    [ \t]*
              )
              (?<val> .*)
              \r?\n
            /gcx) {

        my $kind  = $+{kind};
        my $val   = $+{val};
        my $fname = $+{fname};

        $val =~ s/#.*$//;

        startPending($kind, $fname, $val);
    }

                                                                                        ###     TRAILING LINE // comment
    elsif (m/ \G 
              [ \t]+ 
              (?<val> .*)
              \r?\n
            /gcx) {

        my $val  = $+{val};

        $val =~ s/#.*$//;
        
        appendPending($val);
    }

    else {
        metaParseError('unknown syntax'); # FIXME: define all names such as this separately
    }
};

completePending();

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 3 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

### dump raw attributes specified in brig.h

sub make;

if ($genextra) {
    make "enums0_dump.pl",      \&makePrint, Data::Dumper->Dump([$enums],   ["enums"]);
    make "structs0_dump.pl",    \&makePrint, Data::Dumper->Dump([$structs], ["structs"]);
    make "typedefs0_dump.pl",   \&makePrint, Data::Dumper->Dump([$typedefs],["typedefs"]);
}

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 4 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# Extract 'license' text from the beginning of this file
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

###############################################################################
#### POSTPROCESSING ###########################################################
###############################################################################

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 5 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# Create proxy structs for bit fields
#

for my $s (values %$structs) {                              ### for each struct

    for my $f (@{$s->{fields}}) {

        my $ftype = $f->{type};
        
        if ($typedefs->{$ftype}) {                          ### 
            my $prop = $typedefs->{$ftype}->{'bitmask'};

            if ($prop) {
                my @bits = split(',', $prop);
                my $proxyName = shift @bits;
                my $brigName  = $BRIG_STRUCT_PREFIX . $proxyName;

                $f->{type}    = $brigName;
            }
        }
    }
}

for my $tname (keys %$typedefs) {
    
    #print STDERR "PROCESSING $tname...\n";

    my $type = $typedefs->{$tname};
    my $prop = $type->{'bitmask'};

    if ($prop) {

        my @bits = split(',', $prop);
        my $proxyName = shift @bits;
        my $brigName  = $BRIG_STRUCT_PREFIX . $proxyName;

        die "Invalid bitmask property, missing field names: $prop" unless @bits;

        my %proxy = 
        (
            isroot      => 'true',
            standalone  => 'true',
            name        => $brigName,
            rawbrig     => $brigName,
            acc         => "$SUBITEM<$proxyName>",
            wtype       => $proxyName,
            fields      => 
                            [ 
                                {
                                    defValue    => '0',
                                    name        => $BITMASK_FIELD_NAME,
                                    type        => $tname,
                                    wtype       => "$VAL_REF<$type->{type}>",
                                    acc         => $VAL_REF_ACC,
                                },
                            ]
        );

        my $i = 0;
        for my $bit (@bits) {
            my %phantom = 
            (
                'name'      => $bit,
                'phantomof' => $proxy{'fields'}[0],
                'type'      => 'bool',
                'wtype'     => "$BITVAL_REF<$i>"
            );
            $proxy{'fields'}[++$i] = \%phantom;
        }

        die "Cannot create bitmask proxy for $tname: $brigName already exist" if $structs->{$brigName};
        $structs->{$brigName} = \%proxy;
    }

}

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 6 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# For each struct, set 'wname', 'enum', and 'parent' props if not already defined
# Also set 'generic' property if proxy has children
#

my @wstructs = grep { !$_->{nowrap} } values %$structs;     ### List of structs which need proxies

for my $s (@wstructs) {                                     ### for each struct, set 'wname', 'enum' and 'parent' props if not already defined

    my $sname = $s->{name};

    #print STDERR "PROCESSING $sname...\n";

    if (!$s->{wname}) {                                     ### set 'wname' prop if not defined
        ($s->{wname} = $sname) =~ s/^$BRIG_STRUCT_PREFIX//;
    }

    $s->{enum} //= proxy2kind($s->{wname});                 ### set 'enum' prop if not defined

    next if $s->{isroot};
                                                            ### set 'parent' prop  if not defined
                                                            ###     BrigInstXXX      -> BrigInstBase
                                                            ###     BrigDirectiveXXX -> BrigDirective
    if (!$s->{parent}) {                                    ###     BrigOperandXXX   -> BrigOperand
        $sname =~ /^($BRIG_STRUCT_PREFIX[A-Z][a-z]+)/ or die "$sname";     
        if ($1 eq $BRIG_INST) {                             ### FIXME: remove hardcoded values
            $s->{parent} = $BRIG_INST_BASE;
        } else {
            $s->{parent} = $1;
        }
    }

    die "$sname: bad parent: $s->{parent}" unless exists $structs->{$s->{parent}};

    $structs->{$s->{parent}}{generic} = 1;                  ### 'generic' = has children
}

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 7 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# compute values of properties which are specified by Perl code
#
#   for each enum E:
#     for each key K which maps to a reference to a subroutine R
#        compute all props K depends on
#        for each entry I in enum E
#           local $_ = $I{'name'};
#           $I{$K} = R(%I); 
#

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
        my $name = $entry->{name};
        local $_ = $name;
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

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 8 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# For each enum, compute 'cplen' prop which is max length of prefix w/o digits common for all enum constants
#

for my $en (values %$enums) {
  my @names = map { $_->{name} } @{$en->{entries}};
  next unless @names;
  my $cprefix = $names[0];
  $cprefix =~ s/^(.*_).*/$1/;
  for my $n (@names) {
    chop $cprefix while
        (substr($n,0,length($cprefix)) ne $cprefix
        or substr($n,length($cprefix)) !~ /^[a-z_]/i);
  }
  $en->{cplen} = length($cprefix);
}

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 9 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# Compute default field props unless they are specified explicitly
#

for my $s (@wstructs) {                                         ### Iterate over list of structs which need proxies
    my $p = $s;
    my %seen;

    while(!$p->{isroot}) {                                      ### Record all children
        die "$p->{name}: loop detected" if $seen{$p}++;
        my $pp = $structs->{$p->{parent}};
        die "$s->{name}: bad parent of $p->{name}: $p->{parent}" unless $pp;
        $p = $pp;
        $p->{children}->{$s->{name}} = $s;
    }

    for my $f (@{$s->{fields}}) {
                                                                ### FIXME: define these rules outside of this code
        $f->{skip}     //= 1   if $f->{name} =~ /^reserved/;    ### set 'skip' property for 'reserved' fields         # FIXME: hardcoded 'reserved'
        $f->{defValue} //= '0' if $f->{name} =~ /^reserved/;    ### set 'defValue' property for 'reserved' fields     # FIXME: hardcoded 'reserved'

        if (!$f->{wname}) {                                     ### set default 'wname' if not specified explicitly
            $f->{wname} = $f->{name};
        }

        my $ftype = $f->{type};
        my $e;
        
        if (!$f->{enum} and $ftype=~/^(.*?)[0-9]+_t$/ and ($e = $enums->{$1})) {    ### add 'enum' prop for fields with enum type like BrigWidth8_t #FIXME: add a fn to 'port' section
            $f->{enum} = $e->{name};
            $f->{defValue} //= $e->{defValue} if exists $e->{defValue};
        }
        
        if ($typedefs->{$ftype}) {                              ### if necessary, propagate 'wtype' and 'defValue' props from typedef
            my $tt = $typedefs->{$ftype};
            $f->{wtype}    //= $tt->{wtype} if exists $tt->{wtype};
            $f->{wtype}    //= "$ENUMVAL_REF<$f->{enum},$tt->{type}>" if exists $f->{enum};
            $f->{wtype}    //= "$VAL_REF<$tt->{type}>";
            $f->{defValue} //= $tt->{defValue} if exists $tt->{defValue};
        }
        
        if ($structs->{$ftype}) {                              ### if necessary, propagate 'wtype' and 'acc' props from struct type
            my $tt = $structs->{$ftype};
            $f->{wtype}  //= $tt->{wtype} if exists $tt->{wtype};
            $f->{acc}    //= $tt->{acc}   if exists $tt->{acc};
        }
        
        $f->{wtype} //= "$VAL_REF<$f->{type}>";

        if (!$f->{acc}) {                                       ### set field 'acc' prop
            $f->{acc} = $f->{wtype};
            $f->{acc} =~ s/^./lc($&)/e;
        }
        # HACK                                                  ### FIXME: why this is a hack?
        $f->{acc} =~ s/($VAL_REF_ACC)<.*?>/$1/;
    }
}

### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@ STEP 10 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#
# Sort structs which require wrappers so that parents precede children
#

for (my @q = sort { $b->{wname} cmp $a->{wname} } grep { $_->{isroot} } @wstructs; @q; ) {
    my $s = pop @q;
    push @q, sort { $b->{wname} cmp $a->{wname} } grep { $_->{parent} eq $s->{name} } @wstructs;
    push @sortedStructs, $s;
}


#### END OF POSTPROCESSING ####
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
### @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

sub makeHSAILInitBrig {

    printf $textLicense;

    for my $s (@sortedStructs) {

        printf "void ".$s->{wname}."::$INIT_BRIG() {\n";
        if (!$s->{generic} && !$s->{standalone}) {
          print "    $INIT_BRIG_BASE(sizeof(" , $s->{rawbrig}, "), " , $s->{enum}, ");\n";      ### init base
        }

        if (!$s->{isroot}) {
          my $pwname = $structs->{$s->{parent}}->{wname};                                       ### init parent
          print "    ${pwname}::${INIT_BRIG}();\n";
        }

        for my $f (@{$s->{fields}}) {                                                           ### init fields if required

            next if $f->{phantomof};
            next if $f->{name} eq "base";       # FIXME: hardcoded?

            my $fname = $f->{name};
            my $ftype = $f->{type};

            if ($structs->{$f->{type}}) {                                                       ### this field has a wrapper
                print cpp(<<"EOT");
                    |    $f->{wname}().$INIT_BRIG();
EOT
                next;
            }

            my $rhs;
            $rhs //= $f->{defValue}     if (exists $f->{defValue});

            if ($rhs ne undef) {
                my $lhs = "$BRIG_ACC->$fname";
                if ($f->{size}) {                                                               ### init array elements
                    print cpp(<<"EOT");
                        |    for (int i=0;i<$f->{size};i++) {
                        |        ${lhs}[i] = $rhs;
                        |    }
EOT
                } else {                                                                        ### init scalar
                    print cpp(<<"EOT");
                        |    $lhs = $rhs;
EOT
                }
            }
        }
        printf "}\n\n";
    };
};

sub makeSwitch($$%) {
    my (
        $attrKey,           # attribute name - its value is used as switch key
        $ename,             # enum name
        %options            # values for overriding defaults:
                            #     'fn'      => 
                            #     'proto'   => 
                            #     'arg'     => 
                            #     'context' => 
                            #     'default' => 
                            #     'incfile' => 
                            #     'scanner' => 
                            #     'token'   => 
                            #     'tokenpfx'=> 
                            #     'reverse' => 
                            #     'pre'     => prologue
                            #     'post'    => epilogue
        ) = @_;
    my $fn = $options{fn} // ($ename =~ /^(?:Brig)?(.)(.*)/ and lc($1).$2."2str");              ### name of function which is being generated   # FIXME hardcoded 'Brig'?
    my $proto = $options{proto} // "const char* $fn(unsigned arg)";                             ### function prototype
    my $arg = $options{arg} // "arg";                                                           ### switch argument
    my $context = $options{context};
    my $defaultCode = $options{default} // "return NULL";
    my $text = \$utilities->{$options{incfile} // "BrigUtilities"};         # FIXME hardcoded "BrigUtilities"

    $wrapperImpls .= "$proto;\n" unless $options{incfile};

    $$text .= "$proto {\n";
    $$text .= "  $options{pre}\n" if $options{pre};
    $$text .= "  switch( $arg ) {\n";

    my $e = $enums->{$ename} or die "makeSwitch: bad enum: $ename";

    for my $entry (sort { $a->{name} cmp $b->{name} } @{$e->{entries}}) {

        my $entryName = $entry->{name};
        my $attrValue = $entry->{$attrKey};

        if ($proto =~ /^bool / && $attrValue ne 'true' && $attrValue ne 'false') { $attrValue = $attrValue? 'true' : 'false'; } # FIXME

        next unless defined $attrValue;
        next if $entry->{skip};

        $attrValue="\"$attrValue\"" if $proto=~/^(?:const\s+)?char\s*\*/;

        my $attrCode = "return $attrValue";

        my $scanner = $options{scanner} || $options{token};
        my $token = $entry->{$options{tokenpfx}."token"} || $options{token};

        if ($scanner && $attrValue ne '""') {

            my $tokenText = $attrValue;
            my $block;

            if ($token) {

                # HACK: modifier token ids have an underscore as prefix.                        # FIXME: investigate this hack
                # This underscore is stripped from token id and added to token text.

                if ($token=~s/^_//) {
                  $tokenText =~ s/^"/"_/; $tokenText .= "/EOMOD"; $scanner = "_mods_";
                } else {
                  $tokenText .= ($scanner eq "Instructions") ? "/EOMOD" : "/EOKW";
                }

                $block = "brigId = $entryName; return $token;";

                if ($context) {
                    $scanner{$scanner}->{$tokenText}->{$context} = $block;
                } else {
                    $scanner{$scanner}->{$tokenText} = $block;
                }

            } else {
                $block = "return $entryName;";
                $scanner{$scanner}->{$tokenText} = $block;
            }
        }

        if (defined($attrCode) && $attrCode ne $defaultCode) {

            if ($options{reverse}) {
#               print STDERR "$attrCode $entryName\n";
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

sub makeBrigEnum2str {
    printf $textLicense . "\n";

    for my $en (sort keys %$enums) {
        next if $enums->{$en}->{nodump};

        my $prop = getBrigPropByType($en);

        if ($prop)
        {
            my $propName = getPropName($prop);


                                                                                            # FIXME: hardcoded names
                                                                                            #  - enum2str, extEnum2str
                                                                                            #  - HSAIL_ASM, HSAIL_PROPS
            print cpp(<<"EOT");
                |const string enum2str( $en arg ) const
                |{
                |    string res = HSAIL_ASM::enum2str(arg);
                |    if (res.empty()) res = extEnum2str(HSAIL_PROPS::$propName, arg);
                |    if (res.empty()) return "?";
                |    return res;
                |}
                |
EOT
        }
        else
        {
            print cpp(<<"EOT");
                |const string enum2str( $en arg ) const
                |{
                |    string res = HSAIL_ASM::enum2str(arg);
                |    if (res.empty()) return "?";
                |    return res;
                |}
                |
EOT
        }
    }
}

sub generateBrigUtilities {
    for my $en (sort keys %$enums) {
        for my $attrKey (sort keys %{$enums->{$en}}) {
            if ($attrKey eq "mnemo" && !$enums->{$en}{"mnemo_sw2_"}) { #FIXME
                makeMnemo $en, $attrKey;
            }
            elsif ($attrKey=~s/_switch$//) {
                makeMnemo $en, $attrKey;
            }
        }
    }
    for my $en (sort keys %$enums) {
        next if $enums->{$en}->{nodump};
        makeSwitch "name", $en, proto=>"const char* enum2str( $en arg )", default=>"return \"\"";     # FIXME: hardcoded  enum2str
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

    for my $tname (keys %$typedefs) {

        my $type = $typedefs->{$tname};
        my $prop = $type->{'bitmask'};

        if ($prop) {

            my ($pname) = split(',', $prop);
            $pname = $BRIG_STRUCT_PREFIX . $pname;

            print cpp(<<"EOT");
                |struct $pname {
                |    $tname $BITMASK_FIELD_NAME;
                |};
                |
EOT
        }
    }

    for my $s (@sortedStructs) {
        next if $s->{nowrap};

        my $sname   = $s->{name};
        my $swname  = $s->{wname};
        my $parent  = $s->{isroot} ? undef : $structs->{$s->{parent}};
        my $pwname  = $s->{isroot} ? "ItemBase" : $parent->{wname};         # FIXME: hardcoded ItemBase

        printComments($s->{comments});

        print cpp(<<"EOT");
            |class $swname : public $pwname {
EOT

        if ($s->{children}) {
            print "    // children: ",join(",",sort keys %{$s->{children}}),"\n";
        }

        print cpp(<<"EOT");
            |public:
EOT

        if ($s->{isroot} && !$s->{standalone}) {
            print cpp(<<"EOT");
                |
                |    typedef $swname Kind;
                |
                |    enum { SECTION = $s->{section} };
EOT
        }

        print cpp(<<"EOT");
            |
            |    /// accessors
EOT

        my $findex = -1;
        for my $f (@{$s->{fields}}) {
            ++$findex;
            next if $f->{skip};
            my ($fname,$ftype,$helper,$wname,$wtype) = @{$f}{qw(name type acc wname wtype)};
            next if $fname eq "base";                                                             # FIXME hardcoded 'base'
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
            printComments $f->{comments}, "    ";

            printf("    %-50s %s;\n", $wtype, "$wname$args$constness");
            $wrapperImpls .= "inline $wtype ${\$swname}::$wname$args$constness { return $helper(&$BRIG_ACC->$fldvalue); }\n";

        }

        if (defined $s->{hcode}) {
            my $t = "    ".join("\n    ", @{$s->{hcode}})."\n";
            $t =~ s/KLASS/$swname/g;
            print $t;
        }
        if (defined $s->{implcode}) {
            my $t = join("\n", @{$s->{implcode}})."\n";
            $t =~ s/KLASS/$swname/g;
            $wrapperImpls .= $t;
        }

        print cpp(<<"EOT");
            |
            |    /// constructors
EOT

        print cpp(<<"EOT");                                                                                 # FIXME: hardcoded 'MySection* s, Offset o'
            |    $swname()                           : $pwname() { }
            |    $swname(MySection* s, Offset o)     : $pwname(s, o) { }
EOT

        my @children = $s->{children} ? sort grep { !$_->{generic} } values %{$s->{children}} : ($s);
        if (!$s->{standalone}) {                                                                            # FIXME: hardcoded 'BrigContainer* c, Offset o', 'sectionById'
            print cpp(<<"EOT");
                |    $swname(BrigContainer* c, Offset o) : $pwname(&c->sectionById(SECTION), o) { }
EOT
        }

        if (!$s->{standalone}) {                                                                            # FIXME: lots of hardcoded values in the following code...
            print cpp(<<"EOT");
                |
                |    /// assignment
                |    static bool isAssignable(const ItemBase& rhs) {
EOT
            print "        return ",
                join("\n            || ", (map { "rhs.kind() == ".$_->{enum} } sort { $a->{enum} cmp $b->{enum} } @children )), ";";

            print cpp(<<"EOT");
                |
                |    }
                |    $swname(const ItemBase& rhs) { assignItem(*this,rhs); }
                |    $swname& operator=(const ItemBase& rhs) { assignItem(*this,rhs); return *this; }
EOT
        } else {
            print cpp(<<"EOT");
                |    $swname(const $swname& rhs) : ItemBase(rhs) { }
                |    $swname& operator=(const $swname& rhs) { reset(rhs); return *this; }
EOT
        }

        print cpp(<<"EOT");
            |
            |    /// raw brig access
            |    typedef $s->{rawbrig} BrigStruct;
            |          BrigStruct* $BRIG_ACC       { return reinterpret_cast<BrigStruct*>      (m_section->getData(m_offset)); }
            |    const BrigStruct* $BRIG_ACC const { return reinterpret_cast<const BrigStruct*>(m_section->getData(m_offset)); }
            |    void $INIT_BRIG();
EOT
        if ($s->{isroot} && !$s->{standalone}) {
    
            print cpp(<<"EOT");
                |
                |    /// root utilities
                |    Offset  brigSize() const { return $BRIG_ACC->byteCount; }
                |    $swname next() const { return $swname(section(), brigOffset() + brigSize()); }
EOT
        }

        if (!$s->{generic}) {

            print cpp(<<"EOT");
                |
                |    /// final utilities
                |    static const char *kindName() { return \"$s->{wname}\"; }
EOT
        }

        print cpp(<<"EOT");
            |};
            |
EOT
    }
};

                                                                                ### generate code which visits instructions, directives and operands by item kind
sub makeDispatchByItem {                                                        ### FIXME: lots of hardcoded values here...
    printf $textLicense;
    for my $s (@sortedStructs) {

        next if $s->{nowrap};
        next unless $s->{generic};                                              ### Visitors are only required for generic types (Code, Inst, Directive, Operand, DirectiveExecutable)

        print cpp(<<"EOT");
            |template <typename RetType, typename Visitor>
            |RetType dispatchByItemKind_gen($s->{wname} item,Visitor& vis) {
            |    switch(item.kind()) {
EOT

        for my $c (sort { $a->{enum} cmp $b->{enum} } values %{$s->{children}}) {
            next if $c->{generic};
            print cpp(<<"EOT");
                |    case $c->{enum}: return vis($c->{wname}(item));
EOT
        }
        print cpp(<<"EOT");
            |    default: assert(false); break;
            |    }
            |    return RetType();
            |}
            |
EOT
    }
}

                                                                               ### generate code which visits every field in each proxy
sub makeFldVisitors {                                                          ### FIXME: lots of hardcoded values here...
    my $pfx = "";
    for my $s (@sortedStructs) {

        next if $s->{nowrap};                                                                                   ### proxies only

        print "template <typename Visitor> void enumerateFields_gen($s->{wname} obj, $pfx Visitor & vis) {\n";

        if (!$s->{isroot}) {
           print "    enumerateFields_gen(", $structs->{$s->{parent}}->{wname}, "(obj), vis);\n";               ### visit parent fields first
        }

        for my $f (@{$s->{fields}}) {

            next if $f->{skip} || $f->{novisit};                                                                ### 

            next if $f->{name} eq "byteCount" or $f->{name} eq "kind" or $f->{name} eq "base";                  ### FIXME set 'novisit' for these 

            my $acc = "obj.$f->{wname}";

            if ($f->{size}) {                                                                                   ### 'size' is set for arrays only
                my $size = $f->{size};
                if ($size <= 1) {                                                                               ### 
                    print "    vis($acc(),\"$f->{name}\");\n";
                } else {
                    print "    for (unsigned i=0;i<$size;i++) {\n    vis($acc(i),\"$f->{name}\", i);\n  }\n";   ### currently not used
                }
            } elsif ($structs->{$f->{type}}) {                                                                  ### field has BRIG-specific type
                print "    enumerateFields($acc(), vis);\n";
            } else {                                                                                            ### field has standard type
                print "    vis($acc(),\"$f->{name}\");\n";
            }
        }
        print "}\n\n";
    }
}
                                                                               ### generate code which checks that there are no gaps between struct fields 
sub makeStaticChecks {                                                         
    printf $textLicense;
    for my $s (@sortedStructs) {
        my $sn = "".$s->{name};
        my @fields = grep { !exists $_->{phantomof} } @{$s->{fields}};                              ### list of fields which are not phantoms
        my $n = @fields;
        for(my $i = 0; $i < $n; ++$i) {
            last if $fields[$i]->{noaligncheck};
            my $fn = $fields[$i]->{name};
            my $err = "\"bad alignment in $sn\"";

            if ($i == 0) {                                                                          ### offsetof(struct, base) == 0
                print "static_assert(offsetof($sn, $fn) == 0, $err);\n";
            }
            if ($i > 1) {                                                                           ### offsetof(struct, fld[i - 1]) + sizeof(((struct*)0)->fld[i-1]) == offsetof(struct,fld[i])
                my $pfn = $fields[$i-1]->{name};
                print "static_assert(offsetof($sn, $pfn)+sizeof((($sn","*)0)->$pfn) == offsetof($sn,$fn), $err);\n";
            }
            if ($i == $n - 1) {                                                                     ### offsetof(struct, fld[i]) + sizeof(((struct*)0)->fld[i]) == sizeof(struct)
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
  return ($s->{isroot} ? () : fieldsInclParents($structs->{$s->{parent}}, 'base.'.$pfx)),        ### FIXME: hardcoded 'base'
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

        $structName =~ s/^$BRIG_STRUCT_PREFIX//;
        my $enumName = $s->{enum};
        my $start    = 1;

        print cpp(<<"EOT");
            |       case $enumName:
            |       {
EOT

        for my $it (fieldsInclParents($structs->{$s->{rawbrig}})) {
            my ($brigAcc, $f) = @$it;

            next if $f->{phantomof};
            next if $f->{name} =~ /^(byteCount|kind|base)$/;
            next if $f->{wtype} !~ $filter;

            if ($start) {           # Avoid emitting unused variables
                $start = 0;
                print cpp(<<"EOT");
                    |           $structName it = item;
                    |
EOT
            }
            
            my $fieldType = $f->{type};

            if ($fieldType =~ /^$BRIG_STRUCT_PREFIX/ && $fieldType !~ /^BrigUInt64$/) {
                $fieldType =~ s/^(.*?)[0-9]+_t$/$1/;
            } else {
                $fieldType = "fld_" . ucfirst($f->{name});
            }

            if ($f->{size} && $f->{size} > 1) {
                print  "           for (unsigned i = 0; i < $f->{size}; i++) {\n";
                printf "               validate_%s(item, it.$BRIG_ACC->%s[i], \"%s\", \"%s\");\n", $fieldType, $brigAcc, $structName, $f->{name};
                print  "           }\n"
            } else {
                printf "           validate_%s(item, it.$BRIG_ACC->%s, \"%s\", \"%s\");\n", $fieldType, $brigAcc, $structName, $f->{name};
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

    $type =~ s/^(.*?)[0-9]+_t$/$1/;

    if ($brigProps{$prop}) {
        my ($t, $a) = @{$brigProps{$prop}};
        die "Instruction '$inst': property '$prop' type mismatch: defined as '$type' and '$t'" if $t ne $type;
        die "Instruction '$inst': property '$prop' struct mismatch: defined in '$acc' and '$a'" if $a ne $acc;
        return;
    }
    $brigProps{$prop} = [$type, $acc];
}

sub getBrigPropByType {
    my ($type) = @_;

    for my $prop (keys %brigProps) {
        my ($ty, $acc) = @{$brigProps{$prop}};
        if ($ty eq $type) { return $prop; }
    }
    return '';
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
        next unless $s->{name} =~ /^$BRIG_INST/;

        my $inst = $s->{name};
        my $enum = $s->{enum};

        registerInst($inst, $enum);

        for my $it (fieldsInclParents($s)) {
            my ($brigAcc, $f) = @$it;
            next if $f->{name} =~ /^(byteCount|kind|operands|reserved|base)$/;

            die "unexpected array" if $f->{size};

            if ($f->{hdlProp}) { # This is a special case: ".hdlProp=..." may be used to resolve conflicts
                registerProp($inst, $f->{hdlProp}, $f->{type}, $f->{name} . '()');
            } elsif ($f->{acc} =~ /^$SUBITEM</) {
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
        |    using namespace HSAIL_PROPS;
        |
        |    switch(inst.kind())
        |    {
EOT

    for my $inst (sort keys %brigInst) {
        my $id = $brigInst{$inst}{'id'};
        my $name = $inst;
        $name =~ s/^$BRIG_STRUCT_PREFIX//;

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
        |    switch(instFormat)
        |    {
EOT

    for my $inst (sort keys %brigInst) {
        my $id = $brigInst{$inst}{'id'};
        my $name = $inst;
        $name =~ s/^$BRIG_STRUCT_PREFIX//;

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
            next unless $root->{name} eq $BRIG_INST; ##
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

################################################################################
################################################################################
################################################################################
### Generation of LLVM-specific code

sub makeLLVMEnums 
{
    printf $textLicense . "\n";

    for my $en (sort { $a->{name} cmp $b->{name} } values %$enums) {

        next if $en->{nollvm};

        my $tdtype = "i32";
        my $tdname = $en->{name};

        print cpp(<<"EOT");
            |def $tdname : Operand<$tdtype> {
            |  let PrintMethod = \"print$tdname\";
EOT

        for my $i (@{$en->{entries}}) {

            my $n = $i->{name};
            my $nn = substr($n, $en->{cplen});

            print "  int $nn = ",gvalue($n),";\n";
        }

        print cpp(<<"EOT");
            |}
            |
EOT
    }
}

################################################################################
################################################################################
################################################################################

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

make "HSAILItems_gen.hpp",              \&makeWrappers;
make "HSAILItemImpls_gen.hpp",          \&makePrint, $wrapperImpls;

make "HSAILVisitItems_gen.hpp",         \&makeDispatchByItem;
make ">>HSAILVisitItems_gen.hpp",       \&makeFldVisitors;

make "HSAILBrigStaticChecks_gen.hpp",   \&makeStaticChecks;
make "HSAILBrigValidation_gen.hpp",     \&makeBrigValidator;
make "HSAILBrigProps_gen.hpp",          \&makeBrigProps;
make "HSAILBrigPropsAcc_gen.hpp",       \&makeBrigPropsAcc;
make "HSAILBrigPropsFastAcc_gen.hpp",   \&makeBrigPropsFastAcc;
make "HSAILBrigPropsVisitor_gen.hpp",   \&makeBrigPropsVisitor;
make "HSAILBrigPropsName_gen.hpp",      \&makeBrigPropsName;
make "HSAILBrigEnum2str_gen.hpp",       \&makeBrigEnum2str;
make "HSAILBrigInstUtils_gen.hpp",      \&makeBrigInstUtils;

make "HSAILEnums.td",                   \&makeLLVMEnums;

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

runTool("$^X -I \"@INC[0]\" $indir/HDLProcessor.pl -target=validator $indir/HSAILDefs.hdl $indir/HSAILCore.hdl", "", "$outdir/HSAILInstValidation_core_gen.hpp")
    unless $nohdl;
runTool("$^X -I \"@INC[0]\" $indir/HDLProcessor.pl -target=validator $indir/HSAILDefs.hdl $indir/HSAILImage.hdl", "", "$outdir/HSAILInstValidation_image_gen.hpp")
    unless $nohdl;
runTool($re2c_path, "-i --no-generation-date $outdir/HSAILScannerRules_gen.re2c.tmp", "$outdir/HSAILScannerRules_gen_re2c.hpp")
    unless $nore2c;

for my $s (values %$structs) {
    if ($s->{children}) { $s->{children} = [ sort keys %{$s->{children}} ] }
}

make "HSAILPropAccessors_gen.hpp", \&makePropAccessors;

### dump raw attributes specified in brig.h + generated attributes

if ($genextra) {
    make "gvalues_dump.pl", \&makePrint, Data::Dumper->Dump([$gvalues], ["gvalues"]);
    make "enums_dump.pl", \&makePrint, Data::Dumper->Dump([$enums], ["enums"]);
    make "structs_dump.pl", \&makePrint, Data::Dumper->Dump([$structs], ["structs"]);
    make "typedefs_dump.pl", \&makePrint, Data::Dumper->Dump([$typedefs],["typedefs"]);
}

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
