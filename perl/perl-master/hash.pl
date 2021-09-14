use 5.010;
use strict;
use warnings;

my %scientists = (
	"Newton"   => "Isaac",
	"Einstein" => "Albert",
	"Darwin"   => "Charles",
);

say $scientists{"Newton"};   # "Isaac"
say $scientists{"Einstein"}; # "Albert"
say $scientists{"Darwin"};   # "Charles"
say $scientists{"Dyson"};    # returns undef, prints "" and raises a warning

my @scientists = %scientists;
say "@scientists". " ";