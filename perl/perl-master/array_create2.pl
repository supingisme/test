use 5.010;use strict;use warnings;

my @capitals = (
	"Baton Rouge", "Indianapolis", "Columbus", 
	"Montgomery", "Helena", "Denver", "Boise");
say "1.",join ", ", grep { length $_ == 6 } @capitals;
# "Helena, Denver"
say scalar grep { $_ eq "Columbus" } @capitals; # "1"

my @elevations = (19, 1, 2, 100, 3, 98, 100, 1056);
say "2.",join ", ", sort @elevations;
# "1, 100, 100, 1056, 19, 2, 3, 98"
say "3.",join ", ", sort { $a cmp $b } @elevations;
# "1, 100, 100, 1056, 19, 2, 3, 98"
say "4.",join ", ", sort { $a <=> $b } @elevations;
# "1, 2, 3, 19, 98, 100, 100, 1056"

sub comparator {
	if ($a > $b){return -1;}
	elsif ($a == $b){return 0;}
	else {return 1;}
}
say "5.", join ", ", sort comparator @elevations;