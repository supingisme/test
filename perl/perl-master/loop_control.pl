use 5.010;
use strict;
use warnings;

CANDIDATE: foreach my $candidate ( 2 .. 50 ) {
	foreach my $divisor ( 2 .. sqrt $candidate ) {
		next CANDIDATE if $candidate % $divisor == 0;
	}
	say $candidate." is prime";
}