#!/usr/bin/perl

sub dict_line {
	our %dict;
	my $word = lc shift;
	chomp $word;
	$dict{$word}++;
}	

sub read_file {
	my $file = shift;
	my $subref = shift || \&read_line;

	open (FILE, $file);

	while (my $line = <FILE>) {
		$subref->($line);
	}
}	

sub print_hash {
	my $hashref = shift;
	while ((my $key, my $value) = each %$hashref)
	{
		print "$key ==> $value\n";
	}
}

read_file "/usr/share/dict/words", \&dict_line;
print_hash \%dict;
print "*" if !defined $dict{shift @ARGV};
