use 5.010;
use strict;
use warnings;

my @array1 = "Mendeleev"; #my @array1 = ("Mendeleev");
say @array1;

my @array2 = ("Alpha", "Beta", "Gamma", "Pie");
my $scalar2 = @array2;
say $scalar2; # "4"

my $scalar3 = ("Alpha", "Beta", "Gamma", "Pie");
say $scalar3; # "Pie"

my @array4 = ("Alpha", "Beta", "Goo");
my $scalar4 = "-X-";
say @array4;              # "AlphaBetaGoo";
say $scalar4, @array4, 98; # "-X-AlphaBetaGoo98";

