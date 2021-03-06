http://www.brendangregg.com/DTraceToolkit/DTraceToolkit-0.99.tar.gz

Guide - Guide to the DTraceToolkit

    How to get started, and a table of contents.

QuickStart

	1. The top most useful scripts are in this directory.
	2. Try running them with "-h". Eg, "./execsnoop -h".
	3. Read Docs/Contents for a full list of scripts.

QuickStart-by-Screenshot

	1. Look through the examples in the Examples directory until
	   you see an output you like
	2. Find the script and run it
	3. Look for its man page in Man

Not-so-QuickStart
[rongtao@localhost DTraceToolkit-0.99]$ cat Guide 
Guide - Guide to the DTraceToolkit

    How to get started, and a table of contents.

QuickStart

	1. The top most useful scripts are in this directory.
	2. Try running them with "-h". Eg, "./execsnoop -h".
	3. Read Docs/Contents for a full list of scripts.

QuickStart-by-Screenshot

	1. Look through the examples in the Examples directory until
	   you see an output you like
	2. Find the script and run it
	3. Look for its man page in Man

Not-so-QuickStart
	
	1. Welcome!
	2. Check the Table of Contents below to become famaliar with the
	   directory structure of the DTraceToolkit.
	3. See Docs/Faq for any initial questions.
	4. Read Docs/Contents for a list of scripts.
	5. Read Docs/Readme to see where scripts are documented.
	6. Check Docs/Links for further DTrace.
	7. Once famaliar with the toolkit, the following may be useful to
	   add to your shell initialisation file,
		PATH=$PATH:/opt/DTT/Bin
		MANPATH=$MANPATH:/opt/DTT/Man
	   in this case assuming the toolkit was installed in /opt/DTT.

Installation

	1. Run ./install
	   This will replace any existing version of the DTraceToolkit
	   with this one. It will prompt. Final install location is
	   printed by this install script.

Table of Contents

   DTraceToolkit-X.XX/
	Bin/			Symlinks to all the scripts
	Apps/			Application specific scripts
	Cpu/			Scripts for CPU analysis
	Code/			Example code to practise on
	Disk/			Scripts for disk I/O analysis
	Docs/			Documentation
	   Contents		Command list for the Toolkit
	   Faq			Frequently asked questions
	   Links		Further DTrace links
	   Readme		Readme for using the docs
	Examples/		Examples of command usage
	Guide			This file!
	Include/		DTrace include files
	Java/			Scripts for tracing Java
	JavaScript/		Scripts for tracing JavaScript
	Kernel/			Scripts for kernel analysis
	License			The CDDL license
	Locks/			Scripts for lock analysis
	Man/			Man pages
	   man1m/		Man pages for the Toolkit commands
	Mem/			Scripts for memory analysis
	Misc/			Misc scripts
	Net/			Scripts for network analysis
	Notes/			Notes on Toolkit commands
	Perl/			Scripts for tracing Perl
	Php/			Scripts for tracing Php
	Proc/			Scripts for process analysis
	Python/			Scripts for tracing Python
	Ruby/			Scripts for tracing Ruby
	Shell/			Scripts for tracing Shell languages
	Snippits/		Snippits of D scripting
	System/			Scripts for system analysis
	Tcl/			Scripts for tracing Tcl
	User/			Scripts for user based activity analysis
	Zones/			Scripts for analysis by zone
	Version			DTraceToolkit version
	install			Install script, use for installs only

When you type ls in the DTraceToolkit, you will be looking at the top ten 
or so most useful scripts plus the top level directories. Other scripts have
been placed in meaningful subdirectories, such as Disk, Kernel, Proc, etc.

An optional Bin directory has been provided that links to all the scripts.

The DTraceToolkit is released under the CDDL license. It's the same open
source license that OpenSolaris has been released under.

Thank you for using the DTraceToolkit!

