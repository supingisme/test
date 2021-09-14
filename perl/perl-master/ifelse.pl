use 5.010;
use strict;
use warnings;

my $word = "antidisestablishmentarianism";
my $strlen = length($word);

if($strlen >= 15) {
    say "'", $word, "' is a very long word";
} elsif(10 <= $strlen && $strlen < 15) {
    say "'", $word, "' is a medium-length word";
} else {
    say "'", $word, "' is a a short word";
}
say "'", $word, "' is actually enormous" if $strlen >= 20;
