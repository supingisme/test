use 5.010;
use strict;
use warnings;

sub reassign {
	say $_[0];
	$_[0] = 42;
}
my $x = 7;
reassign($x);
say $x; # "42"
