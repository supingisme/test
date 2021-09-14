use 5.010;
use strict;
use warnings;

my $rc = system "perl", "anotherscript.pl", "foo", "bar", "baz";
$rc >>= 8;
say $rc; # "37"

say "";
my $text = `perl anotherscript.pl foo bar baz`;
say $text; # "foobarbaz"
