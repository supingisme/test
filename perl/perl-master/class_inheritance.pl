use 5.010;use strict;use warnings;

require Koala;

my $koala = Koala->new();

$koala->eat("curry");
$koala->eat("eucalyptus");

say "Koala has ", $koala->{"legs"}, " leg(s)";
$koala->eat("insects", "curry", "eucalyptus");
