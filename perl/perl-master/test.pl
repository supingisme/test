use 5.010;
use strict;
use warnings;

my $string1 = "Hello world";
if($string1 =~ m/(\w+)\s+(\w+)/) {
    say $1;
    say $2;
    say "success";
}

my $string2 = "colourless green ideas sleep furiously";
my @matches = $string2 =~ m/(\w+)\s+((\w+)\s+(\w+))\s+(\w+)\s+(\w+)/;

say join ", ", map { "'".$_."'" } @matches;# prints "'colourless', 'green ideas', 'green', 'ideas', 'sleep', 'furiously'"

my $string3 = "Good morning world";
$string3 =~ s/world/Vietnam/;
say $string3 ; # "Good morning Vietnam"

my $string4 = "a tonne of feathers or a tonne of bricks";
# while($string4 =~ m/(\w+)/g) {
  # print "'".$1."'";
# }
# say "";

my @matches1 = $string4 =~ m/(\w+)/g;
print join ", ", map { "'".$_."'" } @matches1;
say "";
# /g 없이 한번 실행.
$string4 =~ s/[aeiou]/r/;
print $string4; # "r tonne of feathers or a tonne of bricks"
say "";
# 다시 또 한번 실행.
$string4 =~ s/[aeiou]/r/;
print $string4; # "r trnne of feathers or a tonne of bricks"
say "";
# /g를 이용하여 나머지 모두를 바꾼다.
$string4 =~ s/[aeiou]/r/g;
print $string4, "\n"; # "r trnnr rf frrthrrs rr r trnnr rf brrcks"
say "";
say "";
say "/////////////////////////////////////////////////////////////";
say "";
say "";

require Animal;

# my $animal = {
    # "legs"   => 4,
    # "colour" => "brown",
# };                       # $animal 은 그냥 해시 참조
# say ref $animal;       # "HASH"
# bless $animal, "Animal"; # 이제 "Animal" 클래스의 객체가 되었다
# say ref $animal;       # "Animal"

my $animal = Animal->new();
say ref $animal;       # "HASH"

say "";
say "";
say "/////////////////////////////////////////////////////////////";
say "";
say "";

require Koala;

my $koala = Koala->new();

say $koala->eat("curry");
say $koala->eat("eucalyptus");


say "";
say "";
say "/////////////////////////////////////////////////////////////";
say "";
say "";



