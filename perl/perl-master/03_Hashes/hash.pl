#!/usr/bin/perl

my %hash;
$hash{do} = "a deer, a female deer";
$hash{re} = "a drop of golden sun";
$hash{mi} = "what it's all about";

foreach my $key (keys %hash)
{
	print "$key => $hash{$key}\n";
}

%hash1 = (
	do => "a deer, a female deer",
	re => "a drop of golden sun",
	mi => "what it’s all about",
);
while ((my $key, my $value) = each %hash1)
{
	print "$key => $value\n";
}
my @values = values %hash1;
print "@values\n";
