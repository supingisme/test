use 5.010;use strict;use warnings;

package Koala;

# Animal을 상속
use parent ("Animal");

# 메서드 오버라이드
sub can_eat {
    my $self = shift @_; # 이 변수를 사용하진 않지만 받아 놓는다
    my $food = shift @_;
    return $food eq "eucalyptus";
}
return 1;