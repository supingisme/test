use 5.010;use strict;use warnings;

my $string1 = "Hello world";

say "success" if $string1 =~ m/(\w+)\s+(\w+)/;

say $1; # "Hello"
say $2; # "world"

my $string = "colourless green ideas sleep furiously";
my @matches = $string =~ m/(\w+)\s+((\w+)\s+(\w+))\s+(\w+)\s+(\w+)/;

say join ", ", map { "'".$_."'" } @matches;
# prints "'colourless', 'green ideas', 'green', 'ideas', 'sleep', 'furiously'"