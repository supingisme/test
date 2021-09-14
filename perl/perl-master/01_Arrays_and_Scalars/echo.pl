#!/usr/bin/perl

#use strict;
#use warnings;

#sub echo {
#	my @params = @_;
#	print "@params\n"
#}
#
#echo @ARGV

sub echo1 {
	my ($p1, $p2, @params) = @_;
	print "$p1, $p2, @params\n";
}

echo1 @ARGV
