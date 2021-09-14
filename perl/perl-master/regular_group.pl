use 5.010;use strict;use warnings;

my $string = "a tonne of feathers or a tonne of bricks";
while($string =~ m/(\w+)/g) {  print "'".$1."', ";}say "";

my @matches = $string =~ m/(\w+)/g;
say join ", ", map { "'".$_."'" } @matches;

$string =~ s/[aeiou]/r/;
say $string; # "r tonne of feathers or a tonne of bricks"
$string =~ s/[aeiou]/r/;
say $string; # "r trnne of feathers or a tonne of bricks"
$string =~ s/[aeiou]/r/g;
say $string; # "r trnnr rf frrthrrs rr r trnnr rf brrcks"