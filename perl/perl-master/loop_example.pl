use 5.010;
use strict;
use warnings;

my @array = ("print", "these", "strings", "out", "for", "me", );# trailing comma is okay
my %scientists = ("Newton"   => "Isaac","Einstein" => "Albert","Darwin"   => "Charles",);
my $i = 0;
while($i < scalar @array) {print $i, ": ", $array[$i],", "; $i++;}say "";
my $j = 0;
until($j >= scalar @array) {print $j, ": ", $array[$j],", "; $j++;}say "";
my $k = 0;
do {print $k, ": ", $array[$k],", ";$k++;} while ($k < scalar @array);say "";
foreach my $string ( @array ) {print $string,", ";}say "";
foreach my $i ( 0 .. $#array ) {print $i, ": ", $array[$i],", ";}say "";
foreach my $key (keys %scientists) {print $key, ": ", $scientists{$key},", ";}say "";
foreach my $key (sort keys %scientists) {print $key, ": ", $scientists{$key},", ";}say "";
foreach ( @array ) {print $_,", ";}say "";
print $_ ,", " foreach @array;say "";
