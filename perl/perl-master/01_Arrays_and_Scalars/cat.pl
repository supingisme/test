#!/usr/bin/perl

use strict;
use warnings;

sub print_file {
	my $file = shift;
	open FILE, $file;
	while (my $line = <FILE>) {
		print $line;
	}
}

sub print_dir {
	my $dir = shift;
	my @files = glob "$dir/*";
	foreach my $file (@files) {
		print_file $file;
	}
}

sub cat {
	foreach my $file (@_) {
		if (-d $file) {
			print_dir $file;
		}
		#else {
		#	print_file $file;
		#}
	}
}

cat @ARGV;
