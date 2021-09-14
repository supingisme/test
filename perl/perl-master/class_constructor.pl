use 5.010;use strict;use warnings;

require Animal;

my $animal = Animal->new();

say "Animal has ", $animal->{"legs"}, " leg(s)";
$animal->eat("insects", "curry", "eucalyptus");