#!/usr/bin/perl

#use strict;
#use warnings;

sub print_hash {
	my $hashref = shift;
	while ((my $key, my $value) = each %$hashref)
	{
		print "$key ==> $value\n";
	}
}

sub triple_word {
	our (@prefix, %hash);
	my $word = shift;
	
	if (@prefix == 2) {
		my $key = join " ", @prefix;

		#my $aref = $hash{$key};
		#push @$aref, $word;
		#$hash{$key} = $aref;
		$hash{$key} .= $word;

		shift @prefix;
	}
	push @prefix, $word;
}

sub triple_line {
	my @list = split " ", shift;
	foreach my $word (@list) {
		triple_word $word;
	}
}

sub read_file {
	my $file = shift;
	my $subref = shift;

	open (FILE, $file);

	while (my $line = <FILE>) {
		$subref->($line);
	}
}	

read_file shift @ARGV, \&triple_line;
print_hash \%hash;
