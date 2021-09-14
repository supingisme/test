use 5.010;
use strict;
use warnings;

say left_pad1("hello", 10, "+"); # "+++++hello"
say left_pad2("hello", 10, "+"); # "+++++hello"
say left_pad3("hello", 10, "+"); # "+++++hello"
say left_pad4("hello", 10, "+"); # "+++++hello"

sub left_pad1 {
	my $oldString	= $_[0];
	my $width		= $_[1];
	my $padChar	= $_[2];
	my $newString	= ($padChar x ($width - length $oldString)) . $oldString;
	return $newString;
}

sub left_pad2 {
	my $oldString 	= shift @_;
	my $width     	= shift @_;
	my $padChar   	= shift @_;
	my $newString 	= ($padChar x ($width - length $oldString)) . $oldString;
	return $newString;
}

sub left_pad3 {
	my $oldString 	= shift;
	my $width     	= shift;
	my $padChar   	= shift;
	my $newString 	= ($padChar x ($width - length $oldString)) . $oldString;
	return $newString;
}

sub left_pad4 {
	my ($oldString, $width, $padChar) = @_;
	my $newString = ($padChar x ($width - length $oldString)) . $oldString;
	return $newString;
}

say left_pad5("oldString" => "hello", "width" => 10, "padChar" => "+");

sub left_pad5 {
	my %args = @_;
	my $newString = ($args{"padChar"} x ($args{"width"} - length $args{"oldString"})) . $args{"oldString"};
	return $newString;
}
