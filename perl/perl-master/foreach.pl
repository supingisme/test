use 5.010;
use strict;
use warnings;

foreach my $string ( @array ) {
    say $string;
}

foreach my $i ( 0 .. $#array ) {
    say $i, ": ", $array[$i];
}

foreach my $key (keys %scientists) {
    say $key, ": ", $scientists{$key};
}

foreach my $key (sort keys %scientists) {
    say $key, ": ", $scientists{$key};
}

foreach ( @array ) {
    print $_." ";
}

say "";
print $_." " foreach @array;

TESTLOOP: for my $candidate ( 2 .. 100 ) {
    for my $divisor ( 2 .. sqrt $candidate ) {
        next TESTLOOP if $candidate % $divisor == 0;
    }
    print $candidate." is prime\n";
}

my @stack = ("Fred", "Eileen", "Denise", "Charlie");
say @stack; # "FredEileenDeniseCharlie"
say pop @stack; # "Charlie"
say @stack; # "FredEileenDenise"
push @stack, "Bob", "Alice";
say @stack; # "FredEileenDeniseBobAlice"
say shift @stack; # "Fred"
say @stack; # "EileenDeniseBobAlice"
unshift @stack, "Hank", "Grace";
say @stack; # "HankGraceEileenDeniseBobAlice"
say splice(@stack, 1, 3, "<<<", ">>>"); # GraceEileenDeniseBob"
say @stack; # "Hank<<<>>>Alice"

my @elements = ("Antimony", "Arsenic", "Aluminum", "Selenium");
say @elements; # "AntimonyArsenicAluminumSelenium"
say "@elements"; # "Antimony Arsenic Aluminum Selenium"
say join(", ", @elements); # "Antimony, Arsenic, Aluminum, Selenium"

say reverse("Hello", "World"); # "WorldHello"
say reverse("HelloWorld"); # "HelloWorld"
say scalar reverse("HelloWorld"); # "dlroWolleH"
say scalar reverse("Hello", "World"); # "dlroWolleH"

my @capitals = ("Baton Rouge", "Indianapolis", "Columbus", "Montgomery", "Helena", "Denber", "Boise");
print join( ", ", map { uc $_ } @capitals); # "BATON ROUGE, INDIANAPOLIS, COLUMBUS, MONTGOMERY, HELENA, DENVER, BOISE"
say "";
say join ", ", grep { length $_ > 6 } @capitals;



my @elevations = (19, 1, 2, 100, 3, 89, 100, 1056);
say join ", ", sort @elevations;# "1, 100, 100, 1056, 19, 2, 3, 98"
say join ", ", sort { $a cmp $b } @elevations;# "1, 100, 100, 1056, 19, 2, 3, 98"
say join ", ", sort { $a <=> $b } @elevations;# "1, 2, 3, 19, 98, 100, 100, 1056"


sub hyphenate {
    # 배열의 첫째 원소를 추출하고 나머지는 무시한다
    my $word = shift @_;

    # An overly clever list comprehension
    $word = join "-", map { substr $word, $_, 1 } (0 .. (length $word) - 1);
    return $word;
}

say hyphenate("exterminate"); # "e-x-t-e-r-m-i-n-a-t-e"


print left_pad("hello", 10, "+"); # "+++++hello"

# sub left_pad {
    # my $oldString = $_[0];
    # my $width     = $_[1];
    # my $padChar   = $_[2];
    # my $newString = ($padChar x ($width - length $oldString)) . $oldString;
    # return $newString;
# }

# sub left_pad {
    # my $oldString = shift;
    # my $width     = shift;
    # my $padChar   = shift;
    # my $newString = ($padChar x ($width - length $oldString)) . $oldString;
    # return $newString;
# }

sub left_pad {
    my ($oldString, $width, $padChar) = @_;
    my $newString = ($padChar x ($width - length $oldString)) . $oldString;
    return $newString;
}

sub contextualSubroutine {
    # 호출하는 측이 리스트를 요구하므로 리스트를 반환
    return ("Everest", "K2", "Etna") if wantarray;

    # 호출하는 측이 스칼라를 요구. 스칼라를 반환
    return 3;
}
say "";
my @array = contextualSubroutine();
say join ", ", @array; # "EverestK2Etna"

my $scalar = contextualSubroutine();
say $scalar; # "3"

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