use 5.010;
use strict;
use warnings;

print "input text = ";
my $text = <STDIN>;
chomp $text;
say STDOUT $text;

print "num = ";
my $num = <>;
chomp $num;

my @arr;
say "input the string of ". $num. " times.";
while (@arr < $num) {
    my $num = <STDIN>;
    chomp $num;
    push @arr, $num;
}
say STDOUT "@arr";
