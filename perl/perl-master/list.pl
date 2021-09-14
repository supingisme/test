use 5.010;
use strict;
use warnings;

my @array = (
	"apples",
	"bananas",
	("inner","list","several","entries",),
	"cherries",
);

say "@array"." ";

my %hash = (
	"beer" => "good",
	"bananas" => ("green"  => "wait","yellow" => "eat",),
);

say $hash{beer} . " " . $hash{bananas} . " " . $hash{wait} . " " . $hash{eat};