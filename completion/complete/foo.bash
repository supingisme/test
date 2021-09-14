#!/bin/bash

__foo()
{
	local cur=${COMP_WORDS[COMP_CWORD]}
	COMPREPLY=($(compgen -W "exec help test" -- $cur))
}

complete -F __foo foo
