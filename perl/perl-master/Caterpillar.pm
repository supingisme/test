use 5.010;use strict;use warnings;

package Caterpillar;

# Inherit from Exporter
use parent ("Exporter");

sub crawl  { say "inch inch";   }
sub eat    { say "chomp chomp"; }
sub pupate { say "bloop bloop"; }

our @EXPORT_OK = ("crawl", "eat");

return 1;
