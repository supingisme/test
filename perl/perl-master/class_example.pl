use 5.010;use strict;use warnings;

require Animal_class;

my $animal = {
    "legs"   => 4,
    "colour" => "brown",
};                       # $animal 은 그냥 해시 참조
say ref $animal;       # "HASH"
bless $animal, "Animal_class"; # 이제 "Animal" 클래스의 객체가 되었다
say ref $animal;       # "Animal"

say "Animal has ", $animal->{"legs"}, " leg(s)";
$animal->eat("insects", "curry", "eucalyptus");