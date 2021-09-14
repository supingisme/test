use 5.010;
use strict;
use warnings;

sub contextualSubroutine {
	# Caller wants a list. Return a list
	return ("Everest", "K2", "Etna") if wantarray;

	# Caller wants a scalar. Return a scalar
	return 3;
}

my @array = contextualSubroutine();
say @array; # "EverestK2Etna"

my $scalar = contextualSubroutine();
say $scalar; # "3"
