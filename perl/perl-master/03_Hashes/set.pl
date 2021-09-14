#!/usr/bin/perl

sub dict_line {
	our %dict;
	my $word = lc shift;
	chomp $word;
	$dict{$word}++;
}	

sub make_set {
	my $file = shift;
        open FILE, $file;
        while (my $line = <FILE>) {
                dict_line $line;
        }
}

make_set "/usr/share/dict/words";
while ((my $key, my $value) = each %dict)
{
	#print "$key ==> $value\n";
}

print "*" if !defined $dict{shift @ARGV};
