#!/usr/bin/perl

my @list = (1, 2);
push @list, 3;
print "@list\n";

my $elt = pop @list;
print "$elt\n";
print "@list\n";
