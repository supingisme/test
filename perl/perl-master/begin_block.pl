use 5.010;use strict;use warnings;

say "This gets printed second";
BEGIN {
    say "This gets printed first";
}
say "This gets printed third";