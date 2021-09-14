use 5.010;use strict;use warnings;

package Animal_class;

sub eat {
    # First argument is always the object to act upon.
    my $self = shift @_;

    foreach my $food ( @_ ) {
        if($self->can_eat($food)) {
            say "Eating ", $food;
        } else {
            say "Can't eat ", $food;
        }
    }
}

# Animal은 무엇이든지 먹을(eat) 수 있다고 하자.
sub can_eat {return 1;}

return 1;