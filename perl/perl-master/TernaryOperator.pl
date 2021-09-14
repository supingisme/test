use 5.010;
use strict;
use warnings;

my $gain = 48;
say "You gained ", $gain, " ", ($gain == 1 ? "experience point" : "experience points"), "!";

my $eggs = 5;
say "You have ", $eggs == 0 ? "no eggs" :($eggs == 1 ? "an egg"  :	"some eggs");#()생략가능
