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
#include <wordexp.h>

/* 
 * 10.4.2 Calling wordexp
 * All the functions, constants and data types for word expansion are declared in the header
 * fle ‘wordexp.h’.
 * Word expansion produces a vector of words (strings). To return this vector, wordexp
 * uses a special data type, wordexp_t, which is a structure. You pass wordexp the address
 * of the structure, and it flls in the structure’s felds to tell you about the results.
 * wordexp_t [Data Type]
 * This data type holds a pointer to a word vector. More precisely, it records both the
 * address of the word vector and its size.
 * we_wordc The number of elements in the vector.
 * we_wordv The address of the vector. This feld has type char **.
 * we_offs The oﬀset of the frst real element of the vector, from its nominal address
 * in the we_wordv feld. Unlike the other felds, this is always an input to
 * wordexp, rather than an output from it.
 * If you use a nonzero oﬀset, then that many elements at the beginning
 * of the vector are left empty. (The wordexp function flls them with null
 * pointers.)
 * The we_offs feld is meaningful only if you use the WRDE_DOOFFS ﬂag.
 * Otherwise, the oﬀset is always zero regardless of what is in this feld, and
 * the frst real element comes at the beginning of the vector.
 * int wordexp (const char *words, wordexp t *word-vector-ptr, int [Function]
 * flags)
 * Perform word expansion on the string words, putting the result in a newly allocated
 * vector, and store the size and address of this vector into *word-vector-ptr. The
 * argument ﬂags is a combination of bit ﬂags; see Section 10.4.3 [Flags for Word Ex
 * pansion], page 216, for details of the ﬂags.
 *
 * You shouldn’t use any of the characters ‘|&;<>’ in the string words unless they are
 * quoted; likewise for newline. If you use these characters unquoted, you will get the
 * WRDE_BADCHAR error code. Don’t use parentheses or braces unless they are quoted
 * or part of a word expansion construct. If you use quotation characters ‘’"‘’, they
 * should come in pairs that balance.
 * The results of word expansion are a sequence of words. The function wordexp allocates
 * a string for each resulting word, then allocates a vector of type char ** to store the
 * addresses of these strings. The last element of the vector is a null pointer. This vector
 * is called the word vector.
 * To return this vector, wordexp stores both its address and its length (number of
 * elements, not counting the terminating null pointer) into *word-vector-ptr.
 * If wordexp succeeds, it returns 0. Otherwise, it returns one of these error codes:
 * WRDE_BADCHAR
 * The input string words contains an unquoted invalid character such as
 * ‘|’.
 * WRDE_BADVAL
 * The input string refers to an undefned shell variable, and you used the
 * ﬂag WRDE_UNDEF to forbid such references.
 * WRDE_CMDSUB
 * The input string uses command substitution, and you used the ﬂag WRDE_
 * NOCMD to forbid command substitution.
 * WRDE_NOSPACE
 * It was impossible to allocate memory to hold the result. In this case,
 * wordexp can store part of the results—as much as it could allocate room
 * for.
 * WRDE_SYNTAX
 * There was a syntax error in the input string. For example, an unmatched
 * quoting character is a syntax error.
 * void wordfree (wordexp t *word-vector-ptr) [Function]
 * Free the storage used for the word-strings and vector that *word-vector-ptr points
 * to. This does not free the structure *word-vector-ptr itself—only the other data it
 * points to.
 *
 * 10.4.3 Flags for Word Expansion
 * This section describes the ﬂags that you can specify in the ﬂags argument to wordexp.
 * Choose the ﬂags you want, and combine them with the C operator |.
 * WRDE_APPEND
 * Append the words from this expansion to the vector of words produced by
 * previous calls to wordexp. This way you can eﬀectively expand several words
 * as if they were concatenated with spaces between them.
 * In order for appending to work, you must not modify the contents of the word
 * vector structure between calls to wordexp. And, if you set WRDE_DOOFFS in the
 * frst call to wordexp, you must also set it when you append to the results.
 *
 * WRDE_DOOFFS
 * Leave blank slots at the beginning of the vector of words. The we_offs feld
 * says how many slots to leave. The blank slots contain null pointers.
 * WRDE_NOCMD
 * Don’t do command substitution; if the input requests command substitution,
 * report an error.
 * WRDE_REUSE
 * Reuse a word vector made by a previous call to wordexp. Instead of allocating
 * a new vector of words, this call to wordexp will use the vector that already
 * exists (making it larger if necessary).
 * Note that the vector may move, so it is not safe to save an old pointer and use
 * it again after calling wordexp. You must fetch we_pathv anew after each call.
 * WRDE_SHOWERR
 * Do show any error messages printed by commands run by command substi
 * tution. More precisely, allow these commands to inherit the standard error
 * output stream of the current process. By default, wordexp gives these com
 * mands a standard error stream that discards all output.
 * WRDE_UNDEF
 * If the input refers to a shell variable that is not defned, report an error.
 */

int
expand_and_execute (const char *program, const char **options)
{
	wordexp_t result;
	pid_t pid;
	int status, i;

	/* Expand the string for the program to run. */
	switch (wordexp (program, &result, 0))
	{
		case 0: /* Successful. */
			printf("program:%s\n", program);
            for(i=0;i<result.we_wordc;i++)
            {
                printf("%4d: %s\n", __LINE__, result.we_wordv[i]);
            }
			break;
		case WRDE_NOSPACE:
			/* If the error was WRDE_NOSPACE,
			 * then perhaps part of the result was allocated. */
			wordfree (&result);
		default: /* Some other error. */
			return -1;
	}
	/* Expand the strings specifed for the arguments. */
	for (i = 0; options[i] != NULL; i++)
	{
		if (wordexp (options[i], &result, WRDE_APPEND))
		{
            for(i=0;i<result.we_wordc;i++)
            {
                printf("%4d: %s\n", __LINE__, result.we_wordv[i]);
            }
			wordfree (&result);
			return -1;
		}
	}
    for(i=0;i<result.we_wordc;i++)
    {
        printf("%4d: %s\n", __LINE__, result.we_wordv[i]);
    }
    
	pid = fork ();
	if (pid == 0)
	{
		/* This is the child process. Execute the command. */
        printf("execute: %s\n",result.we_wordv[0] );
		execv (result.we_wordv[0], result.we_wordv);
		exit (EXIT_FAILURE);
	}
	else if (pid < 0)
		/* The fork failed. Report failure. */
		status = -1;
	else
		/* This is the parent process. Wait for the child to complete. */
		if (waitpid (pid, &status, 0) != pid)
			status = -1;
        
	wordfree (&result);
    
	return status;
}

int main()
{
	char *options[2] = {"ls", "~/*"};
	expand_and_execute("*.c *.*", options);

	return 0;
}
