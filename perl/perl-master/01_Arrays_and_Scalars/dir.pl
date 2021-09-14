#!/usr/bin/perl

sub print_file {
	my $file = shift;
	open FILE, $file;
	while (my $line = <FILE>) {
		print $line;
	}
}

sub print_dir {
	foreach my $dir (@_) {
		my @files = glob "$dir/*";
		foreach my $file (@files) {
			print_file "$file\n";
		}
	}
}

print_dir @ARGV;
