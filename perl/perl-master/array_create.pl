use 5.010;
use strict;
use warnings;

my @elements = (
	"Antimony", "Arsenic", 
	"Aluminum", "Selenium");
say @elements; 
# "AntimonyArsenicAluminumSelenium"
say "@elements";
# "Antimony Arsenic Aluminum Selenium"
say join(", ", @elements); 
# "Antimony, Arsenic, Aluminum, Selenium"

say reverse("Hello", "World");        # "WorldHello"
say reverse("HelloWorld");            # "HelloWorld"
say scalar reverse("HelloWorld");     # "dlroWolleH"
say scalar reverse("Hello", "World"); # "dlroWolleH"
say "";
my @capitals = (
	"Baton Rouge", "Indianapolis", "Columbus", 
	"Montgomery", "Helena", "Denver", "Boise");
say join ", ", map { uc $_ } @capitals;
