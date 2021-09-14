use 5.010;use strict;use warnings;

my $f = "test.txt";
my $ft = "target.txt";
open(my $fhR, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;
open(my $fhW, ">", $ft) || die "Couldn't open '".$ft."' for reading because: ".$!;

while(1) {
    my $line = readline $fhR;
    last unless defined $line;# process the line...
    chomp $line;print $line;
}say "";
open(my $fhR2, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;
while(!eof $fhR2) {
    my $line = readline $fhR2;
    chomp $line;print $line;# process $line...
}say "";
open(my $fhR3, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;
while(my $line = <$fhR3>){chomp $line;;print $line;}
say "";
open(my $fhR4, "<", $f) || die "Couldn't open '".$f."' for reading because: ".$!;
while(<$fhR4>) {print $fhW $_ . <STDIN>;}

close $fhW;close $fhR;close $fhR2;close $fhR3;close $fhR4;
