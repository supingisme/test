#!/usr/bin/perl

use strict;
use warnings;

sub grep_pl {
	my ($pattern, @files) = @_;
	foreach my $file (@files) {
		open FILE, $file;
		while (my $line = <FILE>) {
			if ($line =~ m/$pattern/) {
				print $line;
			}
		}
	}
}

grep_pl @ARGV;
