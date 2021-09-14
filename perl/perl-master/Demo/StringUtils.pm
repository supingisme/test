use 5.010;use strict;use warnings;

sub zombify {
	my $word = shift @_;
	$word =~ s/[aeiou]/r/g;
	return $word;
}
return 1;