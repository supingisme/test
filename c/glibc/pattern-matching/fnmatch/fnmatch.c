/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:19 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:28 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:59 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:12 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:50 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:57 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <fnmatch.h>
#include <glob.h>

/*int fnmatch (const char *pattern, const char *string, int flags) [Function]
 * This function tests whether the string string matches the pattern pattern. It re
 * turns 0 if they do match; otherwise, it returns the nonzero value FNM_NOMATCH. The
 * arguments pattern and string are both strings.
 * The argument ﬂags is a combination of ﬂag bits that alter the details of matching.
 * See below for a list of the defned ﬂags.
 * In the GNU C Library, fnmatch cannot experience an “error”—it always returns an
 * answer for whether the match succeeds. However, other implementations of fnmatch
 * might sometimes report “errors”. They would do so by returning nonzero values that
 * are not equal to FNM_NOMATCH.
 * These are the available ﬂags for the ﬂags argument:
 * FNM_FILE_NAME
 * Treat the ‘/’ character specially, for matching fle names. If this ﬂag is set,
 * wildcard constructs in pattern cannot match ‘/’ in string. Thus, the only way
 * to match ‘/’ is with an explicit ‘/’ in pattern.
 * FNM_PATHNAME
 * This is an alias for FNM_FILE_NAME; it comes from POSIX.2. We don’t recom
 * mend this name because we don’t use the term “pathname” for fle names.
 * FNM_PERIOD
 * Treat the ‘.’ character specially if it appears at the beginning of string. If this
 * ﬂag is set, wildcard constructs in pattern cannot match ‘.’ as the frst character
 * of string.
 * If you set both FNM_PERIOD and FNM_FILE_NAME, then the special treatment
 * applies to ‘.’ following ‘/’ as well as to ‘.’ at the beginning of string. (The
 * shell uses the FNM_PERIOD and FNM_FILE_NAME ﬂags together for matching fle
 * names.)
 * FNM_NOESCAPE
 * Don’t treat the ‘\’ character specially in patterns. Normally, ‘\’ quotes the
 * following character, turning oﬀ its special meaning (if any) so that it matches
 * only itself. When quoting is enabled, the pattern ‘\?’ matches only the string
 * ‘?’, because the question mark in the pattern acts like an ordinary character.
 * If you use FNM_NOESCAPE, then ‘\’ is an ordinary character.
 * FNM_LEADING_DIR
 * Ignore a trailing sequence of characters starting with a ‘/’ in string; that is to
 * say, test whether string starts with a directory name that pattern matches.
 * If this ﬂag is set, either ‘foo*’ or ‘foobar’ as a pattern would match the string
 * ‘foobar/frobozz’.
 * FNM_CASEFOLD
 * Ignore case in comparing string to pattern.
 * FNM_EXTMATCH
 * Recognize beside the normal patterns also the extended patterns introduced in
 * ‘ksh’. The patterns are written in the form explained in the following table
 * where pattern-list is a | separated list of patterns.
 * 
 * ?(pattern-list)
 *		The pattern matches if zero or one occurrences of any of the pat
 *		terns in the pattern-list allow matching the input string.
 * *(pattern-list)
 *		The pattern matches if zero or more occurrences of any of the pat
 *		terns in the pattern-list allow matching the input string.
 * +(pattern-list)
 *		The pattern matches if one or more occurrences of any of the pat
 *		terns in the pattern-list allow matching the input string.
 * @(pattern-list)
 *		The pattern matches if exactly one occurrence of any of the patterns
 *		in the pattern-list allows matching the input string.
 * !(pattern-list)
 *		The pattern matches if the input string cannot be matched with
 *		any of the patterns in the pattern-list.
 */

int main()
{
	int ret = fnmatch("*ro*ao", "sylincom RongTao", FNM_PERIOD);

	printf("ret=%d\n", ret);

	glob_t gt;
	

	return 0;
}
