use 5.010;
use strict;
use warnings;

my $undef = undef;
say $undef; # prints the empty string "" and raises a warning

# implicit undef:
my $undef2;
say $undef2; # prints "" and raises exactly the same warning

my $num = 4040.5;
say $num; # "4040.5"

my $string = "world";
say $string; # "world"
