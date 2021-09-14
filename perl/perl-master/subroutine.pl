use 5.010;
use strict;
use warnings;

sub hyphenate {
        # 배열의 첫째 원소를 추출하고 나머지는 무시한다
        my $word = shift @_;

        # An overly clever list comprehension
        $word = join "-", map { substr $word, $_, 1 } (0 .. (length $word) - 1);
        return $word;
}
say hyphenate("exterminate"); # "e-x-t-e-r-m-i-n-a-t-e"
say hyphenate "exterminate"; # "e-x-t-e-r-m-i-n-a-t-e"
