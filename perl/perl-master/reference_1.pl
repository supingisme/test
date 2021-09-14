use 5.010;
use strict;
use warnings;

my $colour = "Indigo";
my $scalarRef = \$colour;

say $colour; # "Indigo"
say $scalarRef; 
say ${ $scalarRef }; # "Indigo"

say $$scalarRef; # "Indigo"
