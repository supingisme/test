#!/usr/bin/perl

sub capture_sequences {
	$line = shift;
	my $pattern = "(ftp|http)://(.*?)/(.*)";
	if ($line =~ m/$pattern/) { print "$1, $2, $3\n" }
}

capture_sequences @ARGV
