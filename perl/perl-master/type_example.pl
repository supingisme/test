use 5.010;
use strict;
use warnings;

my $data = "orange";
my @data = ("purple");
my %data = ( "0" => "blue");

say $data;      # "orange"
say $data[0];   # "purple"
say $data["0"]; # "purple"
say $data{0};   # "blue"
say $data{"0"}; # "blue"