use 5.010;use strict;use warnings;

my $string = "Good morning world";

say $string;
$string =~ s/world/Vietnam/;
say $string; # "Good morning Vietnam"

$string =~ s/(\w+)/test/;
say $string;
