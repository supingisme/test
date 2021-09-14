use 5.010;
use strict;
use warnings;

say "";
say "";
say "";
my $rc = system "perl", "anotherscript.pl", "foo", "bar", "baz";
$rc >>= 8;
say $rc; # "37"

say "";
say "";
my $text = `perl anotherscript.pl foo bar baz`;
say $text; # "foobarbaz"

my $f = "test.txt";
my $ft = "target.txt";
open(my $fh, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;
open(my $fh2, ">", $ft) || die "Couldn't open '".$ft."' for reading because: ".$!;

# while(1) {
    # my $line = readline $fh;
    # last unless defined $line;# process the line...
    # chomp $line;
    # say $line;
# }

# while(!eof $fh) {
    # my $line = readline $fh;
    # print $line;# process $line...
# }

#while(my $line = <$fh>){print $line;}# process $line...
while(<$fh>) {
    # process $_...
    print $fh2 $_ . <STDIN>;
}

close $fh2;
close $fh;