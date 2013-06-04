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
use warnings;
use strict;

###############################################################################
###############################################################################
###############################################################################
#### 
#### 1. HIDEL: A LANGUAGE FOR HSAIL INSTRUCTIONS DESCRIPTION
#### 
#### 1.1 PURPOSE
#### 
#### Hidel has been developed for compact and powerful description of properties of
#### HSAIL instructions. This description is an input for HidelProcessor used for
#### instructions analysis and generation of validation components for HSAIL Assembler.
####  
#### 1.2 IDENTIFIERS
#### 
#### Hidel identifiers may include alphanumeric characters, '.' and "_".
#### '.' is useful only for better readability; it is internally replaced with "_".
#### 
#### 1.3 PROPERTIES AND VALUES
#### 
#### Property is an abstract entity which describes some feature of HSAIL instruction.
#### Examples of properties are 'type' and 'operand 0'. Each property has a list of 
#### possible values described by Hidel identifiers.
#### 
#### There are two kinds of properties: brig properties and non-brig properties.
#### 
#### Brig properties correspond to Brig fields; their values may only include
#### identifiers defined by HSAIL standard. These values are specified without 'Brig' 
#### prefix, for example:
#### 
####     BrigProp geom = geom_1d, geom_1db, geom_2d, geom_1da, geom_3d, geom_2da;
#### 
#### Non-brig properties are user-defined; their values may include any
#### user-defined identifiers. For example:
#### 
####     Prop rounding = none, float, int;
####     Prop modifier = none, hi, ftz, fbar;
#### 
#### Values may only be used in context which assumes specific property, so there 
#### is no ambiguity with identical values such as 'none' in the previous example.
#### 
#### Note. Property name may have a suffix (separated with ".") which describes 
#### additional property attribute. See description of attributes below.
#### 
#### 1.4 ABBREVIATIONS
#### 
#### Some properties may include a long list of similar values; round brackets may
#### help by describing generic part only once. For example, previously defined
#### 'geom' property may be redefined as follows:
#### 
####     BrigProp geom = geom_(1d, 1db, 2d, 1da, 3d, 2da);
#### 
#### or in more cryptic manner:
#### 
####     BrigProp geom = geom_((1, 2, 3)d, (1, 2)da, 1db);
#### 
#### 1.5 ALIASES
#### 
#### Aliases is yet another feature for those who like brevity and expression.
#### An alias simply provides a synonym for one value or a list of values.
#### For example:
#### 
####     BrigProp geom = geom_(1d, 1db, 2d, 1da, 3d, 2da);
####     
####     Alias 1d = geom_1d;
####     Alias 2d = geom_2d;
####     Alias 3d = geom_3d;
####     Alias regular = (1, 2, 3)d;
#### 
#### Inline aliases provide an alternative:
#### 
####     BrigProp geom = 
####         1d = geom_1d, 
####         2d = geom_2d, 
####         3d = geom_3d, 
####         geom_(1db, 1da, 2da);
####     
####     Alias regular = (1, 2, 3)d;
#### 
#### Note 1: Alias definition apply to the last defined property.
#### Note 2: Aliases are similar to values in that they may only be used in context 
#### which assumes specific property, so there is no ambiguity with identical values
#### defined for different properties. However, names of properties and aliases 
#### must be different.
#### Note 3: Expansion of bracketed lists is performed before alias expansion.
#### 
#### 1.6 CLONES
#### 
#### Some properties may describe different entities but have the same list of values.
#### For example, an instruction may have both instruction type and source type
#### which are basically the same:
#### 
####     BrigProp type  = b1, b8, b16, ...;
####     BrigProp stype = b1, b8, b16, ...;
#### 
#### This duplication may be avoided by cloning:
#### 
####     BrigProp type  = b1, b8, b16, ...;
####     Clone stype;
#### 
#### Note. Clone definition apply to the last defined property.
#### 
#### 1.7 ATTRIBUTES
#### 
#### Property is described by a set of values. If this set of values
#### has something in common, it may be expressed by an attribute
#### written as the last suffix separated by '.' or '_'.
#### Examples of property values with attributes are:
####
####    reg.generic  # register type = instruction type
####    imm.generic  # immediate type = instruction type
####    reg.stype    # register type = source type
####    imm.stype    # immediate type = source type
#### 
#### Attributes are useful in the following cases:
####    - There is a set of values that differ only in attribute,
####      for example, reg.generic and reg.stype. 
####    - Property values must have identical attributes
####      or no attributes. 
#### 
#### For these cases Hidel has a special construct called
#### attribute:
#### 
####     Attr generic, stype;
#### 
#### This declaration has the following consequences:
#### 
####     1. Hidel will check that all property values have
####        either the same attribute or no attribute at all.
####
####        For example, the following declarations are valid:
####            s2 = (reg, imm).stype;  # attr = stype
####            s3 = func, lab;         # attr = none
####        The following declarations are invalid:
####            s2 = reg.stype, imm.generic;  # different attributes
####            s3 = reg.stype, lab;          # different attributes
#### 
####      2. Hidel will separate attribute from property
####         and generate 2 different checks: one for the
####         set of provided values and the second for the attribute.
#### 
#### Note 1. Attr definitions apply to the last defined property.
#### Note 2. Attributes may be defined for non-brig properties only.
#### 
#### 1.8 REQUIREMENTS
#### 
#### A simple requirement is a list of ASSERTIONS:
#### 
####     Req Name { <assertion 1>; <assertion 2>; ... }
#### 
#### Each assertion describes a property and values it can take. For example:
#### 
####     Req d0.s1.s2.s3      // Description of standard 4-operand instruction
####     {
####         d0 = reg;        // Destination operand must be a register
####         s1 = reg, imm;   // First, second and third source operands
####         s2 = reg, imm;   //     must be registers or immediate values
####         s3 = reg, imm;
####         s4 = null;       // Last operand must be null
####     }
#### 
#### Some properties may depend on values of other properties. This may be 
#### expressed using VARIANTS:
#### 
####     <variant 1>
####     <variant 2>
####     ...
####     <variant N>;
#### 
#### The trailing semicolon is required to label the last alternative.
#### 
#### Each variant is expressed using CONDITIONS and ASSERTIONS:
#### 
####     { <condition 1>; <condition 2>; ... ? <assertion 1>; <assertion 2>; ... }
#### 
#### For example:
#### 
####     { type = (s, u)(32, 64) ? rounding = none;  modifier = none      }
####     { type = f              ? rounding = float; modifier = none, ftz }
####     ;
#### 
#### Requirements may also include references to other (previously defined) requirements,
#### for example:
#### 
####     Req div
####     {
####         type    = (s, u)(32, 64), f;
####         packing = none; 
#### 
####         { type = (s, u)(32, 64) ? rounding = none;  modifier = none      }
####         { type = f              ? rounding = float; modifier = none, ftz }
####         ;
#### 
####         d0.s1.s2; // Refer another requirement
####     }
#### 
#### 1.9 INSTRUCTIONS
#### 
#### Having defined a requirement that describes limitations on instruction properties,
#### the instruction may be specified as follows:
#### 
####     Inst Div(Mod, div) // Instruction 'BrigDiv' has 'BrigInstMod' format and must comply with requirement 'div'
#### 
#### 1.10 COMMENTS
#### 
#### Hidel supports C++ style comments:
#### 
####     // This is a comment
#### 
#### 1.11 GRAMMAR
#### 
####     Definitions ::= { PropDef | AliasDef | CloneDef | ReqDef | InstDef }
####     
####     PropDef     ::= ("Prop" | "BrigProp") PropName "=" ValDef { "," ValDef } ";"
#### 
####     ValDef      ::= NameList | ( AliasName "=" NameGroup )
#### 
####     AliasDef    ::= "Alias" AliasName "=" NameList ";"
####     CloneDef    ::= "Clone" NameList ";"
#### 
####     ReqDef      ::= "Req" ReqName "{" { Assert } "}"
####     Assert      ::= PropChk | Variants | ReqRef
#### 
####     PropChk     ::= PropName "=" NameList ";"
####     Variants    ::= Variant { Variant } ";"
####     Variant     ::= "{" PropChk { PropChk } "?" { Assert } "}"
####     ReqRef      ::= ReqName ";"
#### 
####     InstDef     ::= "Inst" InstName "(" FormatName "," ReqName ")"
#### 
####     NameGroup   ::= Id | "(" NameList ")" | NameGroup "(" NameList ")" | "(" NameList ")" NameGroup
####     NameList    ::= NameGroup { "," NameGroup }
#### 
####     PropName    ::= Id
####     ValName     ::= Id
####     AliasName   ::= Id
####     CloneName   ::= Id
####     ReqName     ::= Id
####     InstName    ::= Id
####     FormatName  ::= Id
#### 
#### 1.12 LIMITATIONS
#### 
####     TBD
#### 
#### 2.1 IMPLEMENTATION
#### 
####     TBD
#### 
###############################################################################
###############################################################################
###############################################################################

my $dump;

my $validateTestGen = 1; # generate validator for self-check

###############################################################################
###############################################################################
###############################################################################
# Command Line Arguments

die "Missing 'target' option" unless (@ARGV == 1);
die "Invalid 'target' value, expected 'validator' or 'testgen'" unless ($ARGV[0] eq "-target=testgen" || $ARGV[0] eq "-target=validator");
my $genValidator = $ARGV[0] eq "-target=validator";
my $className = $genValidator? "InstValidator" : "InstDescBase";

###############################################################################
###############################################################################
###############################################################################

sub make_lexer {
    my $lexer = shift;
    while (@_) {
        my $args = shift;
        $lexer = _tokens( $lexer, @$args );
    }
    return $lexer;
}

sub _tokens {
    my ($input, $label, $name, $pattern, $maketoken) = @_;
    $maketoken ||= sub { [ $_[0] => $_[1] ] };
    my @tokens;
    my $buf = "";    # set to undef when input is exhausted
    my $split = sub { split /($pattern)/ => $_[0] };

    return sub {
        while ( 0 == @tokens && defined $buf ) {
            my $i = $input->();
            if ( ref $i ) {    # input is a token
                my ($sep, $tok) = $split->($buf);
                $tok = $maketoken->( $label, $tok ) if defined $tok;
                push @tokens => grep defined && $_ ne "" => $sep, $tok, $i;
                $buf = "";
                last;
            }
            $buf .= $i if defined $i;    # append new input to buffer
            my @newtoks = $split->($buf);
            while ( @newtoks > 2 || @newtoks && !defined $i ) {

                # buffer contains complete separator plus combined token
                # OR we've reached the end of input
                push @tokens => shift @newtoks;
                push @tokens => $maketoken->( $label, shift @newtoks )
                  if @newtoks;
            }

            # reassemble remaining contents of buffer
            $buf = join "" => @newtoks;
            undef $buf unless defined $i;
            @tokens = grep $_ ne "" => @tokens;
        }
        $_[0] = '' unless defined $_[0];
        return 'peek' eq $_[0] ? $tokens[0] : shift @tokens;
    };
}

###############################################################################
###############################################################################
###############################################################################
# Tokens

my @input_tokens = 
(
    [ 'COMMENT', '',           qr/\/\/.*\Z/, sub { () } ],
    [ 'NAME',    'identifier', qr/\b\w+\b/              ],
    [ 'EQ',      '=',          qr/=/                    ],
    [ 'COMMA',   ',',          qr/,/                    ],
    [ 'TERM',    ';',          qr/;/                    ],
    [ 'CHK',     '?',          qr/\?/                   ],
    [ 'STAR',    '*',          qr/\*/                   ],
    [ 'SLASH',   '/',          qr/\//                   ],
    [ 'LBR',     '{',          qr/{/                    ],
    [ 'RBR',     '}',          qr/}/                    ],
    [ 'LBRR',    '(',          qr/\(/                   ],
    [ 'RBRR',    ')',          qr/\)/                   ],
    [ 'SPACE',   '',           qr/\s*/, sub { () }      ],
    [ 'UNKNOWN', '',           qr/./                    ],
);

my $it = make_charstream(\*STDIN);
my $lexer = make_lexer( $it, @input_tokens );

sub make_charstream {
    my $fh = shift;
    return sub { 
        #return getc($fh);

        my $ch = getc($fh);
        return ($ch && $ch eq '.')? '_' : $ch;
    };
}

sub getTokenName
{
    my $id = shift;

    for my $rec (@input_tokens)
    {
        my ($tokenId, $tokenName) = @$rec;
        return $tokenName if $tokenId eq $id;
    }
    return '';
}

###############################################################################
# Parser Tables

my %hdlProp;               # $hdlProp{$PropName}{$PropVal} = 1;

                           # Brig properties are labelled as follows:
my %hdlPropType;           # $hdlPropType{$PropName} = 'brig';
                           
                           # Property prefix - used to translate HDL names to BRIG names
my %hdlPropPref;           # $hdlPropPref{$PropName} = "...";
                           
my %hdlClone;              # $hdlClone{$name} = $BasePropName;
                               
my %hdlAlias;              # For user-defined alias $AliasName of property $BasePropName 
                           # with values $V1, $V2, etc:
                           #   $hdlAlias{$BasePropName . '@' . $AliasName} = [$V1, $V2, ...]
                           # For generated alias (array alias) of property $BasePropName
                           # with values $V1, $V2, etc and ordered expanded values $E1, $E2, etc:
                           #   $hdlAlias{$BasePropName . '@' . $E1 . '#' . $E2 ... . '#'] = [$V1, $V2, ...]

my %hdlAttr;               # $hdlAttr{$BasePropName . '*' . $AttrName} = 1;
                               
my %hdlInst;               # $hdlInst{InstName} = [$InstFmt, $ReqName];

my @hdlInstList; # FIXME: this is to simplify TestGen validation - to be deleted
                               
my %hdlReq;                # Each requirement is a list of checks:
                           #     $hdlReq{$Req} = [<Check>*];
                           # There are 4 kinds of checks two of which are used together:
                           #     Check  = <Call> | <Prop> | {<Cond>}+ <End>
                           # Each check is represented as an anonimous hash with named keys:
                           #     Call = {'kind' => '!', 'name'  => $name}
                           #     Prop = {'kind' => '=', 'name'  => $name,  'values' => [@values]};
                           #     Cond = {'kind' => '?', 'tests' => $tests, 'asserts' => $asserts};
                           #     End  = {'kind' => ';'};

my %hdlReqOrig;            # Copy of original requirement (%hdlReq is a subject for optimizations).
                           # This copy is created only after optimization of %hdlReq
                           
                           # Arrays are used to store lists of property values.
                           # These data are used for validation  and error reporring.
                           # Because array names are autogenerated, implementation uses 
                           # the following two hashes to ensure that each name is unique.
                           # Arrays are identified by id which is an array alias name (see above).
my %hdlArray;              #     $hdlArray{$ArrayId} = $ArrayName;

my %hdlGeneratedName;      # All autogenerated names are placed into this hash: 
                           #     $hdlGeneratedName{$Name} = 1
                           # It is used to make sure there are no duplicate names.
                           
my $context = '';          # description of current context (used for errors reporting)
my $prevContext = '';      # description of previous context (used for errors reporting)
                           
my $currentProp;           # Last defined property

my $MAX_ARR_NAME_LEN = 64; # Max length of human-readable array names (generated using array values)
                           # Longer names are generated using simpler algorithm 

###############################################################################
# Lexer

sub setContext
{
    $_[0] //= '';
    $prevContext = $context;
    $context = $_[0];
}

sub lexError 
{
    if ($context) 
    {
        print STDERR "Error when $context:\n" ;
    } 
    elsif ($prevContext) 
    {
        print STDERR "Error after $prevContext:\n" ;
    }

    print STDERR shift(), "\n";
    exit;
}
 
sub dumpToken 
{
    my ($label, $value) = @_;
    print "Next token: $label \t $value \n";
}

sub getToken 
{ 
    my ($expected, $optional) = @_;
    
    if (my $token = $lexer->())
    {
        my ($label, $value) = @$token;
        if ($expected) 
        { 
            $label eq $expected or lexError "Invalid token '$value', expected: '$expected'";
            return $value; 
        } 
        else 
        {
            return ($label, $value); 
        }
    }
    else 
    {
        $optional or lexError 'Unexpected EOF';
        return;
    }
}

sub peekToken 
{ 
    if (my $token = $lexer->('peek'))
    {
        my ($label, $value) = @$token;
        return $label;
    }
    return "EOF";
}

sub trySkipToken
{
    my $token;
    if (($token = $lexer->('peek')) && (@$token[0] eq shift)) {
        getToken;
        return 1;
    }
    return 0;
}

sub peekTokens
{
    my $token = peekToken;
    for my $val (@_) {
        return 1 if $token eq $val;
    }
    return 0;
}

sub peekTerminator
{
    return peekTokens('TERM', 'CHK', 'LBR', 'RBR', 'LBRR', 'RBRR')
}

sub skipToken
{
    my ($label, $value) = getToken;

    for my $i (@_) {
        return $i if $i eq $label;
    }

    my @expected = map { "'" . getTokenName($_) . "'" } @_;
    lexError "Invalid token '$value', expected: " . join(", ", @expected);
}

sub expected 
{ 
    if (peekTokens @_) { return }
    skipToken @_;             # Report error
}

###############################################################################
# Properties

sub isBaseProp
{
    my $name = shift;
    return $hdlProp{$name};
}

sub isClone
{
    my $name = shift;
    return $hdlClone{$name};
}

sub isProp
{
    my $name = shift;
    return isBaseProp($name) || isClone($name);
}

sub isPropVal
{
    my ($prop, $val) = @_;
    return isProp($prop) && $hdlProp{getBaseProp($prop)}{$val};
}

sub isBrigProp 
{
    my $prop = shift;
    return isProp($prop) && $hdlPropType{getBaseProp($prop)} && $hdlPropType{getBaseProp($prop)} eq 'brig';
}

sub getBaseProp     # Given a property or clone name, return corresponding true property name
{
    my $prop = shift;

    return $prop            if isBaseProp($prop);
    return $hdlClone{$prop} if isClone($prop);
    
    lexError "getBaseProp: unknown property or clone '$prop'";
}

sub getPropValues
{
    my ($prop) = @_;
    return $hdlProp{getBaseProp($prop)};
}

sub addPropVal
{
    my ($prop, $val) = @_;
    $hdlProp{$prop}{$val} = 1;
}

sub markBrigProp 
{
    my $prop = shift;
    $hdlPropType{getBaseProp($prop)} = 'brig';
}

sub addClone
{
    my ($name, $prop) = @_;
    $hdlClone{$name} = $prop;
}

###############################################################################
# Property Kinds and Values

# FIXME: these are currently static; should we declare pairs (affects, depends)? e.g. should 'type' always be primary?

my %staticPrmProps;
my %staticMetaProps;
my %staticDepProps;

my %instPropKind;
my %instPrimaryProps;
my %instPropVals;

sub dclPrmProp  { my ($prop) = @_; $staticPrmProps{$prop} = 1; }
sub dclMetaProp { my ($prop) = @_; $staticMetaProps{$prop} = 1; }
sub dclDepProp  { my ($prop) = @_; $staticDepProps{$prop} = 1; }

sub isPrmProp  { my ($prop) = @_; return $staticPrmProps{getBaseProp($prop)}; }
sub isMetaProp { my ($prop) = @_; return $staticMetaProps{getBaseProp($prop)}; }
sub isDepProp  { my ($prop) = @_; return $staticDepProps{getBaseProp($prop)}; }

sub addPrimaryProp
{
    my ($inst, $prop) = @_;
    push @{$instPrimaryProps{$inst}}, $prop;
}

sub addPropDesc
{
    my ($inst, $chk, $kind) = @_;
    my $prop = getChkPropName($chk);

    #print STDERR "ADD DESC($inst, $prop, $kind)\n";

    for my $val (expandAliases($prop, getChkPropValues($chk))) {
        $instPropVals{$inst}{$prop}{$val} = 1;
    }

    if (isDepProp($prop) && $kind eq 'PLN')  { $kind = 'DEP'; }
    if (isPrmProp($prop))  { $kind = 'PRM'; }
    if (isMetaProp($prop)) { $kind = 'MTA'; }

    #print STDERR "                      $kind\n";

    if ($instPropKind{$inst}{$prop}) {
        my $prev = $instPropKind{$inst}{$prop};
        return if $kind eq $prev;
        return if $kind eq 'PLN';
        return if $kind eq 'DEP' && ($prev eq 'CND' || $prev eq 'PRM');
        return if $kind eq 'CND' && $prev eq 'PRM';
    } 
    #print STDERR "                      ***ADDED as $kind\n\n";
    addPrimaryProp($inst, $prop) if $kind eq 'PRM';
    $instPropKind{$inst}{$prop} = $kind;
}

sub getPropKindName
{
    my ($inst, $prop) = @_;
    my $kind = $instPropKind{$inst}{$prop};
    return 'Primary'     if ($kind eq 'PRM');
    return 'Conditional' if ($kind eq 'CND');
    return 'Dependent'   if ($kind eq 'DEP');
    return 'Plain'       if ($kind eq 'PLN');
}

sub getProps
{
    my ($inst, $kind) = @_;
    return @{$instPrimaryProps{$inst}} if $kind eq 'PRM' && $instPrimaryProps{$inst};
    return grep { $instPropKind{$inst}{$_} eq $kind } keys %{$instPropKind{$inst}};
}

sub addPrmPropDesc { my ($inst, $chk) = @_; addPropDesc($inst, $chk, 'PRM'); }
sub addCndPropDesc { my ($inst, $chk) = @_; addPropDesc($inst, $chk, 'CND'); }
sub addPlnPropDesc { my ($inst, $chk) = @_; addPropDesc($inst, $chk, 'PLN'); }

sub getPrmProps  { my $inst = shift; return getProps($inst, 'PRM'); }
sub getMetaProps { my $inst = shift; return sort(getProps($inst, 'MTA')); }
sub getCndProps  { my $inst = shift; return sort(getProps($inst, 'CND')); }
sub getDepProps  { my $inst = shift; return sort(getProps($inst, 'DEP')); }
sub getPlnProps  { my $inst = shift; return sort(getProps($inst, 'PLN')); }

sub getPrmPropsNum { my $inst = shift; return scalar(getProps($inst, 'PRM')); }
sub getCndPropsNum { my $inst = shift; return scalar(getProps($inst, 'CND')); }
sub getDepPropsNum { my $inst = shift; return scalar(getProps($inst, 'DEP')); }
sub getPlnPropsNum { my $inst = shift; return scalar(getProps($inst, 'PLN')); }

sub getOrderedPropList # NB: order is important! Primary props must go first!
{
    my $inst = shift;
    return (getPrmProps($inst), getCndProps($inst), getDepProps($inst), getPlnProps($inst));
}

sub getInstPropVals
{
    my ($inst, $prop) = @_;
    return sort keys %{$instPropVals{$inst}{$prop}};
}

###############################################################################
# Attributes

sub isAttr
{
    my ($prop, $attr) = @_;
    return $hdlAttr{getAttrId($prop, $attr)};
}

sub getAttrId
{
    my ($prop, $attr) = @_;
    return getBaseProp($prop) . '*' . $attr; # "prop*attr"
}

sub addAttr
{
    my ($prop, $attr) = @_; 
    $hdlAttr{getAttrId($prop, $attr)} = 1;
}

###############################################################################
# Aliases

sub isAlias
{
    my ($prop, $alias) = @_;
    return $hdlAlias{getAliasId($prop, $alias)};
}

sub getAliasId
{
    my ($prop, $alias) = @_;
    return getBaseProp($prop) . '@' . $alias; # "prop@alias"
}

sub getAliasComponents
{
    my $aliasId = shift;
    return split('@', $aliasId);
}

sub getAliasValues
{
    my ($prop, $alias) = @_;
    return @{$hdlAlias{getAliasId($prop, $alias)}};
}

sub getAliasNames
{
    return sort keys %hdlAlias;
}

sub expandAliasVal      # Given a value or an alias, return a list of actual values
{
    my ($prop, $val) = @_;
    
    if (isPropVal($prop, $val)) {
        return ($val);
    } elsif (isAlias($prop, $val)) {
        return getAliasValues($prop, $val);
    } else {
        lexError "Unknown value (or alias) '$val' of property '$prop'";
    }
}

sub addAlias
{
    my ($prop, $alias, @values) = @_;
    $hdlAlias{getAliasId($prop, $alias)} = [@values];
}

###############################################################################
# Arrays (aka generated aliases)

sub isArray
{
    my ($prop, $val) = @_;
    return $hdlArray{getAliasId($prop, $val)};
}

sub isArrayName
{
    my $name = shift();
    return $name =~ m/#\Z/
}

sub makeArrayName
{
    return join('#', @_) . '#';
}

# FIXME: put all other generated names into 'hdlGeneratedName'

sub genTargetArrayName       # Generate a unique array name
{
    my ($prop, $val) = @_;

            # First, generate human-readable array name by concatenating
            # names of values and aliases in the list, separated with "_"
            # e.g. TYPE_VALUES_B_S_U

    my $name = join('.', getAliasValues($prop, $val));
    $name =~ s/_//g;
    $name =~ s/\./_/g;

    my $res = getTargetValListName($prop, $name);

            # Check that the name is unique and does not violate length limitation.
            # If the check fails, generate a simple numeric name like this: TYPE_VALS_01

    if (defined($hdlGeneratedName{$res}) || length($res) > $MAX_ARR_NAME_LEN)
    {
        my $cnt = 0; 
        while (1)
        {
            $res = getTargetValListName($prop, $cnt++);
            last unless defined($hdlGeneratedName{$res});
        }
        $hdlGeneratedName{$res} = 1;
    }
    
    return $res;
}

sub createTargetArrayName
{
    my ($prop, $alias, @values) = @_;
    
    if (!isArray($prop, $alias)) {
        $hdlArray{getAliasId($prop, $alias)} = [genTargetArrayName($prop, $alias), @values];
    }
    return getTargetArrayName($prop, $alias);
}

sub getTargetArrayName
{
    my ($prop, $val) = @_;
    
    isArray($prop, $val) or lexError "Internal error: undefined array '$val' of property '$prop'";

    my ($name, @values) = @{$hdlArray{getAliasId($prop, $val)}};
    return $name;
}

sub getTargetArrayValues
{
    my ($prop, $val) = @_;

    isArray($prop, $val) or lexError "Internal error: undefined array '$val' of property '$prop'";

    my ($name, @values) = @{$hdlArray{getAliasId($prop, $val)}};
    return @values;
}

###############################################################################
# Checks

sub isChkProp
{ 
    return shift()->{'kind'} eq '=';
}

sub isChkCall
{ 
    return shift()->{'kind'} eq '!';
}

sub isChkCond
{ 
    return shift()->{'kind'} eq '?';
}

sub isChkEnd
{ 
    return shift()->{'kind'} eq ';';
}

sub getChkCallName 
{ 
    return shift()->{'name'};
}

sub getChkPropName 
{ 
    return shift()->{'name'};
}

sub getChkPropPureName # prop name without attribute
{ 
    my $prop = getChkPropName shift;

    if (!isBrigProp($prop)) {
        if ($prop =~ m/^(.*?)\.(.*)$/) { $prop = $1 }
    }
    return $prop;
}

sub getChkPropValues 
{ 
    return @{shift()->{'values'}};
}

sub getChkCondTests
{ 
    return @{shift()->{'tests'}};
}

sub getChkCondAsserts
{ 
    return @{shift()->{'asserts'}};
}

sub makeChkProp
{
    my ($name, @values) = @_;
    return { 
        'kind'   => '=', 
        'name'   => $name, 
        'values' => [@values]
    };
}

sub makeChkCall
{
    my ($name) = @_;
    return { 
        'kind'   => '!', 
        'name'   => $name
    };
}

sub makeChkCond
{
    my ($tests, $asserts) = @_;
    return { 
        'kind'    => '?', 
        'tests'   => $tests,
        'asserts' => $asserts
    };
}

sub makeChkEnd
{
    return { 
        'kind'    => ';', 
    };
}

###############################################################################
# instructions

sub addInst
{
    my ($name, $fmt, $req) = @_;
    $hdlInst{$name} = [$fmt, $req];
    push @hdlInstList, $name;
}

sub getInstFormat
{
    my $inst = shift;
    return $hdlInst{$inst}[0];
}

sub getInstReq
{
    my $inst = shift;
    return $hdlInst{$inst}[1];
}

###############################################################################
# HDL to Target Name Translation

# FIXME: each name should start with a unique prefix, revise all names accordingly

#
# Auto-generated private names
#
sub getTargetPropName             { my $name = shift;      return 'PROP_' . uc($name); }
sub getTargetPropValListName      { my $name = shift;      return 'PROP_VALUES_' . uc($name); }
sub getTargetInstPropsName        { my $name = shift;      return 'INST_PROPS_' . uc($name); }
sub getTargetInstPropValListName  { my ($prop, $val) = @_; return uc('INST_PROP_VALUES_' . ($prop) . '__' . $val); }
sub getTargetExValName            { my ($prop, $val) = @_; return uc(getBaseProp($prop) . '_VAL_' . $val); }
sub getTargetAttrName             { my ($prop, $val) = @_; return uc(getBaseProp($prop) . '_ATTR_' . $val); }
sub getTargetValListName          { my ($prop, $val) = @_; return uc(getBaseProp($prop) . '_VALUES_' . $val); }
sub getTargetReqName              { my $name = shift;      return 'req_' . $name; }
sub getTargetBrigChkName          { my $name = shift;      return 'check_' . lc($name); }
sub getTargetExChkName            { my $name = shift;      return 'validate' . ucfirst($name); }
sub getTargetChkInstPropName      { my $name = shift;      return 'chkInstProp' . ucfirst($name); }
sub getTargetInstValidatorName    { my $name = shift;      return 'validateInst' . ucfirst($name); }

#
# Externally-defined names
#
sub getTargetInstName         { my $name = shift; return "Brig::BRIG_OPCODE_" . uc($name); }
sub getTargetFormatClass      { my $name = shift; return 'Inst' . $name; }
sub getTargetFormatName       { my $name = shift; return 'Brig::BrigEInst' . $name; }
sub getTargetPropAccessorName { my $name = shift; return 'get' . ucfirst($name); }
sub getTargetBrigValName      
{ 
    my ($prop, $val) = @_; 

    if ($hdlPropPref{$prop}) 
    {
        return 'Brig::BRIG_' . $hdlPropPref{$prop} . '_' . uc($val);
    }
    return $val; # FIXME: think over possible consequences; should we enforce specifying 'BrigPref' for all BRIG props? Special props like ftz do not need it
}

sub getTargetValName
{ 
    my ($prop, $val) = @_; 
    return isBrigProp($prop)? getTargetBrigValName($prop, $val) : getTargetExValName($prop, $val); 
}

###############################################################################
# Dumping

sub dumpCheckProp
{
    my $chk = shift;
    return getChkPropName($chk) . ' = ' . join(', ', getChkPropValues($chk)) . ';';
}

sub dumpCall
{
    my $chk = shift;
    return getChkCallName($chk) . ';';
}

sub dumpCheckCond
{
    my $chk = shift;
    my $res;
    $res .= '{';
    $res .= join(' ', map { dumpCheckProp($_) } getChkCondTests($chk));
    $res .= ' ? ';
    $res .= join(' ', map { isChkProp($_)? dumpCheckProp($_) : dumpCall($_) } getChkCondAsserts($chk));
    $res .= '}';
    return $res;
}

sub dumpReq
{
    my ($name) = @_;
    dumpReqBase(@_, @{$hdlReq{$name}});
}

sub dumpOrigReq
{
    my ($name) = @_;
    dumpReqBase(@_, @{$hdlReqOrig{$name}});
}

sub dumpReqBase
{
    my ($name, $pref, @reqlist) = @_;

    print $pref, "Req $name = {\n";
    for my $chk (@reqlist) 
    {
        print $pref, '    ';
        if (isChkProp($chk)) {
            print dumpCheckProp($chk);
        } elsif (isChkCall($chk)) {
            print dumpCall($chk);
        } elsif (isChkCond($chk)) {
            print dumpCheckCond($chk);
        } elsif (isChkEnd($chk)) {
            print ';';
        } else {
            die "internal dump error";
        }
        print "\n";
    }
    print $pref, "}\n";
}

###############################################################################
# Helpers

sub unique          # Return unique array elements
{
    my %hash = map { $_, 1 } @_;
    return keys %hash;
}

###############################################################################
# Parser

sub parsePropElement;

sub multiply    # Multiply 2 lists, so that (a, b)(x, y) result in (ax, ay, bx, by)
{
    return map { my $second = $_; map { $_ . $second } @_ } parsePropElement;
}

sub parsePropList           # PropList ::= PropElement ("," PropElement)*
{
    my @list = ();
    while (1)
    {
        push @list, parsePropElement;
        last unless trySkipToken('COMMA');
    }
    @list or lexError "Empty list is invalid";

    return @list;
}

sub parsePropElement        # PropElement ::= Name | "(" PropList ")" | Name "(" PropList ")" | "(" PropList ")" PropElement
{
    my @list;
    my $reqTerm = 1;

    if (@_) 
    {
        @list = @_;
    }
    elsif (peekToken eq 'NAME')
    {
        @list = (getToken('NAME'));
    }
    elsif (trySkipToken('LBRR'))
    {
        @list = parsePropList;
        skipToken 'RBRR';
        $reqTerm = 0;
    }
    else 
    {
        expected('NAME', 'LBRR');
    }

    return @list if peekTokens('TERM', 'COMMA', 'RBR', 'RBRR', 'CHK');
    !$reqTerm or expected('COMMA', 'TERM', 'LBRR'); # best we can afford here (for diagnostic purposes)

    return multiply @list;
}

sub parsePropDef            # PropDef ::= { AliasName "=" } PropElement
{
    my $name = shift;
    my $alias;
    my @list;

    if (peekToken eq 'NAME')
    {
        my $val = getToken('NAME');
        if (trySkipToken('EQ')) {
            $alias = $val;
            @list = parsePropElement;
        } else {
            @list = parsePropElement($val);
        }
    }
    else
    {
        @list = parsePropElement;
    }

    for my $val (@list)
    {
        !isPropVal($name, $val) or lexError "Redefinition of value '$val'";
        addPropVal($name, $val);
    }

    if ($alias) {
        my $aliasName = $alias;
        !isAlias($name, $alias) or lexError "Redefinition of alias '$aliasName'";
        addAlias($name, $alias, @list);
    }
}

sub parseProp           # Prop ::= PropName "=" PropDef { "," PropDef } ";"
{
    my $name = getToken('NAME');

    setContext "parsing property '$name'";
    !isBaseProp($name)  or lexError "Redefinition of property '$name'";
    !isClone($name) or lexError "Redefinition of property clone '$name'";

    $currentProp = $name;

    skipToken('EQ');

    while (1) {
        parsePropDef($name);
        last if skipToken('COMMA', 'TERM') ne 'COMMA'
    }
}

sub parseClone          # Clone ::= PropList ";"
{
    defined $currentProp or lexError "No property context to define clone";
    setContext "parsing clone of property '$currentProp'";

    my @list = parsePropList;
    skipToken('TERM');

    for my $name (@list)
    {
        $name !~ m/[\._]/ or !isBrigProp($currentProp) 
                              or lexError "Attributes (delimited with '.' and '_') cannot be used with clones of brig properties";
        !isBaseProp($name)    or lexError "Redefinition of property '$name'";
        !isClone($name)   or lexError "Redefinition of property clone '$name'";

        addClone($name, $currentProp);
    }
}

sub parseDeps          # [DependsOn | Affects] ::= PropList ";"
{
    my $option = shift;
    defined $currentProp or lexError "No property context for $option";
    setContext "parsing $option of property '$currentProp'";

    my @list = parsePropList;
    skipToken('TERM');

    for my $name (@list)
    {
        isBaseProp($name) or lexError "Unknown property '$name' (clones are not accepted)";
    }

    return @list;
}

sub parseAttr          # Attr ::= PropList ";"
{
    defined $currentProp or lexError "No property context to define attribute";
    setContext "parsing attribute of property '$currentProp'";

    !isBrigProp($currentProp) or lexError "Brig property cannot have attributes";  # FIXME

    my @list = parsePropList;
    skipToken('TERM');

    for my $name (@list)
    {
        $name !~ m/[\._]/ or lexError "Attributes cannot include '.' and '_'";

        !isAttr($currentProp, $name) or lexError "Redefinition of attribute '$name'";
        addAttr($currentProp, $name);
    }
}

sub parseBrigProp 
{
    parseProp;
    markBrigProp($currentProp);
}

sub parseBrigBitProp 
{
    my $name = getToken('NAME');

    setContext "parsing property '$name'";
    !isBaseProp($name)  or lexError "Redefinition of property '$name'";
    !isClone($name) or lexError "Redefinition of property clone '$name'";

    $currentProp = $name;

    skipToken('TERM');

    addPropVal($name, '0');
    addPropVal($name, '1');

    addAlias($name, 'any', ('0', '1'));
    addAlias($name, 'none', ('0'));

    markBrigProp($currentProp);
}

sub parseExtProp 
{
    parseProp;
}

sub parseMetaProp 
{
    parseProp;
    dclMetaProp($currentProp);
}

sub parseDependsOn
{
    !isMetaProp($currentProp) or lexError "Meta properties cannot have dependencies";  # FIXME

    my @props = parseDeps 'DependsOn';
    for my $prop (@props)
    {
        dclDepProp($currentProp);
        dclPrmProp($prop);
    }
}

sub parseAffects
{
    my @props = parseDeps 'Affects';
    for my $prop (@props)
    {
        if (isMetaProp($currentProp)) {
            dclPrmProp($prop);
        } else {
            dclPrmProp($currentProp);
            dclDepProp($prop);
        }
    }
}

sub parsePrefix
{
    my $pref = getToken('NAME');
    skipToken('TERM');

    defined $currentProp or lexError "No property context for BrigPrefix";
    setContext "parsing BrigPrefix of property '$currentProp'";

    !defined $hdlPropPref{$currentProp} or lexError "Redefinition of BrigPrefix for '$currentProp'";
    $hdlPropPref{$currentProp} = $pref;
}

# FIXME: Should be extended to allow more generic 
# expressions such as (PropList / PropList)
#
sub parseStarExpr           # StarExpr = "*" { "/" PropList }
{                           # Make list including all properties
    my $prop = shift;
    my %values = %{getPropValues($prop)};

    if (trySkipToken('SLASH')) # Exclude properties specifies after "/"
    {
        my @excluded = map { expandAliasVal($prop, $_) } parsePropList;
        delete @values{@excluded}; # duplicate values are not a problem
    }

    return sort keys %values; # 'sort' is necessary to ensure stable array name
}

sub parseAlias          # Alias ::= AliasName "=" ( StarExpr | PropList ) ";"
{
    my $name = getToken('NAME');

    defined $currentProp or lexError "No property context to define alias '$name'";
    setContext "parsing alias of property '$currentProp'";

    !isAlias($currentProp, $name) or lexError "Redefinition of alias '$name'";
    !isPropVal($currentProp, $name) or lexError "Invalid alias name '$name', must differ from property values";

    skipToken('EQ');

    if (trySkipToken('STAR')) { # FIXME there is similar code below

        my @res = parseStarExpr($currentProp);
        skipToken('TERM');

        @res or lexError "Alias '$name' has an empty list of values";
    
        addAlias($currentProp, $name, @res);
        return;
    }

    my @list = parsePropList;
    skipToken('TERM');

    my @res = map { expandAliasVal($currentProp, $_) } @list;

    for my $val (@res) {
        isPropVal($currentProp, $val) or lexError "Undefined value '$val' of property '$currentProp'";
    }

    addAlias($currentProp, $name, @res);
}

sub parseCheck          # Check ::= "=" ( StarExpr | PropList ) {";"} 
{
    my $name = shift;
    my $prop = getBaseProp $name;
    $prop or lexError "Undefined property '$name'";

    skipToken('EQ');

    if (trySkipToken('STAR')) # FIXME: There is similar code in parseAlias
    {
        my @values = parseStarExpr($prop);
        
        @values or lexError "Property '$name' has an empty list of values";

        expected('TERM', 'CHK', 'RBR');
        trySkipToken('TERM');

        return makeChkProp($name, @values);
    }

    my @values = parsePropList;

    expected('TERM', 'CHK', 'RBR');
    trySkipToken('TERM');

    for my $val (@values) 
    {
        isPropVal($prop, $val) or isAlias($prop, $val) 
                               or lexError "Undefined value (or alias) '$val' of property '$name'";
    }

    return makeChkProp($name, @values);
}

sub parseCheckList          # CheckList ::= { PropName Check }+
{
    my @res;
    while (peekToken eq 'NAME') {
        push @res, parseCheck(getToken('NAME'));
    }
    @res or lexError "List of conditions must include at least one element";
    return @res;
}

sub parseReqList            # ReqList ::= { ( PropName Check ) | ReqName }+
{
    my @res;
    while (peekToken eq 'NAME') {
        push @res, parseCheckOrReq(getToken('NAME'));
    }
    return @res;
}

sub parseCond               # Cond ::= "{" CheckList "?" ReqList "}"
{
    skipToken('LBR');
    my $checks = [parseCheckList];
    skipToken('CHK');
    my $reqs = [parseReqList];
    skipToken('RBR');
    return makeChkCond($checks, $reqs);
}

sub parseCall               # Call ::= ReqName { ';' }
{
    my $req = shift;
    $hdlReq{$req} or lexError "Undefined requirement '$req'";

    expected('TERM', 'RBR');
    trySkipToken('TERM');

    return makeChkCall($req);
}

sub parseCheckOrReq         # CheckOrReq ::= PropName Check | ReqName
{
    my $name = shift;
    return peekTerminator()? parseCall($name) : parseCheck($name);
}

sub parseReq                # Req ::= ReqName "{" ( CheckOrReq | ( Cond+ ";" ) )* "}"
{
    my $name = getToken('NAME');
    setContext "parsing requirement '$name'";

    !$hdlReq{$name} or lexError "Redefinition of requirement '$name'";

    skipToken('LBR');

    my @reqlist; 
    while ((my $tok = peekToken) ne 'RBR') 
    {
        if ($tok eq 'NAME') 
        { 
            push @reqlist, parseCheckOrReq(getToken('NAME')); 
        }
        else 
        { 
            while (1) {
                push @reqlist, parseCond; 
                last if trySkipToken('TERM')
            }
            push @reqlist, makeChkEnd; 
        }
    }
    skipToken('RBR');

    $hdlReq{$name} = [@reqlist];
}

sub parseInst               # Inst ::= InstName "(" FormatName "," ReqName ")"
{
    my $name = getToken('NAME');
    setContext "parsing instruction '$name'";

    skipToken('LBRR');
    my $fmt = getToken('NAME');
    skipToken('COMMA');
    my $req = getToken('NAME');
    skipToken('RBRR');

    !$hdlInst{$name} or lexError "Redefinition of instruction '$name'";
    $hdlReq{$req} or lexError "Undefined requirement '$req'";

    addInst($name, $fmt, $req);
}

###############################################################################
# Property List Optimizer
#
# Purpose:
#    - expand each list of property values by replacing aliases in the list with their values
#    - remove duplicate values from lists of property values
#    - find identical lists of values
#    - replace long list of values (longer than MAX_VALS_PER_CALL) with reference to arrays
#      (on this step, identical lists of values are replaced with one array reference)
#
# NB: Array reference is a special form of property alias.

sub getAttr
{
    my ($prop, $val) = @_;

    my $name;
    my $attr;

    if ((($name, $attr) = $val =~ /^(.+)_([^_]+)$/) && isAttr($prop, $attr))
    {
        return ($name, $attr);
    }
    else
    {
        return ($val, "");
    }
}

sub extractAttr
{
    my ($prop, $firstVal, @values) = @_;

    return ("", $firstVal, @values) if isBrigProp($prop);

    my @res;
    my ($name, $attr) = getAttr($prop, $firstVal);
    push @res, $name;

    for my $val (@values)
    {
        my ($name, $xattr) = getAttr($prop, $val);
        ($xattr eq $attr) or lexError "Incompatible attributes '$attr' and '$xattr' of property '$prop'";
        push @res, $name;
    }

    return $attr, @res;
}

sub expandAliases
{
    my ($prop, @values) = @_;
    return map { expandAliasVal($prop, $_) } @values;
}

sub optimizeCheck
{
    my $chk = shift;
    return $chk unless isChkProp($chk);

    my $attr;
    my $prop = getChkPropName($chk);
    my @values = getChkPropValues($chk);
    my @expValues = sort(unique(expandAliases($prop, @values)));

                                                           # Property values may include attribute, e.g. "reg.stype"
    ($attr, @expValues) = extractAttr($prop, @expValues);  # Validate that all values are either labelled with 
    $attr = "\.$attr" if $attr ne "";                      # the same attribute or none are.
                                                           # Attribute (if any) is removed from values
                                                           # and appended to property name
    
    my $alias = makeArrayName(@expValues);                 # create an array for each unique sequence of brig values
    if (!isAlias($prop, $alias)) {
        addAlias($prop, $alias, @values);
    }
    
    createTargetArrayName($prop, $alias, @expValues);      # generate a name for this array (for use in C++ code)

    return makeChkProp($prop . $attr, $alias);
}

sub optimizeCond
{
    my $chk = shift;
    return makeChkCond([map { optimizeCheck($_) } getChkCondTests($chk)], 
                       [map { optimizeCheck($_) } getChkCondAsserts($chk)]);
}

sub optimizeReq
{
    my $name = shift;
    $hdlReqOrig{$name} = $hdlReq{$name};
    $hdlReq{$name} = [ map { isChkCond($_)? optimizeCond($_) : optimizeCheck($_) } @{$hdlReq{$name}} ];
}

###############################################################################
# TestGen Req Analyzer

sub analyzeInstChk
{
    my ($inst, $chk) = @_;
    addPlnPropDesc($inst, $chk);
}

sub analyzeInstReq;

sub analyzeInstCond
{
    my ($inst, $cond) = @_;

    for my $chk (getChkCondTests($cond)) {
        addPrmPropDesc($inst, $chk);
    }

    for my $chk (getChkCondAsserts($cond)) {
        if (isChkCall($chk)) {
            analyzeInstReq($inst, getChkCallName($chk)); # recursive FIXME: nested reqs must not include conditions 
        } else {
            addCndPropDesc($inst, $chk);
        }
    }
}

sub analyzeInstReq
{
    my ($inst, $req) = @_;
    my @reqlist = @{$hdlReq{$req}};

    for my $chk (@reqlist) 
    {
        if (isChkProp($chk)) {
            analyzeInstChk($inst, $chk);
        } elsif (isChkCall($chk)) {
            analyzeInstReq($inst, getChkCallName($chk)); # recursive
        } elsif (isChkCond($chk)) {
            analyzeInstCond($inst, $chk);
        } elsif (isChkEnd($chk)) {
            # nothing to do            
        } else {
            die "internal error";
        }
    }
}

###############################################################################
# Generator

# FIXME: define all error messages in class or move to the support lib

sub genSwitchHeader 
{
    my ($type, $name, $args) = @_;

    print 
<<"EOT";
$type $className\::$name($args)
{
    switch (inst.opcode())
    {
EOT
}

sub genSwitchFooter 
{
    my ($name, $errHdlr) = @_;

    print 
<<"EOT";
        default:
            @{[ $errHdlr->() ]}
            break;
    }
} // $className\::$name 
EOT
}

sub ttt { return "ccc" }

sub genValidatorCase 
{
    my $name = shift;
    my $chkHdlr = sub { my ($fmt, $inst) = @_; return getTargetReqName(getInstReq($name)) . '<' . $fmt . '>(' . $inst . ');' };
    my $errHdlr = sub { my ($inst, $msg) = @_; return 'invalidFormat(' . $inst . ', "' . $msg . '");' };

    genCase($name, $chkHdlr, $errHdlr);
}

sub genCase 
{
    my ($name, $chkHdlr, $errHdlr) = @_;

    my $brigName = getTargetInstName($name);
    my $fmtClass = getTargetFormatClass(getInstFormat($name));

    if ($fmtClass eq 'InstMod') {

        print 
<<"EOT";
        case ($brigName):
        {
            if (InstMod i = inst)
            {
                @{[ $chkHdlr->('InstMod', 'i') ]}
            }
            else if (InstBasic i = inst)
            {
                @{[ $chkHdlr->('InstBasic', 'i') ]}
            }
            else
            {
                @{[ $errHdlr->('inst', 'InstBasic or InstMod') ]}
            }
            break;
        } 
EOT

    } else {

        print 
<<"EOT";
        case ($brigName):
        {
            $fmtClass i = inst;
            if (!i) { @{[ $errHdlr->('inst', $fmtClass) ]} }
            @{[ $chkHdlr->($fmtClass, 'i') ]}
            break;
        } 
EOT

    }
}

sub translateVal
{
    my ($name, $val) = @_;
    my $prop = getBaseProp $name;

    if (isArrayName($val))                                   # Array (generated alias)
    {

#if (!isAlias($prop, $val)){
#print STDERR "NAME = '", $name, "', ARR = '", $val, "'\n";
#}
        isAlias($prop, $val) or lexError "Internal error: unknown array '$val' of property '$name'";

        my $array = getTargetArrayName($prop, $val);          # optimized list - replaced 
        return ($array, "sizeof($array) / sizeof(unsigned)"); # with array ref
    }

    return getTargetValName($prop, $val);
}

sub translateValues         # Translate property values into format suitable for passing to validation library
{
    my ($prop, @values) = @_;
    return map { translateVal($prop, $_) } @values;
}

sub decayPropName
{
    my $prop = shift;
    my $val;

    if (isBrigProp($prop)) 
    {
        $val = getTargetPropAccessorName($prop) . '<T>(inst)';    # accessor for reading Brig property
    } 
    elsif ($prop =~ m/^(.*?)_(.*)$/) # property with an attribute like this: s0.model
    {
        $prop = $1;
        $val  = getTargetAttrName($prop, $2); # attribute value
    }
    elsif ($prop =~ m/^(.*?)\.(.*)$/) # property with an attribute like this: s0.model
    {
        $prop = $1;
        $val  = getTargetAttrName($prop, $2); # attribute value
    }
    else
    {
        $val  = getTargetAttrName($prop, 'NONE');
    }

    return ($prop, $val);
}

sub getCheckArgs
{
    my $chk = shift;
    my ($prop, $val) = decayPropName(getChkPropName($chk));
    return 'inst, ' . getTargetPropName($prop) . ", $val, " . join(', ', translateValues($prop, getChkPropValues($chk)));
}

sub genDirectCheck 
{
    my ($prop, $name) = @_;
    my $targetName = getTargetArrayName($prop, $name);
    my $val = getTargetPropAccessorName($prop) . '<T>(inst)';
    return getTargetBrigChkName($targetName) . "($val)";
}

sub genCheck 
{
    my ($chk, $indent) = @_;
    my $prop = getChkPropName($chk);

    if (isBrigProp($prop))
    {
        my @values = getChkPropValues($chk);
        return $indent . genDirectCheck($prop, shift @values);
    }
    else
    {
        if ($prop =~ m/^(.*?)\.(.*)$/) { $prop = $1 }
        return $indent . getTargetExChkName(getBaseProp($prop)) . '(' . getCheckArgs($chk) . ', false)';
    }
}

sub genCall
{
    my ($chk) = @_;
    my $name = getChkCallName($chk);
    return '    ' . getTargetReqName($name) . "(inst);\n";
}

sub genAssert 
{
    my ($chk, $indent) = @_;
    my $prop = getChkPropName($chk);
    my $res;

    if (isBrigProp($prop))
    {
        my ($val0) = getChkPropValues($chk);
        $res = '    if (!' . genDirectCheck($prop, $val0) . ") ";
        if ($genValidator) {
            $res .= "{\n$indent        brigPropError(" . getCheckArgs($chk) . ");\n$indent    }\n";
        } else {
            $res .= "return false;\n";
        }
    }
    else
    {
        if ($prop =~ m/^(.*?)\.(.*)$/) { $prop = $1 }
        $prop = getBaseProp($prop);
        
        my $vldFlag = $genValidator? '' : ', false';
        $res = getTargetExChkName($prop) . '(' . getCheckArgs($chk) . $vldFlag . ")";
        if (!$genValidator) { $res = 'if (!' . $res . ') return false'; }
        $res = '    ' . $res . ";\n";
    }
    
    return $res;
}

sub genReqDecl 
{
    my $name = shift;

    print "    template<class T> bool " . getTargetReqName($name) . "(T inst);\n";
}

sub genReq 
{
    my $name = shift;
    my @reqlist = @{$hdlReq{$name}};
    
    print '//', '=' x 80, "\n";
    dumpOrigReq($name, '//  ');

    print "template<class T> bool InstValidator::", getTargetReqName($name), "(T inst)\n";
    print "{\n";

    my %propVariants = ();        # list of properties used for variant selection
    
    for my $chk (@reqlist) 
    {
        if (isChkCall($chk)) 
        {
            print genCall($chk, ""); 
        } 
        elsif (isChkProp($chk)) 
        {
            print genAssert($chk, ""); 
        } 
        elsif (isChkEnd($chk)) # terminator: list of variants has finished
        {
            print "    else \n";
            print "    {\n";
            print "        invalidVariant(inst, ", join(', ', map { getTargetPropName($_) } keys %propVariants), ");\n";
            print "    }\n";
            %propVariants = ();
        }
        elsif (isChkCond($chk)) # one of variants
        {        
            if (keys(%propVariants) == 0) { # First format variant
                print "\n";
                print "    if (\n";
            } else {
                print "    else if (\n";
            }

            print join(" &&\n", map { $propVariants{getChkPropPureName($_)} = 1; genCheck($_, '            ') } getChkCondTests($chk)), "\n";
            print "       )\n";
            print "    {\n    ";

            print join("    ", map { isChkCall($_)? genCall($_, "    ") : genAssert($_, "    "); } getChkCondAsserts($chk));
            print "    }\n";
        }
        else
        {
            die "internal error";
        }
    }
    print "    return true;\n";
    print "}\n\n";
}

sub genArrayDecl
{
    my ($prop, $name) = getAliasComponents(shift);
    my $targetName = getTargetArrayName($prop, $name);

    print '    static unsigned ', $targetName, "[];\n";
}

sub genArrayDef
{
    my ($prop, $name) = getAliasComponents(shift);
    my $targetName = getTargetArrayName($prop, $name);

    print "unsigned $className\::$targetName\[] = {\n    ";
    print join(",\n    ", translateValues($prop, getTargetArrayValues($prop, $name)));
    print "\n};\n\n";
}

sub genCheckDecl
{
    my ($prop, $name) = getAliasComponents(shift);
    return if !isBrigProp($prop);

    my $targetName = getTargetArrayName($prop, $name);
    print '    static bool ', getTargetBrigChkName($targetName), "(unsigned val);\n";
}

sub genCheckDef
{
    my ($prop, $name) = getAliasComponents(shift);
    return if !isBrigProp($prop);

    my $targetChkName = getTargetBrigChkName(getTargetArrayName($prop, $name));

    print
<<"EOT";
bool $className\::$targetChkName(unsigned val)
{
    switch(val)
    {    
EOT
    print "    case ";
    print join(":\n    case ", translateValues($prop, getTargetArrayValues($prop, $name)));
    print

<<"EOT";
:
        return true;
    default: 
        return false;
    }
}

EOT
}

sub genCommonDeclarations
{
    print "\nprivate:\n";
    for my $alias (getAliasNames()) {
        setContext "generating array declaration for '$alias'";
        genArrayDecl($alias) if isArrayName($alias)
    }
    setContext;

    print "\nprivate:\n";
    for my $alias (getAliasNames()) {
        setContext "generating check declaration for '$alias'";
        genCheckDecl($alias) if isArrayName($alias)
    }
    setContext;
}

sub genCommonDefinitions
{
    for my $alias (getAliasNames()) 
    {
        setContext "generating array definition for '$alias'";
        genArrayDef($alias) if isArrayName($alias)
    }

    for my $alias (getAliasNames()) 
    {
        setContext "generating check definition for '$alias'";
        genCheckDef($alias) if isArrayName($alias)
    }
}

###############################################################################
# Main Parser

setContext;
while (my $val = getToken('NAME', 1)) 
{
    if ($val eq 'BrigProp')      { parseBrigProp; }
    elsif ($val eq 'BrigBitProp'){ parseBrigBitProp; }
    elsif ($val eq 'ExtProp')    { parseExtProp; }
    elsif ($val eq 'MetaProp')   { parseMetaProp; }
    elsif ($val eq 'DependsOn')  { parseDependsOn; }
    elsif ($val eq 'Affects')    { parseAffects; }
    elsif ($val eq 'BrigPrefix') { parsePrefix; }
    elsif ($val eq 'Clone')      { parseClone; }
    elsif ($val eq 'Alias')      { parseAlias; }
    elsif ($val eq 'Attr')       { parseAttr; }
    elsif ($val eq 'Req')        { parseReq;  }
    elsif ($val eq 'Inst')       { parseInst; }
    else {
        lexError "Invalid identifier '$val', expected one of: BrigProp, Prop, Clone, Alias, Req, Inst";
    }
    setContext;
}

###############################################################################
# Properties Analyzer (for TestGen only)

if ($ARGV[0] eq "-target=testgen") {
    
    for my $inst (sort keys %hdlInst) 
    {
        setContext "analyzing instruction '$inst'";

        my $req = getInstReq($inst);
        analyzeInstReq($inst, $req);
    }
    setContext;
}

###############################################################################
# Main Optimizer

for my $req (keys %hdlReq) {
    setContext "optimizing requirement '$req'";
    optimizeReq($req);
}
setContext;


###############################################################################
if ($ARGV[0] eq "-target=validator") {
###############################################################################
# Main Generator - Validator Declarations

print 
<<"EOT";

using HSAIL_ASM::Inst;

namespace HSAIL_ASM {

class InstValidator : public InstValidatorBase 
{
public:
    InstValidator(unsigned type) : InstValidatorBase(type) {}
    void validateInst(Inst inst);
EOT

genCommonDeclarations();

print "\nprivate:\n";
for my $req (sort keys %hdlReq) {
    setContext "generating requirement declaration for '$req'";
    genReqDecl($req);
}
setContext;

print 
<<"EOT";

}; // class InstValidator 

EOT

###############################################################################
# Main Generator - Validator  Definitions

genCommonDefinitions();

for my $req (sort keys %hdlReq) 
{
    setContext "generating requirement definition for '$req'";
    genReq($req);
}

genSwitchHeader('void', 'validateInst', 'Inst inst');
for my $inst (sort keys %hdlInst) 
{
    setContext "generating switch case for instruction '$inst'";
    genValidatorCase($inst);
}
genSwitchFooter('validateInst', sub { return 'validate(inst, false, "Invalid instruction opcode");' });

print 
<<"EOT";
} // namespace HSAIL_ASM 
EOT

###############################################################################
} elsif ($ARGV[0] eq "-target=testgen") {
###############################################################################
# Main Generator - TestGen Declarations

print 
<<"EOT";

namespace HSAIL_ASM {

class InstDescBase : public InstValidatorBase
{
public:
    static unsigned* getPropVals(unsigned propId, unsigned& num); // should include XXX_VAL_INVALID for invalid values (non-brig only)
    static bool isBrigProp(unsigned propId);

public:
    static unsigned* getOpcodes(unsigned& num);
    static unsigned getFormat(unsigned opcode);
    static unsigned* getProps(unsigned opcode, unsigned& prm, unsigned& sec);
    static unsigned* getPropVals(unsigned opcode, unsigned propId, unsigned& num);

public:
    static bool isValidProp(Inst inst, unsigned propId);
    static bool validatePrimaryProps(Inst inst);
    static bool isValidInst(Inst inst); // for debugging only

private:
    static unsigned OPCODES[];
EOT

genCommonDeclarations();

print "\nprivate:\n";
for my $prop (keys %hdlProp) {
    print '    static unsigned ', getTargetPropValListName($prop), "[];\n"; 
}

print "\nprivate:\n";
for my $inst (sort keys %hdlInst) {
    print '    static unsigned ', getTargetInstPropsName($inst), "[];\n";
}

print "\nprivate:\n";
for my $inst (sort keys %hdlInst) {
    for my $prop (getOrderedPropList($inst)) {
        print '    static unsigned ', getTargetInstPropValListName($inst, $prop), "[];\n";
    }
    print "\n";
}

print "\nprivate:\n";
for my $inst (sort keys %hdlInst) {
    print '    template<class T> static bool ', getTargetChkInstPropName($inst), "(T inst, unsigned propId);\n";
}

if ($validateTestGen)
{
    print "\nprivate:\n";
    for my $inst (sort keys %hdlInst) {
        print '    template<class T> static bool ', getTargetInstValidatorName($inst), "(T inst);\n";
    }
}

print 
<<"EOT";
}; // class InstDescBase 

EOT

genCommonDefinitions();

#-------------------------------------------------------------------------------
# isBrigProp

setContext "generating isBrigProp";

print 
<<"EOT";
bool InstDescBase::isBrigProp(unsigned propId)
{
    switch(propId)
    {
EOT

for my $prop (keys %hdlProp) {
    print '    case ', getTargetPropName($prop), ': return ', (isBrigProp($prop)? 'true' : 'false'), ";\n"; 
}

for my $clone (keys %hdlClone) {
    print '    case ', getTargetPropName($clone), ': return ', (isBrigProp($hdlClone{$clone})? 'true' : 'false'), ";\n"; 
}

print 
<<"EOT";
    }
    assert(false);
    return false;
}

EOT

#-------------------------------------------------------------------------------
# getOpcodes

setContext "generating getOpcodes";

print 
<<"EOT";
unsigned InstDescBase::OPCODES[] = 
{
EOT

for my $name (@hdlInstList) 
#for my $name (sort keys %hdlInst) 
{
    print "    ", getTargetInstName($name), ",\n";
}

print 
<<"EOT";
};

unsigned* InstDescBase::getOpcodes(unsigned& num)
{
    num = sizeof(OPCODES) / sizeof(unsigned*);
    return OPCODES;
}

EOT

#-------------------------------------------------------------------------------
# getFormat

setContext "generating getOpcodes";

print 
<<"EOT";
unsigned InstDescBase::getFormat(unsigned opcode)
{
    switch(opcode)
    {
EOT

for my $name (sort keys %hdlInst) 
{
    my $brigFormat = getTargetFormatName(getInstFormat($name));
    print "    case ", getTargetInstName($name), ': return ', $brigFormat, ";\n";
}

print 
<<"EOT";
    }

    assert(false);
    return (unsigned)-1;
}

EOT

#-------------------------------------------------------------------------------
# getPropVals(unsigned propId, unsigned& num)

setContext "generating getPropVals(propId, num)";

sub printPropValList
{
    my ($prop, @list) = @_;

    my %values; # used to remove duplicates

    for my $val (@list) 
    {
        # Non-brig properties may have attribites specified after the name, e.g. "reg.generic"
        # These attributes are not a part of property value and must be removed.
        # Attributes removal result in identical names which must be removed as well, e.g.
        # "reg.generic" and "reg.stype" are both reduced to "reg".

        if (!isBrigProp($prop)) {
            ($val) = getAttr($prop, $val); # remove attr if any
        }
        if (!$values{$val}) { # remove duplicates
            print '    ', getTargetValName($prop, $val), ",\n";
        }
        $values{$val} = 1;
    }
}

sub printPropValues
{
    my $prop = shift;

    printPropValList($prop, sort keys %{$hdlProp{$prop}});

    if (!isBrigProp($prop)) {
        print '    ', getTargetValName($prop, 'INVALID'), ",\n";
    }
}

for my $prop (keys %hdlProp) {
    print 'unsigned InstDescBase::', getTargetPropValListName($prop), "[] = \n{\n"; 
    printPropValues($prop);
    print "};\n\n"
}

sub printPropValsCode
{
    my $prop = shift;
    my $arrName = getTargetPropValListName($prop);
    print '    case ', getTargetPropName($prop), "num = sizeof($arrName) / sizeof(unsigned*); return $arrName;\n"; 
}

print 
<<"EOT";
unsigned* InstDescBase::getPropVals(unsigned propId, unsigned& num) // should include XXX_VAL_INVALID for invalid values (non-brig only)
{
    switch(propId)
    {
EOT

for my $prop (sort keys %hdlProp) 
{
    for my $clone (sort keys %hdlClone) {
        if (getBaseProp($clone) eq $prop) {
            print '    case ', getTargetPropName($clone), ":\n"; 
        }
    }

    my $arrName = getTargetPropValListName($prop);
    print '    case ', getTargetPropName($prop), ": \tnum = sizeof($arrName) / sizeof(unsigned*); return $arrName;\n\n"; 
}

print 
<<"EOT";
    }
    assert(false);
    num = 0;
    return 0;
}

EOT

#-------------------------------------------------------------------------------
# getProps

setContext "generating getProps";

# FIXME: AVOID GENERATION OF IDENTICAL TABLES!
# NB: THERE ARE GROUPS OF INSTRUCTIONS THAT USE THE SAME REQ, e.g. workitemidflat

for my $inst (sort keys %hdlInst) 
{
    print 'unsigned InstDescBase::', getTargetInstPropsName($inst), "[] =\n";
    print "{\n";
    for my $prop (getOrderedPropList($inst)) {
        print '    ', getTargetPropName($prop), ',', ' ' x (20 - length(getTargetPropName($prop))), '// ', getPropKindName($inst, $prop), "\n"; 
    }
    print "};\n\n";
}

print 
<<"EOT";
unsigned* InstDescBase::getProps(unsigned opcode, unsigned& prm, unsigned& sec) 
{
    switch(opcode)
    {
EOT

for my $inst (sort keys %hdlInst) 
{
    print '    case ', getTargetInstName($inst), ":\n";
    print '        prm = ', getPrmPropsNum($inst), ";\n";
    print '        sec = ', getCndPropsNum($inst) + getDepPropsNum($inst) + getPlnPropsNum($inst), ";\n";
    print '        return ', getTargetInstPropsName($inst), ";\n";
    print "\n";
}

print 
<<"EOT";
    }

    assert(false);
    prm = 0;
    sec = 0;
    return 0;
}

EOT

#-------------------------------------------------------------------------------
# getPropVals(unsigned opcode, unsigned propId, unsigned& num)

setContext "generating getPropVals(opcode, propId, num)";

# FIXME: AVOID GENERATION OF IDENTICAL TABLES!
# NB: THERE ARE GROUPS OF INSTRUCTIONS THAT USE THE SAME REQ, e.g. workitemidflat

for my $inst (sort keys %hdlInst) {
    for my $prop (getOrderedPropList($inst)) {
        print 'unsigned InstDescBase::', getTargetInstPropValListName($inst, $prop), "[] =\n";
        print "{\n";
        printPropValList($prop, getInstPropVals($inst, $prop));
        print "};\n\n";
    }
}

print 
<<"EOT";
unsigned* InstDescBase::getPropVals(unsigned opcode, unsigned propId, unsigned& num) 
{
    switch(opcode)
    {
EOT

for my $inst (sort keys %hdlInst) 
{
    print '    case ', getTargetInstName($inst), ":\n";
    print "        switch(propId)\n";
    print "        {\n";
    for my $prop (getOrderedPropList($inst)) {
        print '        case ', getTargetPropName($prop), ":\n";
        print '            num = sizeof(', getTargetInstPropValListName($inst, $prop), ") / sizeof(unsigned);\n";
        print '            return ', getTargetInstPropValListName($inst, $prop), ";\n";
    }
    print "        default: \n";
    print "            assert(false);\n";
    print "            return 0;\n";
    print "        }\n";
    print "\n";
}

print 
<<"EOT";
    }

    assert(false);
    num = 0;
    return 0;
}

EOT

#-------------------------------------------------------------------------------
# isValidProp

# --------------------------------------------------------------------------------------------------------------------------------
# |-- prop ----|-- name  --|-- skip cond --|-- keep all prm --|-- prop filter --| chk type  |-- postponed ---|----- note --------|
# --------------------------------------------------------------------------------------------------------------------------------
# | primary    |   PRM     |  y            |   no             |  this prop      |   LIGHT   |                |                   |
# | last prm   |   PRM     |  no           |   in conds only  |  mta + all prm  |   MEDIUM  |                |                   |
# | meta       |   MTA     |  no           |   in conds only  |  mta + all prm  |   MEDIUM  |                | checked only with last prm |
# | conditional|   CND     |  no           |   in conds only  |  this + all prm |   MEDIUM  | skip chk group |                   |
# | dependent  |   DEP     |  y            |   no             |  this prop      |   LIGHT   |                | not used in conds |
# | plain      |   PLN     |  y            |   no             |  this prop      |   LIGHT   |                |                   |
# | all prm    |    -      |  no           |   yes            |  all prm        |   HEAVY   |                |                   |
# | all        |    -      |  no           |   yes            |     -           |   FULL    |                | for selfvalidation|
# --------------------------------------------------------------------------------------------------------------------------------

sub genSelectorChk
{
    my ($chk, $mode, $indent, @list) = @_;
    my ($prop) = decayPropName(getChkPropName($chk)); # remove attribute if any

    if ($mode eq 'FULL' || grep { $prop eq $_ } @list) {
        print $indent, genAssert($chk, ''); 
    }
}

sub genSelectorCond
{
    my ($cond, $mode, $indent, $first, @list) = @_;

    return if $mode eq 'LIGHT';

    if ($first) { # First format variant
        print "\n";
        print $indent, "if (\n";
    } else {
        print $indent, "else if (\n";
    }

    print join(" &&\n", map { genCheck($_, $indent . '    ') } getChkCondTests($cond)), "\n";
    print $indent, "   )\n";
    print $indent, "{\n";

    for my $chk (getChkCondAsserts($cond)) {
        if (isChkCall($chk)) { # FIXME: analyze limitations on nested code
            genSelector(getChkCallName($chk), $mode, $indent, @list); # recursive
        } else {
            genSelectorChk($chk, $mode, $indent, @list);
        }
    }

    print $indent, "}\n";
}

sub genSelectorCondEnd
{
    my ($chk, $mode, $indent, @list) = @_;

    return if $mode eq 'LIGHT';

    print $indent, "else\n";
    print $indent, "{\n";
    print $indent, "    return false;\n";
    print $indent, "}\n";
}

sub genSelector
{
    my ($req, $mode, $indent, @list) = @_;
    my @reqlist = @{$hdlReq{$req}};
    my $first = 1;

    for my $chk (@reqlist) 
    {
        if (isChkProp($chk)) {
            genSelectorChk($chk, $mode, $indent, @list);
        } elsif (isChkCall($chk)) {
            genSelector(getChkCallName($chk), $mode, $indent, @list); # recursive
        } elsif (isChkCond($chk)) {
            genSelectorCond($chk, $mode, $indent . '    ', $first, @list);
            $first = 0;
        } elsif (isChkEnd($chk)) {
            genSelectorCondEnd($chk, $mode, $indent . '    ', @list);
            $first = 1;
        } else {
            die "internal error";
        }
    }
}

sub genInstPropCheck
{
    my ($inst, $prop, $kind, $mode, @list) = @_;
    my $req = getInstReq($inst);

    print "        // $kind Property\n";
    print '        case ', getTargetPropName($prop), ":\n";
    print "        {\n";
    
    genSelector($req, $mode, '        ', @list);
    
    print "\n";
    print "            return true;\n";
    print "        }\n";
    print "\n";
}

sub genIsValidProp
{
    my $inst = shift;
    my @metaProps = getMetaProps($inst);
    my @prmProps = getPrmProps($inst);
    my @firstPrmProps = @prmProps[0 .. $#prmProps - 1];
    my $lastPrimaryProp = $prmProps[$#prmProps] // '';

#if (@metaProps) {
#    print STDERR "INST = ", $inst, ", META = ", @metaProps, "\n";
#    if (@prmProps) {
#        print STDERR "INST = ", $inst, ", PRM = ", join(", ", @prmProps), "\n";
#    }
#}

    for my $prop (@firstPrmProps)     { genInstPropCheck($inst, $prop, 'Primary',      'LIGHT', ($prop)); }
    if (my $prop = $lastPrimaryProp)  { genInstPropCheck($inst, $prop, 'Last Primary', 'HEAVY', (@prmProps, @metaProps)); }
    for my $prop (getCndProps($inst)) { genInstPropCheck($inst, $prop, 'Conditional',  'HEAVY', ($prop, @prmProps)); } # FIXME: do not include checks for primary outside conds
    for my $prop (getDepProps($inst)) { genInstPropCheck($inst, $prop, 'Dependent',    'LIGHT', ($prop)); }
    for my $prop (getPlnProps($inst)) { genInstPropCheck($inst, $prop, 'Plain',        'LIGHT', ($prop)); }
}


for my $inst (sort keys %hdlInst) 
{
    print 'template<class T> bool InstDescBase::', getTargetChkInstPropName($inst), "(T inst, unsigned propId)\n";
    print "{\n";
    print "    switch(propId)\n";
    print "    {\n";

    genIsValidProp($inst);

    print "    default: \n";
    print "        assert(false);\n";
    print "        return false;\n";
    print "    }\n";
    print "}\n";
}

sub genChkPropCase 
{
    my $name = shift;
    my $chkHdlr = sub { my ($fmt, $inst) = @_; return 'return ' . getTargetChkInstPropName($name) . '<' . $fmt . '>(' . $inst . ', propId);' };
    my $errHdlr = sub { my ($inst, $msg) = @_; return 'assert(false); return false;' };

    genCase($name, $chkHdlr, $errHdlr);
}

genSwitchHeader('bool', 'isValidProp', 'Inst inst, unsigned propId');

for my $inst (sort keys %hdlInst) 
{
    setContext "generating switch case for instruction '$inst'";
    genChkPropCase($inst);
}

genSwitchFooter('isValidProp', sub { return 'assert(false); return false;' });

#-------------------------------------------------------------------------------
# validatePrimaryProps

print 
<<"EOT";

bool InstDescBase::validatePrimaryProps(Inst inst)
{
    unsigned prm;
    unsigned sec;
    unsigned* props = getProps(inst.opcode(), prm, sec);
    if (prm > 0) return isValidProp(inst, props[prm - 1]);
    // assert(false); // FIXME
    return false;
}

EOT

#-------------------------------------------------------------------------------
# isValidInst

sub genIsValidInst
{
    my $inst = shift;
    my $req = getInstReq($inst);

    genSelector($req, 'FULL', '', ());
}

sub genIsValid
{
    my $name = shift;
    my $chkHdlr = sub { my ($fmt, $inst) = @_; return 'return ' . getTargetInstValidatorName($name) . '<' . $fmt . '>(' . $inst . ');' };
    my $errHdlr = sub { my ($inst, $msg) = @_; return 'assert(false); return false;' };

    genCase($name, $chkHdlr, $errHdlr);
}

if ($validateTestGen)
{
    for my $inst (sort keys %hdlInst) {
        print 'template<class T> bool InstDescBase::', getTargetInstValidatorName($inst), "(T inst)\n";
        print "{\n";

        genIsValidInst($inst);

        print "    return true;\n";
        print "}\n\n";
    }

    genSwitchHeader('bool', 'isValidInst', 'Inst inst');

    for my $inst (sort keys %hdlInst) 
    {
        setContext "generating switch case for instruction '$inst'";
        genIsValid($inst);
    }

    genSwitchFooter('isValidInst', sub { return 'assert(false); return false;' });
}

#-------------------------------------------------------------------------------

print 
<<"EOT";

} // namespace HSAIL_ASM 
EOT

###############################################################################
} # -target=testgen
###############################################################################

###############################################################################
# DONE
# 
# + err handling: refer to context in validator file
# + nested refs to req: req Add { req Sub; }
# + replace all " with ' where possible
# + allow "." in prop values, reqirements and aliases
# + make ";" before "?" optional
# + fix comments bug
# + check -> isValid
# + allow nested req only in toplevel or in asserts, disable in checks
# + PropAlias (e.g. to avoid defining both type and stype)
# + "." in identifiers
# + ";" is optional before "?" and "}"
# + grouping and concatenation using "(" and ")"
# + set substraction using "/"
# + "custom" checks
# + list of prop values may include duplicate values; eliminate them
# + improve error reporting
# + error reporting: improve for errors that occur just after req, etc (currently refer to that req, etc)
# + make sure there are no duplicated array names
# + limit length of generated names

###############################################################################
# TODO
# - generate HSAILTestGenCategories.h
# - revise attributes
#   - try creating a better approach
#   - at least we have to remove attr prefix from prop name
# - cannot define "MetaProp type.size = ..."
#    - problem with ".": internal error
#    - investigate issue detect error when metaprop with "." is defined
# - compare performance with old version
# - would it be possible to use new notation for TestGen?
# - extend optimizer to collect all err messages like "Invalid instruction format, expected InstBase"
# - is it possible to move complex checks from Validator back to InstValidator?
# - in the following code, there is a missing ";" which causes the following err message: expected '('
#    s2 = (reg, imm).32 s3 = null;
# - in DEBUG mode, generate a list of all prop values for additional validation
#   - operands:
#     - validate generic operands
#     - some conditions must be asserts (checks are not supported)
#   - ctype: only one element in a list
#   - attribute is only allowed with non-Brig props
#   - Big props may only include Brig enum values
#   - Each prop is specified only once (except for variants)
#   - props correspond to instruction format
# - "." as NIL
# - optimize operands
# - optimize all other props
#   - AluMod: 
# - make dumper
#
# STYLE
# - minimize use of shift, $_[...], $_[x..y]
#
#
#
#
#
#
#
#
# POSTPONED
# - reviw parsing of '(', '*', etc
# - check diagnostic messages: they are misleading in some cases
# - testing

# - process attrs separately 
#   - skip if NONE
#   - call check${prop}${attr} # e.g. checkOperandGeneric
