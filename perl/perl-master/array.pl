use 5.010;
use strict;
use warnings;

my @array = (
	"print", "these", "strings", "out", "for", "me", # trailing comma is okay
);

say $array[0]. " " . $array[1]. " " . $array[2]. " " . $array[3]. " " . $array[4]. " " . $array[5]. " " . $array[6]; 
# returns undef, prints "" and raises a warning
say $array[-1]. " " . $array[-2]. " " . $array[-3]. " " . $array[-4]. " " . $array[-5]. " " . $array[-6]. " " . $array[-7]; 
# returns undef, prints "" and raises a warning
say "";
say $array[0]. " " . $array[1]. " " . $array[2]. " " . $array[3]. " " . $array[4]. " " . $array[5]; 
say $array[-1]. " " . $array[-2]. " " . $array[-3]. " " . $array[-4]. " " . $array[-5]. " " . $array[-6]; 
