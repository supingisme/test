#!/usr/bin/perl

sub rev {
	foreach (@_) { 
		unshift $_; 
		print "---@stack";
	}
}

my @list = (1, 2);
push @list, 3;
print "@list\n";

rev @list;
print "@list\n";
