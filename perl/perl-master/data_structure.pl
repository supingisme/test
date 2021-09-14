use 5.010;
use strict;
use warnings;

# #case 1
# my %owner1= ("name" => "Santa Claus",    "DOB" => "1882-12-25",);
# my %owner2= ("name" => "Mickey Mouse",    "DOB" => "1928-11-18",);
# my $owner11Ref = \%owner1;
# my $owner12Ref = \%owner2;
# my @owners1= ( $owner11Ref, $owner12Ref );
# my $owners1Ref = \@owners1;

# my %account1= (
    # "number" => "12345678",    "opened" => "2000-01-01",
    # "owners" => $owners1Ref,
# );

# #case2
# #my %owner1= ("name" => "Santa Claus",    "DOB" => "1882-12-25",);
# #my %owner2= ("name" => "Mickey Mouse",    "DOB" => "1928-11-18",);
# my @owners2 = ( \%owner1, \%owner2 );

# my %account2 = (
    # "number" => "12345678",    "opened" => "2000-01-01",
    # "owners" => \@owners2,
# );

# #case3
# # 중괄호는 익명 해시# 대괄호는 익명 배열
# my $owner31Ref = {"name" => "Santa Claus",    "DOB" => "1882-12-25",};
# my $owner32Ref = {"name" => "Mickey Mouse",    "DOB" => "1928-11-18",};
# my $owners3Ref = [ $owner31Ref, $owner32Ref ];

# my %account3 = (
    # "number" => "12345678",    "opened" => "2000-01-01",
    # "owners" => $owners3Ref,
# );

#case4
my %account4 = (
    "number" => "31415926",     "opened" => "3000-01-01",
    "owners" => [
        {"name" => "Philip Fry",        "DOB" => "1974-08-06",},
        {"name" => "Hubert Farnsworth",         "DOB" => "2841-04-09",},
    ],
);

#case1
my $owners1Ref = $account4{"owners"};
my @owners1    = @{ $owners1Ref };my $owner11Ref = $owners1[0];
my %owner11    = %{ $owner11Ref };my $owner12Ref = $owners1[1];
my %owner12    = %{ $owner12Ref };
say "Account #", $account4{"number"};
say "Opened on ", $account4{"opened"};
say "Joint owners:";
say "\t", $owner11{"name"}, " (born ", $owner11{"DOB"}, ")";
say "\t", $owner12{"name"}, " (born ", $owner12{"DOB"}, ")\n";
#case2
my @owners2 = @{ $account4{"owners"} };
my %owner21 = %{ $owners2[0] };
my %owner22 = %{ $owners2[1] };
say "Account #", $account4{"number"};
say "Opened on ", $account4{"opened"};
say "Joint owners:";
say "\t", $owner21{"name"}, " (born ", $owner21{"DOB"}, ")";
say "\t", $owner22{"name"}, " (born ", $owner22{"DOB"}, ")\n";
#case3
my $owners3Ref = $account4{"owners"};
my $owner31Ref = $owners3Ref->[0];
my $owner32Ref = $owners3Ref->[1];
say "Account #", $account4{"number"};
say "Opened on ", $account4{"opened"};
say "Joint owners:";
say "\t", $owner31Ref->{"name"}, " (born ", $owner31Ref->{"DOB"}, ")";
say "\t", $owner32Ref->{"name"}, " (born ", $owner32Ref->{"DOB"}, ")\n";
#case4
say "Account #", $account4{"number"};
say "Opened on ", $account4{"opened"};
say "Joint owners:";
say "\t", $account4{"owners"}->[0]->{"name"}, " (born ", $account4{"owners"}->[0]->{"DOB"}, ")";
say "\t", $account4{"owners"}->[1]->{"name"}, " (born ", $account4{"owners"}->[1]->{"DOB"}, ")";
