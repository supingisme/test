#!/usr/bin/perl

use strict;
use warnings;

sub echo {
	my $p1 = shift @_;
	my $p2 = shift;
	print "$p1, $p2, @_\n";
}

echo @ARGV
