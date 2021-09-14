use 5.010;
use strict;
use warnings;

my $temperature = 20;

unless($temperature > 30) {
    say $temperature, " degrees Celsius is not very hot";
} else {
    say $temperature, " degrees Celsius is actually pretty hot";
}

say "Oh no it's too cold" unless $temperature > 15;