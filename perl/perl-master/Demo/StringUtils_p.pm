use 5.010;use strict;use warnings;

package Demo::StringUtils_p;

sub zombify {
	my $word = shift @_;
	$word =~ s/[aeiou]/r/g;
	return $word;
}
return 1;