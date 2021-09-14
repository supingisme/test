use 5.010;use strict;use warnings;

sub subroutine {	say "universe";}

package Food::Potatoes;
sub subroutine {say "kingedward";}
subroutine();                 # "kingedward"
main::subroutine();           # "universe"
Food::Potatoes::subroutine(); # "kingedward"

require Demo::StringUtils_p;
say Demo::StringUtils_p::zombify("i want brains"); # "r wrnt brrrns"