#!/usr/bin/perl

use strict;
use warnings;

sub croak
{
	die "$0: @_: $!\n";
}

sub read_line 
{
	our %hash;
	
	my @list = split " ", shift;
	foreach my $word (@list)
	{
		$hash{$word}++;
	}
}

sub read_file 
{
	my $file = shift;
	open (FILE, $file) || croak "Couldn't open $file";

	while (my $line = <FILE>)
	{
		read_line $line;
	}
}

sub print_hash
{
	our %hash;

	my @list_keys = sort keys %hash;
	my @list_values = sort values %hash;
	print "@list_keys\n";
	print "@list_values\n";
	#while ((my $key, my $value) = each %hash)
	#{
	#	print "$key ==> $value\n";
	#}
}

read_file @ARGV;
print_hash;
