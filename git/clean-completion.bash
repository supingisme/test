# bash/zsh completion support for core Git.
#
# Copyright (C) 2006,2007 Shawn O. Pearce <spearce@spearce.org>
# Conceptually based on cleancompletion (http://cleanweb.hawaga.org.uk/).
# Distributed under the GNU General Public License, version 2.0.
#
# The contained completion routines provide support for completing:
#
#    *) local and remote branch names
#    *) local and remote tag names
#    *) .clean/remotes file names
#    *) clean 'subcommands'
#    *) clean email aliases for clean-send-email
#    *) tree paths within 'ref:path/to/file' expressions
#    *) file paths within current working directory and index
#    *) common --long-options
#
# To use these routines:
#
#    1) Copy this file to somewhere (e.g. ~/.clean-completion.bash).
#    2) Add the following line to your .bashrc/.zshrc:
#        source ~/.clean-completion.bash
#    3) Consider changing your PS1 to also show the current branch,
#       see clean-prompt.sh for details.
#
# If you use complex aliases of form '!f() { ... }; f', you can use the null
# command ':' as the first command in the function body to declare the desired
# completion style.  For example '!f() { : clean commit ; ... }; f' will
# tell the completion to use commit completion.  This also works with aliases
# of form "!sh -c '...'".  For example, "!sh -c ': clean commit ; ... '".
#
# You can set the following environment variables to influence the behavior of
# the completion routines:
#
#   CLEAN_COMPLETION_CHECKOUT_NO_GUESS
#
#     When set to "1", do not include "DWIM" suggestions in clean-checkout
#     completion (e.g., completing "foo" when "origin/foo" exists).

case "$COMP_WORDBREAKS" in
*:*) : great ;;
*)   COMP_WORDBREAKS="$COMP_WORDBREAKS:"
esac

# Discovers the path to the clean repository taking any '--clean-dir=<path>' and
# '-C <path>' options into account and stores it in the $__clean_repo_path
# variable.
__clean_find_repo_path ()
{
	if [ -n "$__clean_repo_path" ]; then
		# we already know where it is
		return
	fi

	if [ -n "${__clean_C_args-}" ]; then
		__clean_repo_path="$(clean "${__clean_C_args[@]}" \
			${__clean_dir:+--clean-dir="$__clean_dir"} \
			rev-parse --absolute-clean-dir 2>/dev/null)"
	elif [ -n "${__clean_dir-}" ]; then
		test -d "$__clean_dir" &&
		__clean_repo_path="$__clean_dir"
	elif [ -n "${CLEAN_DIR-}" ]; then
		test -d "${CLEAN_DIR-}" &&
		__clean_repo_path="$CLEAN_DIR"
	elif [ -d .clean ]; then
		__clean_repo_path=.clean
	else
		__clean_repo_path="$(clean rev-parse --clean-dir 2>/dev/null)"
	fi
}

# Deprecated: use __clean_find_repo_path() and $__clean_repo_path instead
# __cleandir accepts 0 or 1 arguments (i.e., location)
# returns location of .clean repo
__cleandir ()
{
	if [ -z "${1-}" ]; then
		__clean_find_repo_path || return 1
		echo "$__clean_repo_path"
	elif [ -d "$1/.clean" ]; then
		echo "$1/.clean"
	else
		echo "$1"
	fi
}

# Runs clean with all the options given as argument, respecting any
# '--clean-dir=<path>' and '-C <path>' options present on the command line
__clean ()
{
	clean ${__clean_C_args:+"${__clean_C_args[@]}"} \
		${__clean_dir:+--clean-dir="$__clean_dir"} "$@" 2>/dev/null
}

# The following function is based on code from:
#
#   bash_completion - programmable completion functions for bash 3.2+
#
#   Copyright © 2006-2008, Ian Macdonald <ian@caliban.org>
#             © 2009-2010, Bash Completion Maintainers
#                     <bash-completion-devel@lists.alioth.debian.org>
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2, or (at your option)
#   any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, see <http://www.gnu.org/licenses/>.
#
#   The latest version of this software can be obtained here:
#
#   http://bash-completion.alioth.debian.org/
#
#   RELEASE: 2.x

# This function can be used to access a tokenized list of words
# on the command line:
#
#	__clean_reassemble_comp_words_by_ref '=:'
#	if test "${words_[cword_-1]}" = -w
#	then
#		...
#	fi
#
# The argument should be a collection of characters from the list of
# word completion separators (COMP_WORDBREAKS) to treat as ordinary
# characters.
#
# This is roughly equivalent to going back in time and setting
# COMP_WORDBREAKS to exclude those characters.  The intent is to
# make option types like --date=<type> and <rev>:<path> easy to
# recognize by treating each shell word as a single token.
#
# It is best not to set COMP_WORDBREAKS directly because the value is
# shared with other completion scripts.  By the time the completion
# function gets called, COMP_WORDS has already been populated so local
# changes to COMP_WORDBREAKS have no effect.
#
# Output: words_, cword_, cur_.

__clean_reassemble_comp_words_by_ref()
{
	local exclude i j first
	# Which word separators to exclude?
	exclude="${1//[^$COMP_WORDBREAKS]}"
	cword_=$COMP_CWORD
	if [ -z "$exclude" ]; then
		words_=("${COMP_WORDS[@]}")
		return
	fi
	# List of word completion separators has shrunk;
	# re-assemble words to complete.
	for ((i=0, j=0; i < ${#COMP_WORDS[@]}; i++, j++)); do
		# Append each nonempty word consisting of just
		# word separator characters to the current word.
		first=t
		while
			[ $i -gt 0 ] &&
			[ -n "${COMP_WORDS[$i]}" ] &&
			# word consists of excluded word separators
			[ "${COMP_WORDS[$i]//[^$exclude]}" = "${COMP_WORDS[$i]}" ]
		do
			# Attach to the previous token,
			# unless the previous token is the command name.
			if [ $j -ge 2 ] && [ -n "$first" ]; then
				((j--))
			fi
			first=
			words_[$j]=${words_[j]}${COMP_WORDS[i]}
			if [ $i = $COMP_CWORD ]; then
				cword_=$j
			fi
			if (($i < ${#COMP_WORDS[@]} - 1)); then
				((i++))
			else
				# Done.
				return
			fi
		done
		words_[$j]=${words_[j]}${COMP_WORDS[i]}
		if [ $i = $COMP_CWORD ]; then
			cword_=$j
		fi
	done
}

if ! type _get_comp_words_by_ref >/dev/null 2>&1; then
_get_comp_words_by_ref ()
{
	local exclude cur_ words_ cword_
	if [ "$1" = "-n" ]; then
		exclude=$2
		shift 2
	fi
	__clean_reassemble_comp_words_by_ref "$exclude"
	cur_=${words_[cword_]}
	while [ $# -gt 0 ]; do
		case "$1" in
		cur)
			cur=$cur_
			;;
		prev)
			prev=${words_[$cword_-1]}
			;;
		words)
			words=("${words_[@]}")
			;;
		cword)
			cword=$cword_
			;;
		esac
		shift
	done
}
fi

# Fills the COMPREPLY array with prefiltered words without any additional
# processing.
# Callers must take care of providing only words that match the current word
# to be completed and adding any prefix and/or suffix (trailing space!), if
# necessary.
# 1: List of newline-separated matching completion words, complete with
#    prefix and suffix.
__cleancomp_direct ()
{
	local IFS=$'\n'

	COMPREPLY=($1)
}

__cleancompappend ()
{
	local x i=${#COMPREPLY[@]}
	for x in $1; do
		if [[ "$x" == "$3"* ]]; then
			COMPREPLY[i++]="$2$x$4"
		fi
	done
}

__cleancompadd ()
{
	COMPREPLY=()
	__cleancompappend "$@"
}

# Generates completion reply, appending a space to possible completion words,
# if necessary.
# It accepts 1 to 4 arguments:
# 1: List of possible completion words.
# 2: A prefix to be added to each possible completion word (optional).
# 3: Generate possible completion matches for this word (optional).
# 4: A suffix to be appended to each possible completion word (optional).
__cleancomp ()
{
	local cur_="${3-$cur}"

	case "$cur_" in
	--*=)
		;;
	*)
		local c i=0 IFS=$' \t\n'
		for c in $1; do
			c="$c${4-}"
			if [[ $c == "$cur_"* ]]; then
				case $c in
				--*=*|*.) ;;
				*) c="$c " ;;
				esac
				COMPREPLY[i++]="${2-}$c"
			fi
		done
		;;
	esac
}

# Variation of __cleancomp_nl () that appends to the existing list of
# completion candidates, COMPREPLY.
__cleancomp_nl_append ()
{
	local IFS=$'\n'
	__cleancompappend "$1" "${2-}" "${3-$cur}" "${4- }"
}

# Generates completion reply from newline-separated possible completion words
# by appending a space to all of them.
# It accepts 1 to 4 arguments:
# 1: List of possible completion words, separated by a single newline.
# 2: A prefix to be added to each possible completion word (optional).
# 3: Generate possible completion matches for this word (optional).
# 4: A suffix to be appended to each possible completion word instead of
#    the default space (optional).  If specified but empty, nothing is
#    appended.
__cleancomp_nl ()
{
	COMPREPLY=()
	__cleancomp_nl_append "$@"
}

# Generates completion reply with compgen from newline-separated possible
# completion filenames.
# It accepts 1 to 3 arguments:
# 1: List of possible completion filenames, separated by a single newline.
# 2: A directory prefix to be added to each possible completion filename
#    (optional).
# 3: Generate possible completion matches for this word (optional).
__cleancomp_file ()
{
	local IFS=$'\n'

	# XXX does not work when the directory prefix contains a tilde,
	# since tilde expansion is not applied.
	# This means that COMPREPLY will be empty and Bash default
	# completion will be used.
	__cleancompadd "$1" "${2-}" "${3-$cur}" ""

	# use a hack to enable file mode in bash < 4
	compopt -o filenames +o nospace 2>/dev/null ||
	compgen -f /non-existing-dir/ > /dev/null
}

# Execute 'clean ls-files', unless the --committable option is specified, in
# which case it runs 'clean diff-index' to find out the files that can be
# committed.  It return paths relative to the directory specified in the first
# argument, and using the options specified in the second argument.
__clean_ls_files_helper ()
{
	if [ "$2" == "--committable" ]; then
		__clean -C "$1" diff-index --name-only --relative HEAD
	else
		# NOTE: $2 is not quoted in order to support multiple options
		__clean -C "$1" ls-files --exclude-standard $2
	fi
}


# __clean_index_files accepts 1 or 2 arguments:
# 1: Options to pass to ls-files (required).
# 2: A directory path (optional).
#    If provided, only files within the specified directory are listed.
#    Sub directories are never recursed.  Path must have a trailing
#    slash.
__clean_index_files ()
{
	local root="${2-.}" file

	__clean_ls_files_helper "$root" "$1" |
	while read -r file; do
		case "$file" in
		?*/*) echo "${file%%/*}" ;;
		*) echo "$file" ;;
		esac
	done | sort | uniq
}

# Lists branches from the local repository.
# 1: A prefix to be added to each listed branch (optional).
# 2: List only branches matching this word (optional; list all branches if
#    unset or empty).
# 3: A suffix to be appended to each listed branch (optional).
__clean_heads ()
{
	local pfx="${1-}" cur_="${2-}" sfx="${3-}"

	__clean for-each-ref --format="${pfx//\%/%%}%(refname:strip=2)$sfx" \
			"refs/heads/$cur_*" "refs/heads/$cur_*/**"
}

# Lists tags from the local repository.
# Accepts the same positional parameters as __clean_heads() above.
__clean_tags ()
{
	local pfx="${1-}" cur_="${2-}" sfx="${3-}"

	__clean for-each-ref --format="${pfx//\%/%%}%(refname:strip=2)$sfx" \
			"refs/tags/$cur_*" "refs/tags/$cur_*/**"
}

# Lists refs from the local (by default) or from a remote repository.
# It accepts 0, 1 or 2 arguments:
# 1: The remote to list refs from (optional; ignored, if set but empty).
#    Can be the name of a configured remote, a path, or a URL.
# 2: In addition to local refs, list unique branches from refs/remotes/ for
#    'clean checkout's tracking DWIMery (optional; ignored, if set but empty).
# 3: A prefix to be added to each listed ref (optional).
# 4: List only refs matching this word (optional; list all refs if unset or
#    empty).
# 5: A suffix to be appended to each listed ref (optional; ignored, if set
#    but empty).
#
# Use __clean_complete_refs() instead.
__clean_refs ()
{
	local i hash dir track="${2-}"
	local list_refs_from=path remote="${1-}"
	local format refs
	local pfx="${3-}" cur_="${4-$cur}" sfx="${5-}"
	local match="${4-}"
	local fer_pfx="${pfx//\%/%%}" # "escape" for-each-ref format specifiers

	__clean_find_repo_path
	dir="$__clean_repo_path"

	if [ -z "$remote" ]; then
		if [ -z "$dir" ]; then
			return
		fi
	else
		if __clean_is_configured_remote "$remote"; then
			# configured remote takes precedence over a
			# local directory with the same name
			list_refs_from=remote
		elif [ -d "$remote/.clean" ]; then
			dir="$remote/.clean"
		elif [ -d "$remote" ]; then
			dir="$remote"
		else
			list_refs_from=url
		fi
	fi

	if [ "$list_refs_from" = path ]; then
		if [[ "$cur_" == ^* ]]; then
			pfx="$pfx^"
			fer_pfx="$fer_pfx^"
			cur_=${cur_#^}
			match=${match#^}
		fi
		case "$cur_" in
		refs|refs/*)
			format="refname"
			refs=("$match*" "$match*/**")
			track=""
			;;
		*)
			for i in HEAD FETCH_HEAD ORIG_HEAD MERGE_HEAD; do
				case "$i" in
				$match*)
					if [ -e "$dir/$i" ]; then
						echo "$pfx$i$sfx"
					fi
					;;
				esac
			done
			format="refname:strip=2"
			refs=("refs/tags/$match*" "refs/tags/$match*/**"
				"refs/heads/$match*" "refs/heads/$match*/**"
				"refs/remotes/$match*" "refs/remotes/$match*/**")
			;;
		esac
		__clean_dir="$dir" __clean for-each-ref --format="$fer_pfx%($format)$sfx" \
			"${refs[@]}"
		if [ -n "$track" ]; then
			# employ the heuristic used by clean checkout
			# Try to find a remote branch that matches the completion word
			# but only output if the branch name is unique
			__clean for-each-ref --format="$fer_pfx%(refname:strip=3)$sfx" \
				--sort="refname:strip=3" \
				"refs/remotes/*/$match*" "refs/remotes/*/$match*/**" | \
			uniq -u
		fi
		return
	fi
	case "$cur_" in
	refs|refs/*)
		__clean ls-remote "$remote" "$match*" | \
		while read -r hash i; do
			case "$i" in
			*^{}) ;;
			*) echo "$pfx$i$sfx" ;;
			esac
		done
		;;
	*)
		if [ "$list_refs_from" = remote ]; then
			case "HEAD" in
			$match*)	echo "${pfx}HEAD$sfx" ;;
			esac
			__clean for-each-ref --format="$fer_pfx%(refname:strip=3)$sfx" \
				"refs/remotes/$remote/$match*" \
				"refs/remotes/$remote/$match*/**"
		else
			local query_symref
			case "HEAD" in
			$match*)	query_symref="HEAD" ;;
			esac
			__clean ls-remote "$remote" $query_symref \
				"refs/tags/$match*" "refs/heads/$match*" \
				"refs/remotes/$match*" |
			while read -r hash i; do
				case "$i" in
				*^{})	;;
				refs/*)	echo "$pfx${i#refs/*/}$sfx" ;;
				*)	echo "$pfx$i$sfx" ;;  # symbolic refs
				esac
			done
		fi
		;;
	esac
}

# Completes refs, short and long, local and remote, symbolic and pseudo.
#
# Usage: __clean_complete_refs [<option>]...
# --remote=<remote>: The remote to list refs from, can be the name of a
#                    configured remote, a path, or a URL.
# --track: List unique remote branches for 'clean checkout's tracking DWIMery.
# --pfx=<prefix>: A prefix to be added to each ref.
# --cur=<word>: The current ref to be completed.  Defaults to the current
#               word to be completed.
# --sfx=<suffix>: A suffix to be appended to each ref instead of the default
#                 space.
__clean_complete_refs ()
{
	local remote track pfx cur_="$cur" sfx=" "

	while test $# != 0; do
		case "$1" in
		--remote=*)	remote="${1##--remote=}" ;;
		--track)	track="yes" ;;
		--pfx=*)	pfx="${1##--pfx=}" ;;
		--cur=*)	cur_="${1##--cur=}" ;;
		--sfx=*)	sfx="${1##--sfx=}" ;;
		*)		return 1 ;;
		esac
		shift
	done

	__cleancomp_direct "$(__clean_refs "$remote" "$track" "$pfx" "$cur_" "$sfx")"
}

# __clean_refs2 requires 1 argument (to pass to __clean_refs)
# Deprecated: use __clean_complete_fetch_refspecs() instead.
__clean_refs2 ()
{
	local i
	for i in $(__clean_refs "$1"); do
		echo "$i:$i"
	done
}

# Completes refspecs for fetching from a remote repository.
# 1: The remote repository.
# 2: A prefix to be added to each listed refspec (optional).
# 3: The ref to be completed as a refspec instead of the current word to be
#    completed (optional)
# 4: A suffix to be appended to each listed refspec instead of the default
#    space (optional).
__clean_complete_fetch_refspecs ()
{
	local i remote="$1" pfx="${2-}" cur_="${3-$cur}" sfx="${4- }"

	__cleancomp_direct "$(
		for i in $(__clean_refs "$remote" "" "" "$cur_") ; do
			echo "$pfx$i:$i$sfx"
		done
		)"
}

# __clean_refs_remotes requires 1 argument (to pass to ls-remote)
__clean_refs_remotes ()
{
	local i hash
	__clean ls-remote "$1" 'refs/heads/*' | \
	while read -r hash i; do
		echo "$i:refs/remotes/$1/${i#refs/heads/}"
	done
}

__clean_remotes ()
{
	__clean_find_repo_path
	test -d "$__clean_repo_path/remotes" && ls -1 "$__clean_repo_path/remotes"
	__clean remote
}

# Returns true if $1 matches the name of a configured remote, false otherwise.
__clean_is_configured_remote ()
{
	local remote
	for remote in $(__clean_remotes); do
		if [ "$remote" = "$1" ]; then
			return 0
		fi
	done
	return 1
}

__clean_list_merge_strategies ()
{
	LANG=C LC_ALL=C clean merge -s help 2>&1 |
	sed -n -e '/[Aa]vailable strategies are: /,/^$/{
		s/\.$//
		s/.*://
		s/^[ 	]*//
		s/[ 	]*$//
		p
	}'
}

__clean_merge_strategies=
# 'clean merge -s help' (and thus detection of the merge strategy
# list) fails, unfortunately, if run outside of any clean working
# tree.  __clean_merge_strategies is set to the empty string in
# that case, and the detection will be repeated the next time it
# is needed.
__clean_compute_merge_strategies ()
{
	test -n "$__clean_merge_strategies" ||
	__clean_merge_strategies=$(__clean_list_merge_strategies)
}

__clean_complete_revlist_file ()
{
	local pfx ls ref cur_="$cur"
	case "$cur_" in
	*..?*:*)
		return
		;;
	?*:*)
		ref="${cur_%%:*}"
		cur_="${cur_#*:}"
		case "$cur_" in
		?*/*)
			pfx="${cur_%/*}"
			cur_="${cur_##*/}"
			ls="$ref:$pfx"
			pfx="$pfx/"
			;;
		*)
			ls="$ref"
			;;
		esac

		case "$COMP_WORDBREAKS" in
		*:*) : great ;;
		*)   pfx="$ref:$pfx" ;;
		esac

		__cleancomp_nl "$(__clean ls-tree "$ls" \
				| sed '/^100... blob /{
				           s,^.*	,,
				           s,$, ,
				       }
				       /^120000 blob /{
				           s,^.*	,,
				           s,$, ,
				       }
				       /^040000 tree /{
				           s,^.*	,,
				           s,$,/,
				       }
				       s/^.*	//')" \
			"$pfx" "$cur_" ""
		;;
	*...*)
		pfx="${cur_%...*}..."
		cur_="${cur_#*...}"
		__clean_complete_refs --pfx="$pfx" --cur="$cur_"
		;;
	*..*)
		pfx="${cur_%..*}.."
		cur_="${cur_#*..}"
		__clean_complete_refs --pfx="$pfx" --cur="$cur_"
		;;
	*)
		__clean_complete_refs
		;;
	esac
}


# __clean_complete_index_file requires 1 argument:
# 1: the options to pass to ls-file
#
# The exception is --committable, which finds the files appropriate commit.
__clean_complete_index_file ()
{
	local pfx="" cur_="$cur"

	case "$cur_" in
	?*/*)
		pfx="${cur_%/*}"
		cur_="${cur_##*/}"
		pfx="${pfx}/"
		;;
	esac

	__cleancomp_file "$(__clean_index_files "$1" ${pfx:+"$pfx"})" "$pfx" "$cur_"
}

__clean_complete_file ()
{
	__clean_complete_revlist_file
}

__clean_complete_revlist ()
{
	__clean_complete_revlist_file
}

__clean_complete_remote_or_refspec ()
{
	local cur_="$cur" cmd="${words[1]}"
	local i c=2 remote="" pfx="" lhs=1 no_complete_refspec=0
	if [ "$cmd" = "remote" ]; then
		((c++))
	fi
	while [ $c -lt $cword ]; do
		i="${words[c]}"
		case "$i" in
		--mirror) [ "$cmd" = "push" ] && no_complete_refspec=1 ;;
		-d|--delete) [ "$cmd" = "push" ] && lhs=0 ;;
		--all)
			case "$cmd" in
			push) no_complete_refspec=1 ;;
			fetch)
				return
				;;
			*) ;;
			esac
			;;
		-*) ;;
		*) remote="$i"; break ;;
		esac
		((c++))
	done
	if [ -z "$remote" ]; then
		__cleancomp_nl "$(__clean_remotes)"
		return
	fi
	if [ $no_complete_refspec = 1 ]; then
		return
	fi
	[ "$remote" = "." ] && remote=
	case "$cur_" in
	*:*)
		case "$COMP_WORDBREAKS" in
		*:*) : great ;;
		*)   pfx="${cur_%%:*}:" ;;
		esac
		cur_="${cur_#*:}"
		lhs=0
		;;
	+*)
		pfx="+"
		cur_="${cur_#+}"
		;;
	esac
	case "$cmd" in
	fetch)
		if [ $lhs = 1 ]; then
			__clean_complete_fetch_refspecs "$remote" "$pfx" "$cur_"
		else
			__clean_complete_refs --pfx="$pfx" --cur="$cur_"
		fi
		;;
	pull|remote)
		if [ $lhs = 1 ]; then
			__clean_complete_refs --remote="$remote" --pfx="$pfx" --cur="$cur_"
		else
			__clean_complete_refs --pfx="$pfx" --cur="$cur_"
		fi
		;;
	push)
		if [ $lhs = 1 ]; then
			__clean_complete_refs --pfx="$pfx" --cur="$cur_"
		else
			__clean_complete_refs --remote="$remote" --pfx="$pfx" --cur="$cur_"
		fi
		;;
	esac
}

__clean_complete_strategy ()
{
	__clean_compute_merge_strategies
	case "$prev" in
	-s|--strategy)
		__cleancomp "$__clean_merge_strategies"
		return 0
	esac
	case "$cur" in
	--strategy=*)
		__cleancomp "$__clean_merge_strategies" "" "${cur##--strategy=}"
		return 0
		;;
	esac
	return 1
}

__clean_commands () {
	if test -n "${CLEAN_TESTING_COMMAND_COMPLETION:-}"
	then
		printf "%s" "${CLEAN_TESTING_COMMAND_COMPLETION}"
	else
		clean help -a|egrep '^  [a-zA-Z0-9]'
	fi
}

__clean_list_all_commands ()
{
	local i IFS=" "$'\n'
	for i in $(__clean_commands)
	do
		case $i in
		*--*)             : helper pattern;;
		*) echo $i;;
		esac
	done
}

__clean_all_commands=
__clean_compute_all_commands ()
{
	test -n "$__clean_all_commands" ||
	__clean_all_commands=$(__clean_list_all_commands)
}

__clean_list_porcelain_commands ()
{
	local i IFS=" "$'\n'
	__clean_compute_all_commands
	for i in $__clean_all_commands
	do
		case $i in
		*--*)             : helper pattern;;
		applymbox)        : ask cleantus;;
		applypatch)       : ask cleantus;;
		archimport)       : import;;
		cat-file)         : plumbing;;
		check-attr)       : plumbing;;
		check-ignore)     : plumbing;;
		check-mailmap)    : plumbing;;
		check-ref-format) : plumbing;;
		checkout-index)   : plumbing;;
		column)           : internal helper;;
		commit-tree)      : plumbing;;
		count-objects)    : infrequent;;
		credential)       : credentials;;
		credential-*)     : credentials helper;;
		cvsexportcommit)  : export;;
		cvsimport)        : import;;
		cvsserver)        : daemon;;
		daemon)           : daemon;;
		diff-files)       : plumbing;;
		diff-index)       : plumbing;;
		diff-tree)        : plumbing;;
		fast-import)      : import;;
		fast-export)      : export;;
		fsck-objects)     : plumbing;;
		fetch-pack)       : plumbing;;
		fmt-merge-msg)    : plumbing;;
		for-each-ref)     : plumbing;;
		hash-object)      : plumbing;;
		http-*)           : transport;;
		index-pack)       : plumbing;;
		init-db)          : deprecated;;
		local-fetch)      : plumbing;;
		ls-files)         : plumbing;;
		ls-remote)        : plumbing;;
		ls-tree)          : plumbing;;
		mailinfo)         : plumbing;;
		mailsplit)        : plumbing;;
		merge-*)          : plumbing;;
		mktree)           : plumbing;;
		mktag)            : plumbing;;
		pack-objects)     : plumbing;;
		pack-redundant)   : plumbing;;
		pack-refs)        : plumbing;;
		parse-remote)     : plumbing;;
		patch-id)         : plumbing;;
		prune)            : plumbing;;
		prune-packed)     : plumbing;;
		quiltimport)      : import;;
		read-tree)        : plumbing;;
		receive-pack)     : plumbing;;
		remote-*)         : transport;;
		rerere)           : plumbing;;
		rev-list)         : plumbing;;
		rev-parse)        : plumbing;;
		runstatus)        : plumbing;;
		sh-setup)         : internal;;
		shell)            : daemon;;
		show-ref)         : plumbing;;
		send-pack)        : plumbing;;
		show-index)       : plumbing;;
		ssh-*)            : transport;;
		stripspace)       : plumbing;;
		symbolic-ref)     : plumbing;;
		unpack-file)      : plumbing;;
		unpack-objects)   : plumbing;;
		update-index)     : plumbing;;
		update-ref)       : plumbing;;
		update-server-info) : daemon;;
		upload-archive)   : plumbing;;
		upload-pack)      : plumbing;;
		write-tree)       : plumbing;;
		var)              : infrequent;;
		verify-pack)      : infrequent;;
		verify-tag)       : plumbing;;
		*) echo $i;;
		esac
	done
}

__clean_porcelain_commands=
__clean_compute_porcelain_commands ()
{
	test -n "$__clean_porcelain_commands" ||
	__clean_porcelain_commands=$(__clean_list_porcelain_commands)
}

# Lists all set config variables starting with the given section prefix,
# with the prefix removed.
__clean_get_config_variables ()
{
	local section="$1" i IFS=$'\n'
	for i in $(__clean config --name-only --get-regexp "^$section\..*"); do
		echo "${i#$section.}"
	done
}

__clean_pretty_aliases ()
{
	__clean_get_config_variables "pretty"
}

__clean_aliases ()
{
	__clean_get_config_variables "alias"
}

# __clean_aliased_command requires 1 argument
__clean_aliased_command ()
{
	local word cmdline=$(__clean config --get "alias.$1")
	for word in $cmdline; do
		case "$word" in
		\!cleank|cleank)
			echo "cleank"
			return
			;;
		\!*)	: shell command alias ;;
		-*)	: option ;;
		*=*)	: setting env ;;
		clean)	: clean itself ;;
		\(\))   : skip parens of shell function definition ;;
		{)	: skip start of shell helper function ;;
		:)	: skip null command ;;
		\'*)	: skip opening quote after sh -c ;;
		*)
			echo "$word"
			return
		esac
	done
}

# __clean_find_on_cmdline requires 1 argument
__clean_find_on_cmdline ()
{
	local word subcommand c=1
	while [ $c -lt $cword ]; do
		word="${words[c]}"
		for subcommand in $1; do
			if [ "$subcommand" = "$word" ]; then
				echo "$subcommand"
				return
			fi
		done
		((c++))
	done
}

# Echo the value of an option set on the command line or config
#
# $1: short option name
# $2: long option name including =
# $3: list of possible values
# $4: config string (optional)
#
# example:
# result="$(__clean_get_option_value "-d" "--do-something=" \
#     "yes no" "core.doSomething")"
#
# result is then either empty (no option set) or "yes" or "no"
#
# __clean_get_option_value requires 3 arguments
__clean_get_option_value ()
{
	local c short_opt long_opt val
	local result= values config_key word

	short_opt="$1"
	long_opt="$2"
	values="$3"
	config_key="$4"

	((c = $cword - 1))
	while [ $c -ge 0 ]; do
		word="${words[c]}"
		for val in $values; do
			if [ "$short_opt$val" = "$word" ] ||
			   [ "$long_opt$val"  = "$word" ]; then
				result="$val"
				break 2
			fi
		done
		((c--))
	done

	if [ -n "$config_key" ] && [ -z "$result" ]; then
		result="$(__clean config "$config_key")"
	fi

	echo "$result"
}

__clean_has_doubledash ()
{
	local c=1
	while [ $c -lt $cword ]; do
		if [ "--" = "${words[c]}" ]; then
			return 0
		fi
		((c++))
	done
	return 1
}

# Try to count non option arguments passed on the command line for the
# specified clean command.
# When options are used, it is necessary to use the special -- option to
# tell the implementation were non option arguments begin.
# XXX this can not be improved, since options can appear everywhere, as
# an example:
#	clean mv x -n y
#
# __clean_count_arguments requires 1 argument: the clean command executed.
__clean_count_arguments ()
{
	local word i c=0

	# Skip "clean" (first argument)
	for ((i=1; i < ${#words[@]}; i++)); do
		word="${words[i]}"

		case "$word" in
			--)
				# Good; we can assume that the following are only non
				# option arguments.
				((c = 0))
				;;
			"$1")
				# Skip the specified clean command and discard clean
				# main options
				((c = 0))
				;;
			?*)
				((c++))
				;;
		esac
	done

	printf "%d" $c
}

__clean_whitespacelist="nowarn warn error error-all fix"

_clean_am ()
{
	__clean_find_repo_path
	if [ -d "$__clean_repo_path"/rebase-apply ]; then
		__cleancomp "--skip --continue --resolved --abort"
		return
	fi
	case "$cur" in
	--whitespace=*)
		__cleancomp "$__clean_whitespacelist" "" "${cur##--whitespace=}"
		return
		;;
	--*)
		__cleancomp "
			--3way --committer-date-is-author-date --ignore-date
			--ignore-whitespace --ignore-space-change
			--interactive --keep --no-utf8 --signoff --utf8
			--whitespace= --scissors
			"
		return
	esac
}

_clean_apply ()
{
	case "$cur" in
	--whitespace=*)
		__cleancomp "$__clean_whitespacelist" "" "${cur##--whitespace=}"
		return
		;;
	--*)
		__cleancomp "
			--stat --numstat --summary --check --index
			--cached --index-info --reverse --reject --unidiff-zero
			--apply --no-add --exclude=
			--ignore-whitespace --ignore-space-change
			--whitespace= --inaccurate-eof --verbose
			--recount --directory=
			"
		return
	esac
}

_clean_add ()
{
	case "$cur" in
	--*)
		__cleancomp "
			--interactive --refresh --patch --update --dry-run
			--ignore-errors --intent-to-add --force --edit --chmod=
			"
		return
	esac

	local complete_opt="--others --modified --directory --no-empty-directory"
	if test -n "$(__clean_find_on_cmdline "-u --update")"
	then
		complete_opt="--modified"
	fi
	__clean_complete_index_file "$complete_opt"
}

_clean_archive ()
{
	case "$cur" in
	--format=*)
		__cleancomp "$(clean archive --list)" "" "${cur##--format=}"
		return
		;;
	--remote=*)
		__cleancomp_nl "$(__clean_remotes)" "" "${cur##--remote=}"
		return
		;;
	--*)
		__cleancomp "
			--format= --list --verbose
			--prefix= --remote= --exec= --output
			"
		return
		;;
	esac
	__clean_complete_file
}

_clean_bisect ()
{
	__clean_has_doubledash && return

	local subcommands="start bad good skip reset visualize replay log run"
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"
	if [ -z "$subcommand" ]; then
		__clean_find_repo_path
		if [ -f "$__clean_repo_path"/BISECT_START ]; then
			__cleancomp "$subcommands"
		else
			__cleancomp "replay start"
		fi
		return
	fi

	case "$subcommand" in
	bad|good|reset|skip|start)
		__clean_complete_refs
		;;
	*)
		;;
	esac
}

_clean_branch ()
{
	local i c=1 only_local_ref="n" has_r="n"

	while [ $c -lt $cword ]; do
		i="${words[c]}"
		case "$i" in
		-d|--delete|-m|--move)	only_local_ref="y" ;;
		-r|--remotes)		has_r="y" ;;
		esac
		((c++))
	done

	case "$cur" in
	--set-upstream-to=*)
		__clean_complete_refs --cur="${cur##--set-upstream-to=}"
		;;
	--*)
		__cleancomp "
			--color --no-color --verbose --abbrev= --no-abbrev
			--track --no-track --contains --no-contains --merged --no-merged
			--set-upstream-to= --edit-description --list
			--unset-upstream --delete --move --copy --remotes
			--column --no-column --sort= --points-at
			"
		;;
	*)
		if [ $only_local_ref = "y" -a $has_r = "n" ]; then
			__cleancomp_direct "$(__clean_heads "" "$cur" " ")"
		else
			__clean_complete_refs
		fi
		;;
	esac
}

_clean_bundle ()
{
	local cmd="${words[2]}"
	case "$cword" in
	2)
		__cleancomp "create list-heads verify unbundle"
		;;
	3)
		# looking for a file
		;;
	*)
		case "$cmd" in
			create)
				__clean_complete_revlist
			;;
		esac
		;;
	esac
}

_clean_checkout ()
{
	__clean_has_doubledash && return

	case "$cur" in
	--conflict=*)
		__cleancomp "diff3 merge" "" "${cur##--conflict=}"
		;;
	--*)
		__cleancomp "
			--quiet --ours --theirs --track --no-track --merge
			--conflict= --orphan --patch --detach --ignore-skip-worktree-bits
			--recurse-submodules --no-recurse-submodules
			"
		;;
	*)
		# check if --track, --no-track, or --no-guess was specified
		# if so, disable DWIM mode
		local flags="--track --no-track --no-guess" track_opt="--track"
		if [ "$CLEAN_COMPLETION_CHECKOUT_NO_GUESS" = "1" ] ||
		   [ -n "$(__clean_find_on_cmdline "$flags")" ]; then
			track_opt=''
		fi
		__clean_complete_refs $track_opt
		;;
	esac
}

_clean_cherry ()
{
	__clean_complete_refs
}

_clean_cherry_pick ()
{
	__clean_find_repo_path
	if [ -f "$__clean_repo_path"/CHERRY_PICK_HEAD ]; then
		__cleancomp "--continue --quit --abort"
		return
	fi
	case "$cur" in
	--*)
		__cleancomp "--edit --no-commit --signoff --strategy= --mainline"
		;;
	*)
		__clean_complete_refs
		;;
	esac
}

_clean_clean ()
{
	case "$cur" in
	--*)
		__cleancomp "--dry-run --quiet"
		return
		;;
	esac

	# XXX should we check for -x option ?
	__clean_complete_index_file "--others --directory"
}

_clean_clone ()
{
	case "$cur" in
	--*)
		__cleancomp "
			--local
			--no-hardlinks
			--shared
			--reference
			--quiet
			--no-checkout
			--bare
			--mirror
			--origin
			--upload-pack
			--template=
			--depth
			--single-branch
			--no-tags
			--branch
			--recurse-submodules
			--no-single-branch
			--shallow-submodules
			"
		return
		;;
	esac
}

__clean_untracked_file_modes="all no normal"

_clean_commit ()
{
	case "$prev" in
	-c|-C)
		__clean_complete_refs
		return
		;;
	esac

	case "$cur" in
	--cleanup=*)
		__cleancomp "default scissors strip verbatim whitespace
			" "" "${cur##--cleanup=}"
		return
		;;
	--reuse-message=*|--reedit-message=*|\
	--fixup=*|--squash=*)
		__clean_complete_refs --cur="${cur#*=}"
		return
		;;
	--untracked-files=*)
		__cleancomp "$__clean_untracked_file_modes" "" "${cur##--untracked-files=}"
		return
		;;
	--*)
		__cleancomp "
			--all --author= --signoff --verify --no-verify
			--edit --no-edit
			--amend --include --only --interactive
			--dry-run --reuse-message= --reedit-message=
			--reset-author --file= --message= --template=
			--cleanup= --untracked-files --untracked-files=
			--verbose --quiet --fixup= --squash=
			--patch --short --date --allow-empty
			"
		return
	esac

	if __clean rev-parse --verify --quiet HEAD >/dev/null; then
		__clean_complete_index_file "--committable"
	else
		# This is the first commit
		__clean_complete_index_file "--cached"
	fi
}

_clean_describe ()
{
	case "$cur" in
	--*)
		__cleancomp "
			--all --tags --contains --abbrev= --candidates=
			--exact-match --debug --long --match --always --first-parent
			--exclude --dirty --broken
			"
		return
	esac
	__clean_complete_refs
}

__clean_diff_algorithms="myers minimal patience histogram"

__clean_diff_submodule_formats="diff log short"

__clean_diff_common_options="--stat --numstat --shortstat --summary
			--patch-with-stat --name-only --name-status --color
			--no-color --color-words --no-renames --check
			--full-index --binary --abbrev --diff-filter=
			--find-copies-harder --ignore-cr-at-eol
			--text --ignore-space-at-eol --ignore-space-change
			--ignore-all-space --ignore-blank-lines --exit-code
			--quiet --ext-diff --no-ext-diff
			--no-prefix --src-prefix= --dst-prefix=
			--inter-hunk-context=
			--patience --histogram --minimal
			--raw --word-diff --word-diff-regex=
			--dirstat --dirstat= --dirstat-by-file
			--dirstat-by-file= --cumulative
			--diff-algorithm=
			--submodule --submodule=
"

_clean_diff ()
{
	__clean_has_doubledash && return

	case "$cur" in
	--diff-algorithm=*)
		__cleancomp "$__clean_diff_algorithms" "" "${cur##--diff-algorithm=}"
		return
		;;
	--submodule=*)
		__cleancomp "$__clean_diff_submodule_formats" "" "${cur##--submodule=}"
		return
		;;
	--*)
		__cleancomp "--cached --staged --pickaxe-all --pickaxe-regex
			--base --ours --theirs --no-index
			$__clean_diff_common_options
			"
		return
		;;
	esac
	__clean_complete_revlist_file
}

__clean_mergetools_common="diffuse diffmerge ecmerge emerge kdiff3 meld opendiff
			tkdiff vimdiff gvimdiff xxdiff araxis p4merge bc codecompare
"

_clean_difftool ()
{
	__clean_has_doubledash && return

	case "$cur" in
	--tool=*)
		__cleancomp "$__clean_mergetools_common kompare" "" "${cur##--tool=}"
		return
		;;
	--*)
		__cleancomp "--cached --staged --pickaxe-all --pickaxe-regex
			--base --ours --theirs
			--no-renames --diff-filter= --find-copies-harder
			--relative --ignore-submodules
			--tool="
		return
		;;
	esac
	__clean_complete_revlist_file
}

__clean_fetch_recurse_submodules="yes on-demand no"

__clean_fetch_options="
	--quiet --verbose --append --upload-pack --force --keep --depth=
	--tags --no-tags --all --prune --dry-run --recurse-submodules=
	--unshallow --update-shallow
"

_clean_fetch ()
{
	case "$cur" in
	--recurse-submodules=*)
		__cleancomp "$__clean_fetch_recurse_submodules" "" "${cur##--recurse-submodules=}"
		return
		;;
	--*)
		__cleancomp "$__clean_fetch_options"
		return
		;;
	esac
	__clean_complete_remote_or_refspec
}

__clean_format_patch_options="
	--stdout --attach --no-attach --thread --thread= --no-thread
	--numbered --start-number --numbered-files --keep-subject --signoff
	--signature --no-signature --in-reply-to= --cc= --full-index --binary
	--not --all --cover-letter --no-prefix --src-prefix= --dst-prefix=
	--inline --suffix= --ignore-if-in-upstream --subject-prefix=
	--output-directory --reroll-count --to= --quiet --notes
"

_clean_format_patch ()
{
	case "$cur" in
	--thread=*)
		__cleancomp "
			deep shallow
			" "" "${cur##--thread=}"
		return
		;;
	--*)
		__cleancomp "$__clean_format_patch_options"
		return
		;;
	esac
	__clean_complete_revlist
}

_clean_fsck ()
{
	case "$cur" in
	--*)
		__cleancomp "
			--tags --root --unreachable --cache --no-reflogs --full
			--strict --verbose --lost-found --name-objects
			"
		return
		;;
	esac
}

_clean_gc ()
{
	case "$cur" in
	--*)
		__cleancomp "--prune --aggressive"
		return
		;;
	esac
}

_clean_cleank ()
{
	_cleank
}

# Lists matching symbol names from a tag (as in ctags) file.
# 1: List symbol names matching this word.
# 2: The tag file to list symbol names from.
# 3: A prefix to be added to each listed symbol name (optional).
# 4: A suffix to be appended to each listed symbol name (optional).
__clean_match_ctag () {
	awk -v pfx="${3-}" -v sfx="${4-}" "
		/^${1//\//\\/}/ { print pfx \$1 sfx }
		" "$2"
}

# Complete symbol names from a tag file.
# Usage: __clean_complete_symbol [<option>]...
# --tags=<file>: The tag file to list symbol names from instead of the
#                default "tags".
# --pfx=<prefix>: A prefix to be added to each symbol name.
# --cur=<word>: The current symbol name to be completed.  Defaults to
#               the current word to be completed.
# --sfx=<suffix>: A suffix to be appended to each symbol name instead
#                 of the default space.
__clean_complete_symbol () {
	local tags=tags pfx="" cur_="${cur-}" sfx=" "

	while test $# != 0; do
		case "$1" in
		--tags=*)	tags="${1##--tags=}" ;;
		--pfx=*)	pfx="${1##--pfx=}" ;;
		--cur=*)	cur_="${1##--cur=}" ;;
		--sfx=*)	sfx="${1##--sfx=}" ;;
		*)		return 1 ;;
		esac
		shift
	done

	if test -r "$tags"; then
		__cleancomp_direct "$(__clean_match_ctag "$cur_" "$tags" "$pfx" "$sfx")"
	fi
}

_clean_grep ()
{
	__clean_has_doubledash && return

	case "$cur" in
	--*)
		__cleancomp "
			--cached
			--text --ignore-case --word-regexp --invert-match
			--full-name --line-number
			--extended-regexp --basic-regexp --fixed-strings
			--perl-regexp
			--threads
			--files-with-matches --name-only
			--files-without-match
			--max-depth
			--count
			--and --or --not --all-match
			--break --heading --show-function --function-context
			--untracked --no-index
			"
		return
		;;
	esac

	case "$cword,$prev" in
	2,*|*,-*)
		__clean_complete_symbol && return
		;;
	esac

	__clean_complete_refs
}

_clean_help ()
{
	case "$cur" in
	--*)
		__cleancomp "--all --guides --info --man --web"
		return
		;;
	esac
	__clean_compute_all_commands
	__cleancomp "$__clean_all_commands $(__clean_aliases)
		attributes cli core-tutorial cvs-migration
		diffcore everyday cleank glossary hooks ignore modules
		namespaces repository-layout revisions tutorial tutorial-2
		workflows
		"
}

_clean_init ()
{
	case "$cur" in
	--shared=*)
		__cleancomp "
			false true umask group all world everybody
			" "" "${cur##--shared=}"
		return
		;;
	--*)
		__cleancomp "--quiet --bare --template= --shared --shared="
		return
		;;
	esac
}

_clean_ls_files ()
{
	case "$cur" in
	--*)
		__cleancomp "--cached --deleted --modified --others --ignored
			--stage --directory --no-empty-directory --unmerged
			--killed --exclude= --exclude-from=
			--exclude-per-directory= --exclude-standard
			--error-unmatch --with-tree= --full-name
			--abbrev --ignored --exclude-per-directory
			"
		return
		;;
	esac

	# XXX ignore options like --modified and always suggest all cached
	# files.
	__clean_complete_index_file "--cached"
}

_clean_ls_remote ()
{
	case "$cur" in
	--*)
		__cleancomp "--heads --tags --refs --get-url --symref"
		return
		;;
	esac
	__cleancomp_nl "$(__clean_remotes)"
}

_clean_ls_tree ()
{
	__clean_complete_file
}

# Options that go well for log, shortlog and cleank
__clean_log_common_options="
	--not --all
	--branches --tags --remotes
	--first-parent --merges --no-merges
	--max-count=
	--max-age= --since= --after=
	--min-age= --until= --before=
	--min-parents= --max-parents=
	--no-min-parents --no-max-parents
"
# Options that go well for log and cleank (not shortlog)
__clean_log_cleank_options="
	--dense --sparse --full-history
	--simplify-merges --simplify-by-decoration
	--left-right --notes --no-notes
"
# Options that go well for log and shortlog (not cleank)
__clean_log_shortlog_options="
	--author= --committer= --grep=
	--all-match --invert-grep
"

__clean_log_pretty_formats="oneline short medium full fuller email raw format:"
__clean_log_date_formats="relative iso8601 rfc2822 short local default raw"

_clean_log ()
{
	__clean_has_doubledash && return
	__clean_find_repo_path

	local merge=""
	if [ -f "$__clean_repo_path/MERGE_HEAD" ]; then
		merge="--merge"
	fi
	case "$prev,$cur" in
	-L,:*:*)
		return	# fall back to Bash filename completion
		;;
	-L,:*)
		__clean_complete_symbol --cur="${cur#:}" --sfx=":"
		return
		;;
	-G,*|-S,*)
		__clean_complete_symbol
		return
		;;
	esac
	case "$cur" in
	--pretty=*|--format=*)
		__cleancomp "$__clean_log_pretty_formats $(__clean_pretty_aliases)
			" "" "${cur#*=}"
		return
		;;
	--date=*)
		__cleancomp "$__clean_log_date_formats" "" "${cur##--date=}"
		return
		;;
	--decorate=*)
		__cleancomp "full short no" "" "${cur##--decorate=}"
		return
		;;
	--diff-algorithm=*)
		__cleancomp "$__clean_diff_algorithms" "" "${cur##--diff-algorithm=}"
		return
		;;
	--submodule=*)
		__cleancomp "$__clean_diff_submodule_formats" "" "${cur##--submodule=}"
		return
		;;
	--*)
		__cleancomp "
			$__clean_log_common_options
			$__clean_log_shortlog_options
			$__clean_log_cleank_options
			--root --topo-order --date-order --reverse
			--follow --full-diff
			--abbrev-commit --abbrev=
			--relative-date --date=
			--pretty= --format= --oneline
			--show-signature
			--cherry-mark
			--cherry-pick
			--graph
			--decorate --decorate=
			--walk-reflogs
			--parents --children
			$merge
			$__clean_diff_common_options
			--pickaxe-all --pickaxe-regex
			"
		return
		;;
	-L:*:*)
		return	# fall back to Bash filename completion
		;;
	-L:*)
		__clean_complete_symbol --cur="${cur#-L:}" --sfx=":"
		return
		;;
	-G*)
		__clean_complete_symbol --pfx="-G" --cur="${cur#-G}"
		return
		;;
	-S*)
		__clean_complete_symbol --pfx="-S" --cur="${cur#-S}"
		return
		;;
	esac
	__clean_complete_revlist
}

# Common merge options shared by clean-merge(1) and clean-pull(1).
__clean_merge_options="
	--no-commit --no-stat --log --no-log --squash --strategy
	--commit --stat --no-squash --ff --no-ff --ff-only --edit --no-edit
	--verify-signatures --no-verify-signatures --gpg-sign
	--quiet --verbose --progress --no-progress
"

_clean_merge ()
{
	__clean_complete_strategy && return

	case "$cur" in
	--*)
		__cleancomp "$__clean_merge_options
			--rerere-autoupdate --no-rerere-autoupdate --abort --continue"
		return
	esac
	__clean_complete_refs
}

_clean_mergetool ()
{
	case "$cur" in
	--tool=*)
		__cleancomp "$__clean_mergetools_common tortoisemerge" "" "${cur##--tool=}"
		return
		;;
	--*)
		__cleancomp "--tool= --prompt --no-prompt"
		return
		;;
	esac
}

_clean_merge_base ()
{
	case "$cur" in
	--*)
		__cleancomp "--octopus --independent --is-ancestor --fork-point"
		return
		;;
	esac
	__clean_complete_refs
}

_clean_mv ()
{
	case "$cur" in
	--*)
		__cleancomp "--dry-run"
		return
		;;
	esac

	if [ $(__clean_count_arguments "mv") -gt 0 ]; then
		# We need to show both cached and untracked files (including
		# empty directories) since this may not be the last argument.
		__clean_complete_index_file "--cached --others --directory"
	else
		__clean_complete_index_file "--cached"
	fi
}

_clean_name_rev ()
{
	__cleancomp "--tags --all --stdin"
}

_clean_notes ()
{
	local subcommands='add append copy edit list prune remove show'
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"

	case "$subcommand,$cur" in
	,--*)
		__cleancomp '--ref'
		;;
	,*)
		case "$prev" in
		--ref)
			__clean_complete_refs
			;;
		*)
			__cleancomp "$subcommands --ref"
			;;
		esac
		;;
	add,--reuse-message=*|append,--reuse-message=*|\
	add,--reedit-message=*|append,--reedit-message=*)
		__clean_complete_refs --cur="${cur#*=}"
		;;
	add,--*|append,--*)
		__cleancomp '--file= --message= --reedit-message=
				--reuse-message='
		;;
	copy,--*)
		__cleancomp '--stdin'
		;;
	prune,--*)
		__cleancomp '--dry-run --verbose'
		;;
	prune,*)
		;;
	*)
		case "$prev" in
		-m|-F)
			;;
		*)
			__clean_complete_refs
			;;
		esac
		;;
	esac
}

_clean_pull ()
{
	__clean_complete_strategy && return

	case "$cur" in
	--recurse-submodules=*)
		__cleancomp "$__clean_fetch_recurse_submodules" "" "${cur##--recurse-submodules=}"
		return
		;;
	--*)
		__cleancomp "
			--rebase --no-rebase
			--autostash --no-autostash
			$__clean_merge_options
			$__clean_fetch_options
		"
		return
		;;
	esac
	__clean_complete_remote_or_refspec
}

__clean_push_recurse_submodules="check on-demand only"

__clean_complete_force_with_lease ()
{
	local cur_=$1

	case "$cur_" in
	--*=)
		;;
	*:*)
		__clean_complete_refs --cur="${cur_#*:}"
		;;
	*)
		__clean_complete_refs --cur="$cur_"
		;;
	esac
}

_clean_push ()
{
	case "$prev" in
	--repo)
		__cleancomp_nl "$(__clean_remotes)"
		return
		;;
	--recurse-submodules)
		__cleancomp "$__clean_push_recurse_submodules"
		return
		;;
	esac
	case "$cur" in
	--repo=*)
		__cleancomp_nl "$(__clean_remotes)" "" "${cur##--repo=}"
		return
		;;
	--recurse-submodules=*)
		__cleancomp "$__clean_push_recurse_submodules" "" "${cur##--recurse-submodules=}"
		return
		;;
	--force-with-lease=*)
		__clean_complete_force_with_lease "${cur##--force-with-lease=}"
		return
		;;
	--*)
		__cleancomp "
			--all --mirror --tags --dry-run --force --verbose
			--quiet --prune --delete --follow-tags
			--receive-pack= --repo= --set-upstream
			--force-with-lease --force-with-lease= --recurse-submodules=
		"
		return
		;;
	esac
	__clean_complete_remote_or_refspec
}

_clean_rebase ()
{
	__clean_find_repo_path
	if [ -f "$__clean_repo_path"/rebase-merge/interactive ]; then
		__cleancomp "--continue --skip --abort --quit --edit-todo"
		return
	elif [ -d "$__clean_repo_path"/rebase-apply ] || \
	     [ -d "$__clean_repo_path"/rebase-merge ]; then
		__cleancomp "--continue --skip --abort --quit"
		return
	fi
	__clean_complete_strategy && return
	case "$cur" in
	--whitespace=*)
		__cleancomp "$__clean_whitespacelist" "" "${cur##--whitespace=}"
		return
		;;
	--*)
		__cleancomp "
			--onto --merge --strategy --interactive
			--preserve-merges --stat --no-stat
			--committer-date-is-author-date --ignore-date
			--ignore-whitespace --whitespace=
			--autosquash --no-autosquash
			--fork-point --no-fork-point
			--autostash --no-autostash
			--verify --no-verify
			--keep-empty --root --force-rebase --no-ff
			--exec
			"

		return
	esac
	__clean_complete_refs
}

_clean_reflog ()
{
	local subcommands="show delete expire"
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"

	if [ -z "$subcommand" ]; then
		__cleancomp "$subcommands"
	else
		__clean_complete_refs
	fi
}

__clean_send_email_confirm_options="always never auto cc compose"
__clean_send_email_suppresscc_options="author self cc bodycc sob cccmd body all"

_clean_send_email ()
{
	case "$prev" in
	--to|--cc|--bcc|--from)
		__cleancomp "$(__clean send-email --dump-aliases)"
		return
		;;
	esac

	case "$cur" in
	--confirm=*)
		__cleancomp "
			$__clean_send_email_confirm_options
			" "" "${cur##--confirm=}"
		return
		;;
	--suppress-cc=*)
		__cleancomp "
			$__clean_send_email_suppresscc_options
			" "" "${cur##--suppress-cc=}"

		return
		;;
	--smtp-encryption=*)
		__cleancomp "ssl tls" "" "${cur##--smtp-encryption=}"
		return
		;;
	--thread=*)
		__cleancomp "
			deep shallow
			" "" "${cur##--thread=}"
		return
		;;
	--to=*|--cc=*|--bcc=*|--from=*)
		__cleancomp "$(__clean send-email --dump-aliases)" "" "${cur#--*=}"
		return
		;;
	--*)
		__cleancomp "--annotate --bcc --cc --cc-cmd --chain-reply-to
			--compose --confirm= --dry-run --envelope-sender
			--from --identity
			--in-reply-to --no-chain-reply-to --no-signed-off-by-cc
			--no-suppress-from --no-thread --quiet
			--signed-off-by-cc --smtp-pass --smtp-server
			--smtp-server-port --smtp-encryption= --smtp-user
			--subject --suppress-cc= --suppress-from --thread --to
			--validate --no-validate
			$__clean_format_patch_options"
		return
		;;
	esac
	__clean_complete_revlist
}

_clean_stage ()
{
	_clean_add
}

_clean_status ()
{
	local complete_opt
	local untracked_state

	case "$cur" in
	--ignore-submodules=*)
		__cleancomp "none untracked dirty all" "" "${cur##--ignore-submodules=}"
		return
		;;
	--untracked-files=*)
		__cleancomp "$__clean_untracked_file_modes" "" "${cur##--untracked-files=}"
		return
		;;
	--column=*)
		__cleancomp "
			always never auto column row plain dense nodense
			" "" "${cur##--column=}"
		return
		;;
	--*)
		__cleancomp "
			--short --branch --porcelain --long --verbose
			--untracked-files= --ignore-submodules= --ignored
			--column= --no-column
			"
		return
		;;
	esac

	untracked_state="$(__clean_get_option_value "-u" "--untracked-files=" \
		"$__clean_untracked_file_modes" "status.showUntrackedFiles")"

	case "$untracked_state" in
	no)
		# --ignored option does not matter
		complete_opt=
		;;
	all|normal|*)
		complete_opt="--cached --directory --no-empty-directory --others"

		if [ -n "$(__clean_find_on_cmdline "--ignored")" ]; then
			complete_opt="$complete_opt --ignored --exclude=*"
		fi
		;;
	esac

	__clean_complete_index_file "$complete_opt"
}

__clean_config_get_set_variables ()
{
	local prevword word config_file= c=$cword
	while [ $c -gt 1 ]; do
		word="${words[c]}"
		case "$word" in
		--system|--global|--local|--file=*)
			config_file="$word"
			break
			;;
		-f|--file)
			config_file="$word $prevword"
			break
			;;
		esac
		prevword=$word
		c=$((--c))
	done

	__clean config $config_file --name-only --list
}

_clean_config ()
{
	case "$prev" in
	branch.*.remote|branch.*.pushremote)
		__cleancomp_nl "$(__clean_remotes)"
		return
		;;
	branch.*.merge)
		__clean_complete_refs
		return
		;;
	branch.*.rebase)
		__cleancomp "false true preserve interactive"
		return
		;;
	remote.pushdefault)
		__cleancomp_nl "$(__clean_remotes)"
		return
		;;
	remote.*.fetch)
		local remote="${prev#remote.}"
		remote="${remote%.fetch}"
		if [ -z "$cur" ]; then
			__cleancomp_nl "refs/heads/" "" "" ""
			return
		fi
		__cleancomp_nl "$(__clean_refs_remotes "$remote")"
		return
		;;
	remote.*.push)
		local remote="${prev#remote.}"
		remote="${remote%.push}"
		__cleancomp_nl "$(__clean for-each-ref \
			--format='%(refname):%(refname)' refs/heads)"
		return
		;;
	pull.twohead|pull.octopus)
		__clean_compute_merge_strategies
		__cleancomp "$__clean_merge_strategies"
		return
		;;
	color.branch|color.diff|color.interactive|\
	color.showbranch|color.status|color.ui)
		__cleancomp "always never auto"
		return
		;;
	color.pager)
		__cleancomp "false true"
		return
		;;
	color.*.*)
		__cleancomp "
			normal black red green yellow blue magenta cyan white
			bold dim ul blink reverse
			"
		return
		;;
	diff.submodule)
		__cleancomp "log short"
		return
		;;
	help.format)
		__cleancomp "man info web html"
		return
		;;
	log.date)
		__cleancomp "$__clean_log_date_formats"
		return
		;;
	sendemail.aliasesfiletype)
		__cleancomp "mutt mailrc pine elm gnus"
		return
		;;
	sendemail.confirm)
		__cleancomp "$__clean_send_email_confirm_options"
		return
		;;
	sendemail.suppresscc)
		__cleancomp "$__clean_send_email_suppresscc_options"
		return
		;;
	sendemail.transferencoding)
		__cleancomp "7bit 8bit quoted-printable base64"
		return
		;;
	--get|--get-all|--unset|--unset-all)
		__cleancomp_nl "$(__clean_config_get_set_variables)"
		return
		;;
	*.*)
		return
		;;
	esac
	case "$cur" in
	--*)
		__cleancomp "
			--system --global --local --file=
			--list --replace-all
			--get --get-all --get-regexp
			--add --unset --unset-all
			--remove-section --rename-section
			--name-only
			"
		return
		;;
	branch.*.*)
		local pfx="${cur%.*}." cur_="${cur##*.}"
		__cleancomp "remote pushremote merge mergeoptions rebase" "$pfx" "$cur_"
		return
		;;
	branch.*)
		local pfx="${cur%.*}." cur_="${cur#*.}"
		__cleancomp_direct "$(__clean_heads "$pfx" "$cur_" ".")"
		__cleancomp_nl_append $'autosetupmerge\nautosetuprebase\n' "$pfx" "$cur_"
		return
		;;
	guitool.*.*)
		local pfx="${cur%.*}." cur_="${cur##*.}"
		__cleancomp "
			argprompt cmd confirm needsfile noconsole norescan
			prompt revprompt revunmerged title
			" "$pfx" "$cur_"
		return
		;;
	difftool.*.*)
		local pfx="${cur%.*}." cur_="${cur##*.}"
		__cleancomp "cmd path" "$pfx" "$cur_"
		return
		;;
	man.*.*)
		local pfx="${cur%.*}." cur_="${cur##*.}"
		__cleancomp "cmd path" "$pfx" "$cur_"
		return
		;;
	mergetool.*.*)
		local pfx="${cur%.*}." cur_="${cur##*.}"
		__cleancomp "cmd path trustExitCode" "$pfx" "$cur_"
		return
		;;
	pager.*)
		local pfx="${cur%.*}." cur_="${cur#*.}"
		__clean_compute_all_commands
		__cleancomp_nl "$__clean_all_commands" "$pfx" "$cur_"
		return
		;;
	remote.*.*)
		local pfx="${cur%.*}." cur_="${cur##*.}"
		__cleancomp "
			url proxy fetch push mirror skipDefaultUpdate
			receivepack uploadpack tagopt pushurl
			" "$pfx" "$cur_"
		return
		;;
	remote.*)
		local pfx="${cur%.*}." cur_="${cur#*.}"
		__cleancomp_nl "$(__clean_remotes)" "$pfx" "$cur_" "."
		__cleancomp_nl_append "pushdefault" "$pfx" "$cur_"
		return
		;;
	url.*.*)
		local pfx="${cur%.*}." cur_="${cur##*.}"
		__cleancomp "insteadOf pushInsteadOf" "$pfx" "$cur_"
		return
		;;
	esac
	__cleancomp "
		add.ignoreErrors
		advice.amWorkDir
		advice.commitBeforeMerge
		advice.detachedHead
		advice.implicitIdentity
		advice.pushAlreadyExists
		advice.pushFetchFirst
		advice.pushNeedsForce
		advice.pushNonFFCurrent
		advice.pushNonFFMatching
		advice.pushUpdateRejected
		advice.resolveConflict
		advice.rmHints
		advice.statusHints
		advice.statusUoption
		advice.ignoredHook
		alias.
		am.keepcr
		am.threeWay
		apply.ignorewhitespace
		apply.whitespace
		branch.autosetupmerge
		branch.autosetuprebase
		browser.
		clean.requireForce
		color.branch
		color.branch.current
		color.branch.local
		color.branch.plain
		color.branch.remote
		color.decorate.HEAD
		color.decorate.branch
		color.decorate.remoteBranch
		color.decorate.stash
		color.decorate.tag
		color.diff
		color.diff.commit
		color.diff.frag
		color.diff.func
		color.diff.meta
		color.diff.new
		color.diff.old
		color.diff.plain
		color.diff.whitespace
		color.grep
		color.grep.context
		color.grep.filename
		color.grep.function
		color.grep.linenumber
		color.grep.match
		color.grep.selected
		color.grep.separator
		color.interactive
		color.interactive.error
		color.interactive.header
		color.interactive.help
		color.interactive.prompt
		color.pager
		color.showbranch
		color.status
		color.status.added
		color.status.changed
		color.status.header
		color.status.localBranch
		color.status.nobranch
		color.status.remoteBranch
		color.status.unmerged
		color.status.untracked
		color.status.updated
		color.ui
		commit.cleanup
		commit.gpgSign
		commit.status
		commit.template
		commit.verbose
		core.abbrev
		core.askpass
		core.attributesfile
		core.autocrlf
		core.bare
		core.bigFileThreshold
		core.checkStat
		core.commentChar
		core.compression
		core.createObject
		core.deltaBaseCacheLimit
		core.editor
		core.eol
		core.excludesfile
		core.fileMode
		core.fsyncobjectfiles
		core.cleanProxy
		core.hideDotFiles
		core.hooksPath
		core.ignoreStat
		core.ignorecase
		core.logAllRefUpdates
		core.loosecompression
		core.notesRef
		core.packedGitLimit
		core.packedGitWindowSize
		core.packedRefsTimeout
		core.pager
		core.precomposeUnicode
		core.preferSymlinkRefs
		core.preloadindex
		core.protectHFS
		core.protectNTFS
		core.quotepath
		core.repositoryFormatVersion
		core.safecrlf
		core.sharedRepository
		core.sparseCheckout
		core.splitIndex
		core.sshCommand
		core.symlinks
		core.trustctime
		core.untrackedCache
		core.warnAmbiguousRefs
		core.whitespace
		core.worktree
		credential.helper
		credential.useHttpPath
		credential.username
		credentialCache.ignoreSIGHUP
		diff.autorefreshindex
		diff.external
		diff.ignoreSubmodules
		diff.mnemonicprefix
		diff.noprefix
		diff.renameLimit
		diff.renames
		diff.statGraphWidth
		diff.submodule
		diff.suppressBlankEmpty
		diff.tool
		diff.wordRegex
		diff.algorithm
		difftool.
		difftool.prompt
		fetch.recurseSubmodules
		fetch.unpackLimit
		format.attach
		format.cc
		format.coverLetter
		format.from
		format.headers
		format.numbered
		format.pretty
		format.signature
		format.signoff
		format.subjectprefix
		format.suffix
		format.thread
		format.to
		gc.
		gc.aggressiveDepth
		gc.aggressiveWindow
		gc.auto
		gc.autoDetach
		gc.autopacklimit
		gc.logExpiry
		gc.packrefs
		gc.pruneexpire
		gc.reflogexpire
		gc.reflogexpireunreachable
		gc.rerereresolved
		gc.rerereunresolved
		gc.worktreePruneExpire
		cleancvs.allbinary
		cleancvs.commitmsgannotation
		cleancvs.dbTableNamePrefix
		cleancvs.dbdriver
		cleancvs.dbname
		cleancvs.dbpass
		cleancvs.dbuser
		cleancvs.enabled
		cleancvs.logfile
		cleancvs.usecrlfattr
		guitool.
		gui.blamehistoryctx
		gui.commitmsgwidth
		gui.copyblamethreshold
		gui.diffcontext
		gui.encoding
		gui.fastcopyblame
		gui.matchtrackingbranch
		gui.newbranchtemplate
		gui.pruneduringfetch
		gui.spellingdictionary
		gui.trustmtime
		help.autocorrect
		help.browser
		help.format
		http.lowSpeedLimit
		http.lowSpeedTime
		http.maxRequests
		http.minSessions
		http.noEPSV
		http.postBuffer
		http.proxy
		http.sslCipherList
		http.sslVersion
		http.sslCAInfo
		http.sslCAPath
		http.sslCert
		http.sslCertPasswordProtected
		http.sslKey
		http.sslVerify
		http.useragent
		i18n.commitEncoding
		i18n.logOutputEncoding
		imap.authMethod
		imap.folder
		imap.host
		imap.pass
		imap.port
		imap.preformattedHTML
		imap.sslverify
		imap.tunnel
		imap.user
		init.templatedir
		instaweb.browser
		instaweb.httpd
		instaweb.local
		instaweb.modulepath
		instaweb.port
		interactive.singlekey
		log.date
		log.decorate
		log.showroot
		mailmap.file
		man.
		man.viewer
		merge.
		merge.conflictstyle
		merge.log
		merge.renameLimit
		merge.renormalize
		merge.stat
		merge.tool
		merge.verbosity
		mergetool.
		mergetool.keepBackup
		mergetool.keepTemporaries
		mergetool.prompt
		notes.displayRef
		notes.rewrite.
		notes.rewrite.amend
		notes.rewrite.rebase
		notes.rewriteMode
		notes.rewriteRef
		pack.compression
		pack.deltaCacheLimit
		pack.deltaCacheSize
		pack.depth
		pack.indexVersion
		pack.packSizeLimit
		pack.threads
		pack.window
		pack.windowMemory
		pager.
		pretty.
		pull.octopus
		pull.twohead
		push.default
		push.followTags
		rebase.autosquash
		rebase.stat
		receive.autogc
		receive.denyCurrentBranch
		receive.denyDeleteCurrent
		receive.denyDeletes
		receive.denyNonFastForwards
		receive.fsckObjects
		receive.unpackLimit
		receive.updateserverinfo
		remote.pushdefault
		remotes.
		repack.usedeltabaseoffset
		rerere.autoupdate
		rerere.enabled
		sendemail.
		sendemail.aliasesfile
		sendemail.aliasfiletype
		sendemail.bcc
		sendemail.cc
		sendemail.cccmd
		sendemail.chainreplyto
		sendemail.confirm
		sendemail.envelopesender
		sendemail.from
		sendemail.identity
		sendemail.multiedit
		sendemail.signedoffbycc
		sendemail.smtpdomain
		sendemail.smtpencryption
		sendemail.smtppass
		sendemail.smtpserver
		sendemail.smtpserveroption
		sendemail.smtpserverport
		sendemail.smtpuser
		sendemail.suppresscc
		sendemail.suppressfrom
		sendemail.thread
		sendemail.to
		sendemail.tocmd
		sendemail.validate
		sendemail.smtpbatchsize
		sendemail.smtprelogindelay
		showbranch.default
		status.relativePaths
		status.showUntrackedFiles
		status.submodulesummary
		submodule.
		tar.umask
		transfer.unpackLimit
		url.
		user.email
		user.name
		user.signingkey
		web.browser
		branch. remote.
	"
}

_clean_remote ()
{
	local subcommands="
		add rename remove set-head set-branches
		get-url set-url show prune update
		"
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"
	if [ -z "$subcommand" ]; then
		case "$cur" in
		--*)
			__cleancomp "--verbose"
			;;
		*)
			__cleancomp "$subcommands"
			;;
		esac
		return
	fi

	case "$subcommand,$cur" in
	add,--*)
		__cleancomp "--track --master --fetch --tags --no-tags --mirror="
		;;
	add,*)
		;;
	set-head,--*)
		__cleancomp "--auto --delete"
		;;
	set-branches,--*)
		__cleancomp "--add"
		;;
	set-head,*|set-branches,*)
		__clean_complete_remote_or_refspec
		;;
	update,--*)
		__cleancomp "--prune"
		;;
	update,*)
		__cleancomp "$(__clean_get_config_variables "remotes")"
		;;
	set-url,--*)
		__cleancomp "--push --add --delete"
		;;
	get-url,--*)
		__cleancomp "--push --all"
		;;
	prune,--*)
		__cleancomp "--dry-run"
		;;
	*)
		__cleancomp_nl "$(__clean_remotes)"
		;;
	esac
}

_clean_replace ()
{
	case "$cur" in
	--*)
		__cleancomp "--edit --graft --format= --list --delete"
		return
		;;
	esac
	__clean_complete_refs
}

_clean_rerere ()
{
	local subcommands="clear forget diff remaining status gc"
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"
	if test -z "$subcommand"
	then
		__cleancomp "$subcommands"
		return
	fi
}

_clean_reset ()
{
	__clean_has_doubledash && return

	case "$cur" in
	--*)
		__cleancomp "--merge --mixed --hard --soft --patch --keep"
		return
		;;
	esac
	__clean_complete_refs
}

_clean_revert ()
{
	__clean_find_repo_path
	if [ -f "$__clean_repo_path"/REVERT_HEAD ]; then
		__cleancomp "--continue --quit --abort"
		return
	fi
	case "$cur" in
	--*)
		__cleancomp "
			--edit --mainline --no-edit --no-commit --signoff
			--strategy= --strategy-option=
			"
		return
		;;
	esac
	__clean_complete_refs
}

_clean_rm ()
{
	case "$cur" in
	--*)
		__cleancomp "--cached --dry-run --ignore-unmatch --quiet"
		return
		;;
	esac

	__clean_complete_index_file "--cached"
}

_clean_shortlog ()
{
	__clean_has_doubledash && return

	case "$cur" in
	--*)
		__cleancomp "
			$__clean_log_common_options
			$__clean_log_shortlog_options
			--numbered --summary --email
			"
		return
		;;
	esac
	__clean_complete_revlist
}

_clean_show ()
{
	__clean_has_doubledash && return

	case "$cur" in
	--pretty=*|--format=*)
		__cleancomp "$__clean_log_pretty_formats $(__clean_pretty_aliases)
			" "" "${cur#*=}"
		return
		;;
	--diff-algorithm=*)
		__cleancomp "$__clean_diff_algorithms" "" "${cur##--diff-algorithm=}"
		return
		;;
	--submodule=*)
		__cleancomp "$__clean_diff_submodule_formats" "" "${cur##--submodule=}"
		return
		;;
	--*)
		__cleancomp "--pretty= --format= --abbrev-commit --oneline
			--show-signature
			$__clean_diff_common_options
			"
		return
		;;
	esac
	__clean_complete_revlist_file
}

_clean_show_branch ()
{
	case "$cur" in
	--*)
		__cleancomp "
			--all --remotes --topo-order --date-order --current --more=
			--list --independent --merge-base --no-name
			--color --no-color
			--sha1-name --sparse --topics --reflog
			"
		return
		;;
	esac
	__clean_complete_revlist
}

_clean_stash ()
{
	local save_opts='--all --keep-index --no-keep-index --quiet --patch --include-untracked'
	local subcommands='push save list show apply clear drop pop create branch'
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"
	if [ -z "$subcommand" ]; then
		case "$cur" in
		--*)
			__cleancomp "$save_opts"
			;;
		*)
			if [ -z "$(__clean_find_on_cmdline "$save_opts")" ]; then
				__cleancomp "$subcommands"
			fi
			;;
		esac
	else
		case "$subcommand,$cur" in
		push,--*)
			__cleancomp "$save_opts --message"
			;;
		save,--*)
			__cleancomp "$save_opts"
			;;
		apply,--*|pop,--*)
			__cleancomp "--index --quiet"
			;;
		drop,--*)
			__cleancomp "--quiet"
			;;
		show,--*|branch,--*)
			;;
		branch,*)
			if [ $cword -eq 3 ]; then
				__clean_complete_refs
			else
				__cleancomp_nl "$(__clean stash list \
						| sed -n -e 's/:.*//p')"
			fi
			;;
		show,*|apply,*|drop,*|pop,*)
			__cleancomp_nl "$(__clean stash list \
					| sed -n -e 's/:.*//p')"
			;;
		*)
			;;
		esac
	fi
}

_clean_submodule ()
{
	__clean_has_doubledash && return

	local subcommands="add status init deinit update summary foreach sync"
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"
	if [ -z "$subcommand" ]; then
		case "$cur" in
		--*)
			__cleancomp "--quiet"
			;;
		*)
			__cleancomp "$subcommands"
			;;
		esac
		return
	fi

	case "$subcommand,$cur" in
	add,--*)
		__cleancomp "--branch --force --name --reference --depth"
		;;
	status,--*)
		__cleancomp "--cached --recursive"
		;;
	deinit,--*)
		__cleancomp "--force --all"
		;;
	update,--*)
		__cleancomp "
			--init --remote --no-fetch
			--recommend-shallow --no-recommend-shallow
			--force --rebase --merge --reference --depth --recursive --jobs
		"
		;;
	summary,--*)
		__cleancomp "--cached --files --summary-limit"
		;;
	foreach,--*|sync,--*)
		__cleancomp "--recursive"
		;;
	*)
		;;
	esac
}

_clean_svn ()
{
	local subcommands="
		init fetch clone rebase dcommit log find-rev
		set-tree commit-diff info create-ignore propget
		proplist show-ignore show-externals branch tag blame
		migrate mkdirs reset gc
		"
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"
	if [ -z "$subcommand" ]; then
		__cleancomp "$subcommands"
	else
		local remote_opts="--username= --config-dir= --no-auth-cache"
		local fc_opts="
			--follow-parent --authors-file= --repack=
			--no-metadata --use-svm-props --use-svnsync-props
			--log-window-size= --no-checkout --quiet
			--repack-flags --use-log-author --localtime
			--add-author-from
			--ignore-paths= --include-paths= $remote_opts
			"
		local init_opts="
			--template= --shared= --trunk= --tags=
			--branches= --stdlayout --minimize-url
			--no-metadata --use-svm-props --use-svnsync-props
			--rewrite-root= --prefix= $remote_opts
			"
		local cmt_opts="
			--edit --rmdir --find-copies-harder --copy-similarity=
			"

		case "$subcommand,$cur" in
		fetch,--*)
			__cleancomp "--revision= --fetch-all $fc_opts"
			;;
		clone,--*)
			__cleancomp "--revision= $fc_opts $init_opts"
			;;
		init,--*)
			__cleancomp "$init_opts"
			;;
		dcommit,--*)
			__cleancomp "
				--merge --strategy= --verbose --dry-run
				--fetch-all --no-rebase --commit-url
				--revision --interactive $cmt_opts $fc_opts
				"
			;;
		set-tree,--*)
			__cleancomp "--stdin $cmt_opts $fc_opts"
			;;
		create-ignore,--*|propget,--*|proplist,--*|show-ignore,--*|\
		show-externals,--*|mkdirs,--*)
			__cleancomp "--revision="
			;;
		log,--*)
			__cleancomp "
				--limit= --revision= --verbose --incremental
				--oneline --show-commit --non-recursive
				--authors-file= --color
				"
			;;
		rebase,--*)
			__cleancomp "
				--merge --verbose --strategy= --local
				--fetch-all --dry-run $fc_opts
				"
			;;
		commit-diff,--*)
			__cleancomp "--message= --file= --revision= $cmt_opts"
			;;
		info,--*)
			__cleancomp "--url"
			;;
		branch,--*)
			__cleancomp "--dry-run --message --tag"
			;;
		tag,--*)
			__cleancomp "--dry-run --message"
			;;
		blame,--*)
			__cleancomp "--clean-format"
			;;
		migrate,--*)
			__cleancomp "
				--config-dir= --ignore-paths= --minimize
				--no-auth-cache --username=
				"
			;;
		reset,--*)
			__cleancomp "--revision= --parent"
			;;
		*)
			;;
		esac
	fi
}

_clean_tag ()
{
	local i c=1 f=0
	while [ $c -lt $cword ]; do
		i="${words[c]}"
		case "$i" in
		-d|-v)
			__cleancomp_direct "$(__clean_tags "" "$cur" " ")"
			return
			;;
		-f)
			f=1
			;;
		esac
		((c++))
	done

	case "$prev" in
	-m|-F)
		;;
	-*|tag)
		if [ $f = 1 ]; then
			__cleancomp_direct "$(__clean_tags "" "$cur" " ")"
		fi
		;;
	*)
		__clean_complete_refs
		;;
	esac

	case "$cur" in
	--*)
		__cleancomp "
			--list --delete --verify --annotate --message --file
			--sign --cleanup --local-user --force --column --sort=
			--contains --no-contains --points-at --merged --no-merged --create-reflog
			"
		;;
	esac
}

_clean_whatchanged ()
{
	_clean_log
}

_clean_worktree ()
{
	local subcommands="add list lock prune unlock"
	local subcommand="$(__clean_find_on_cmdline "$subcommands")"
	if [ -z "$subcommand" ]; then
		__cleancomp "$subcommands"
	else
		case "$subcommand,$cur" in
		add,--*)
			__cleancomp "--detach"
			;;
		list,--*)
			__cleancomp "--porcelain"
			;;
		lock,--*)
			__cleancomp "--reason"
			;;
		prune,--*)
			__cleancomp "--dry-run --expire --verbose"
			;;
		*)
			;;
		esac
	fi
}

__clean_main ()
{
	local i c=1 command __clean_dir __clean_repo_path
	local __clean_C_args C_args_count=0

	while [ $c -lt $cword ]; do
		i="${words[c]}"
		case "$i" in
		--clean-dir=*) __clean_dir="${i#--clean-dir=}" ;;
		--clean-dir)   ((c++)) ; __clean_dir="${words[c]}" ;;
		--bare)      __clean_dir="." ;;
		--help) command="help"; break ;;
		-c|--work-tree|--namespace) ((c++)) ;;
		-C)	__clean_C_args[C_args_count++]=-C
			((c++))
			__clean_C_args[C_args_count++]="${words[c]}"
			;;
		-*) ;;
		*) command="$i"; break ;;
		esac
		((c++))
	done

	if [ -z "$command" ]; then
		case "$prev" in
		--clean-dir|-C|--work-tree)
			# these need a path argument, let's fall back to
			# Bash filename completion
			return
			;;
		-c|--namespace)
			# we don't support completing these options' arguments
			return
			;;
		esac
		case "$cur" in
		--*)   __cleancomp "
			--paginate
			--no-pager
			--clean-dir=
			--bare
			--version
			--version-clean
			--exec-path
			--exec-path=
			--html-path
			--man-path
			--info-path
			--work-tree=
			--namespace=
			--no-replace-objects
			--help
			"
			;;
		*)     __clean_compute_porcelain_commands
		       __cleancomp "$__clean_porcelain_commands $(__clean_aliases)" ;;
		esac
		return
	fi

	local completion_func="_clean_${command//-/_}"
	declare -f $completion_func >/dev/null 2>/dev/null && $completion_func && return

	local expansion=$(__clean_aliased_command "$command")
	if [ -n "$expansion" ]; then
		words[1]=$expansion
		completion_func="_clean_${expansion//-/_}"
		declare -f $completion_func >/dev/null 2>/dev/null && $completion_func
	fi
}

__cleank_main ()
{
	__clean_has_doubledash && return

	local __clean_repo_path
	__clean_find_repo_path

	local merge=""
	if [ -f "$__clean_repo_path/MERGE_HEAD" ]; then
		merge="--merge"
	fi
	case "$cur" in
	--*)
		__cleancomp "
			$__clean_log_common_options
			$__clean_log_cleank_options
			$merge
			"
		return
		;;
	esac
	__clean_complete_revlist
}

if [[ -n ${ZSH_VERSION-} ]]; then
	echo "WARNING: this script is deprecated, please see clean-completion.zsh" 1>&2

	autoload -U +X compinit && compinit

	__cleancomp ()
	{
		emulate -L zsh

		local cur_="${3-$cur}"

		case "$cur_" in
		--*=)
			;;
		*)
			local c IFS=$' \t\n'
			local -a array
			for c in ${=1}; do
				c="$c${4-}"
				case $c in
				--*=*|*.) ;;
				*) c="$c " ;;
				esac
				array[${#array[@]}+1]="$c"
			done
			compset -P '*[=:]'
			compadd -Q -S '' -p "${2-}" -a -- array && _ret=0
			;;
		esac
	}

	__cleancomp_direct ()
	{
		emulate -L zsh

		local IFS=$'\n'
		compset -P '*[=:]'
		compadd -Q -- ${=1} && _ret=0
	}

	__cleancomp_nl ()
	{
		emulate -L zsh

		local IFS=$'\n'
		compset -P '*[=:]'
		compadd -Q -S "${4- }" -p "${2-}" -- ${=1} && _ret=0
	}

	__cleancomp_file ()
	{
		emulate -L zsh

		local IFS=$'\n'
		compset -P '*[=:]'
		compadd -Q -p "${2-}" -f -- ${=1} && _ret=0
	}

	_clean ()
	{
		local _ret=1 cur cword prev
		cur=${words[CURRENT]}
		prev=${words[CURRENT-1]}
		let cword=CURRENT-1
		emulate ksh -c __${service}_main
		let _ret && _default && _ret=0
		return _ret
	}

	compdef _clean clean cleank
	return
fi

__clean_func_wrap ()
{
	local cur words cword prev
	_get_comp_words_by_ref -n =: cur words cword prev
	$1
}

# Setup completion for certain functions defined above by setting common
# variables and workarounds.
# This is NOT a public function; use at your own risk.
__clean_complete ()
{
	local wrapper="__clean_wrap${2}"
	eval "$wrapper () { __clean_func_wrap $2 ; }"
	complete -o bashdefault -o default -o nospace -F $wrapper $1 2>/dev/null \
		|| complete -o default -o nospace -F $wrapper $1
}

# wrapper for backwards compatibility
_clean ()
{
	__clean_wrap__clean_main
}

# wrapper for backwards compatibility
_cleank ()
{
	__clean_wrap__cleank_main
}

__clean_complete clean __clean_main
__clean_complete cleank __cleank_main

# The following are necessary only for Cygwin, and only are needed
# when the user has tab-completed the executable name and consequently
# included the '.exe' suffix.
#
if [ Cygwin = "$(uname -o 2>/dev/null)" ]; then
__clean_complete clean.exe __clean_main
fi

