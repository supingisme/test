use 5.010;
use strict;
use warnings;

my @colours = ("Red", "Orange", "Yellow", "Green", "Blue");
my $arrayRef = \@colours;

say $colours[0]; # 배열 직접 접근
say ${ $arrayRef }[0]; # 참조를 이용하여 배열에 접근
say $arrayRef->[0]; # 위와 똑같음

my %atomicWeights = ("Hydrogen" => 1.008, "Helium" => 4.003, "Manganese" => 54.94);
my $hashRef = \%atomicWeights;

say $atomicWeights{"Helium"}; # 해시 직접 접근
say ${ $hashRef }{"Helium"}; # 참조를 이용하여 해시에 접근
say $hashRef->{"Helium"}; # 위와 똑같음. 많이 사용되는 형태