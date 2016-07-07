use v5.10;
use Carp;
use warnings;
use strict;
                                                    
############################################################################################################
############################################################################################################
###
### The purpose of this script is to generate a set of negative tests from a compact 
### description contained in one file.
### 
### Each generated test has several sections most of which are optional.
### These sections are described using syntax shown in the table below:
### 
###     ----------------------------------------------------------------------------------------------------
###     SECTION               SYNTAX                             NOTE
###     ----------------------------------------------------------------------------------------------------
###     TEST DESCRIPTION      // name: description               Apply to all following tests up to next '//'
###                           // name                            Same as above
###     HSAIL MODULE          !small                             Switch to small model
###                           !large                             Switch to large model
###                           !full                              Switch to full profile
###                           !base                              Switch to base profile
###                           !default                           Switch to default rounding
###                           !near                              Switch to near rounding
###                           !zero                              Switch to zero rounding
###     GLOBAL DEFINITIONS    [[ HSAIL directives ]]             Top-level directives
###     FUNCTION HEADER       N/A                                Generated automatically for non-empty body
###     FUNCTION BODY         HSAIL directives and instructions  Function-scoped directives and code
###     ----------------------------------------------------------------------------------------------------
### 
### Note that each test must be described in one line. Multi-line tests must be concatenated using '\'.
### Comments starting with '///' and blank lines are ignored.
###
############################################################################################################
############################################################################################################

my $line = '';                                      # input line
my $defs = '';                                      # auxiliary definitions (top-level)
my $name = '';                                      # test name
my $info = '';                                      # test description
my $cnt = 0;                                        # test index
my $model = '$large';                               # current Machine Model
my $profile = '$full';                              # current Profile
my $round = '$default';                             # current default rounding
my $module = 'module &ModuleName:1:0';              # HSAIL module
my $logname = "_testinfo.txt";                      # log file name

############################################################################################################
############################################################################################################
############################################################################################################

if ($#ARGV != 1) 
{
    print STDERR "Fatal error: insufficient number of arguments.\n";
    print STDERR "Usage: perl Testgen.pl TestDescription OutputDir\n";
    exit 1;
}

my $testDesc = $ARGV[0];
my $outDir   = $ARGV[1];

if (!open(STDIN, '<', $testDesc)) {
    print STDERR "Can't open $testDesc: $!\n";
    exit 1;
}

open(my $log, "> $outDir/$logname") or die "Can't create $outDir/$logname: $!\n";

while ($line = <STDIN>) 
{
    chomp($line);
    $line = rmBlanks($line);

    if ($line =~ /^(.*)\\ *$/s)                     # if line ends with '\'
    {
        my $next = <STDIN>;
        $line = $1 . "\n" . rmBlanks($next);

        redo unless eof;
    }

    next if length($line) == 0;                     # skip empty lines
    next if $line =~ /^\/\/\/.*$/s;                 # skip lines starting with '///'

    if ($line =~ /^\/\/ (.+): (.+)$/)               # // name: info
    {
        $name = $1;
        $info = $2;
        $model = '$large';
        $profile = '$full';
        $round = '$default';
        $cnt = 0;
    }
    elsif ($line =~ /^\/\/ (.+)$/)                  # // name
    {
        $name = $1;
        $info = $1;
        $model = '$large';
        $profile = '$full';
        $round = '$default';
        $cnt = 0;
    }
    elsif ($line =~ /^\/\/-/)                       # //-...
    {
        $cnt++;                                     # skip this test but increment test index
    }
    elsif ($line =~ /^\!small *$/)                  # small memory model
    {
        $model = '$small';
    }
    elsif ($line =~ /^\!large *$/)                  # large memory model
    {
        $model = '$large';
    }
    elsif ($line =~ /^\!full *$/)                  # full profile
    {
        $profile = '$full';
    }
    elsif ($line =~ /^\!base *$/)                  # base profile
    {
        $profile = '$base';
    }
    elsif ($line =~ /^\!default *$/)               # default rounding
    {
        $profile = '$default';
    }
    elsif ($line =~ /^\!near *$/)                  # near rounding
    {
        $profile = '$near';
    }
    elsif ($line =~ /^\!zero *$/)                  # zero rounding
    {
        $profile = '$zero';
    }
    else 
    {

        if ($line =~ /^ *\[\[ *(.+) *\]\](.*)$/s)   # // [[defs]] code
        {
            $defs = cleanup($1);
            $line = cleanup($2);
        }
        else
        {
            $defs = '';
        }

        genTest($name, $info, $line);
    }

}

close $log;

exit 0;

############################################################################################################
############################################################################################################
############################################################################################################
# AUXILIARY CODE

sub rmBlanks                                        # remove starting and trailing blanks
{
    my $line = shift;
    return "" unless defined $line;

    $line =~ s/^\s*$//s;                            # remove spaces from empty line
    $line =~ s/^\s*(\S.*)$/$1/s;                    # remove starting spaces from non-empty line
    $line =~ s/^(.*\S)\s*$/$1/s;                    # remove trailing spaces from non-empty line

    return $line;
}

sub rmCRLF                                          # remove starting and trailing CRLF
{
    my $line = shift;
    $line =~ s/^\n*(.*)$/$1/s;                      # remove starting CRLF

    chomp($line);
    return $line;
}

sub cleanup                                         # remove starting and trailing blanks + CRLF (may be intermixed)
{
    my $line = shift;
    my $len = -1;

    while ($len != length($line))
    {
        $len = length($line);
        $line = rmBlanks(rmCRLF($line));
    }

    return $line;
}

sub genTest
{
    my ($name, $info, $line) = @_;
    my $nameCnt = ($cnt < 10)? "00$cnt" : ($cnt < 100)? "0$cnt" : "$cnt";

    $name =~ s/\./_/g;
    my $filename = "${name}_${model}_${nameCnt}.hsail";

    $filename !~ /\s/ or die "Invalid file name, blanks are not allowed: '$filename'";
    if (-e "$outDir/$filename")
    {
        print STDERR "File $outDir/$filename already exists\n";
        print STDERR "Check test groups named '$name' and rename duplicates\n";
        exit 1;
    }
            
    open(RES, "> $outDir/$filename") or die "Can't create $outDir/$filename: $!\n";

    print $log "$filename\n";                       # log test name

    print RES "// $info\n\n";                       # print test header

    if ($defs =~ /\$module\$/)                      # has "$module$" inside => do not emit std header
    {                                               # and replace $module$ with module directive

        $defs =~ s/ *\$module\$ */\n\n$module:$profile:$model:$round;\n\n/g;
        print RES "$defs\n\n";
    }
    elsif ($defs =~ /module/)                       # has "module" inside => do not emit std header
    {
        print RES "$defs\n\n";
    }
    else
    {
        print RES "$module:$profile:$model:$round;\n\n";
        print RES "$defs\n\n" unless !$defs;
    }

    if ($line)                                      # if test includes non-empty function-scoped code, print function header + body 
    {
        print RES "function &HsailNegativeTest()(arg_u32 \%arg)\n";
        print RES "{\n";
        print RES "    $line\n";
        print RES "};\n";
    }

    close RES;
    $cnt++;
}
    
 