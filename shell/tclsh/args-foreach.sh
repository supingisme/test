#!/bin/bin/tclsh
# process command line arguments
foreach arg $argv {
    switch -glob -- $arg {
		--status  {set status_p true}
		--help*   {set help_p true}
		--switch* {set switch_p true}
    }
}

if { [llength $argv] = 0 } {
	echo "--status --help --switch"
	exit
}

if { $help_p } {
	echo "help_p"    
	exit
}

if { $status_p } {
	echo "status_p"
	exit
}

