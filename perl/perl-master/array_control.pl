use 5.010;
use strict;
use warnings;

my @stack = ("Fred", "Eileen", "Denise", "Charlie");
say @stack; # "FredEileenDeniseCharlie"
say pop @stack; # "Charlie"
say @stack;     # "FredEileenDenise"
push @stack, "Bob", "Alice";
say @stack; # "FredEileenDeniseBobAlice"
say shift @stack; # "Fred"
say @stack;       # "EileenDeniseBobAlice"
unshift @stack, "Hank", "Grace";
say @stack; # "HankGraceEileenDeniseBobAlice"
say splice(@stack, 1, 4, "<<<", ">>>"); # "GraceEileenDeniseBob"
say @stack;                             # "Hank<<<>>>Alice"