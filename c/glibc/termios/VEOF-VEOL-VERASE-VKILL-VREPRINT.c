/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:32 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:34 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:06 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:18 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:55 CST. */
/**
 *	int VEOF
 17.4.9.1 Characters for Input Editing
These special characters are active only in canonical input mode. See Section 17.3 [Two
Styles of Input: Canonical or Not], page 434.
int VEOF [Macro]
This is the subscript for the EOF character in the special control character array.
termios.c_cc[VEOF] holds the character itself.
The EOF character is recognized only in canonical input mode. It acts as a line
terminator in the same way as a newline character, but if the EOF character is typed
at the beginning of a line it causes read to return a byte count of zero, indicating
end-of-fle. The EOF character itself is discarded.
Usually, the EOF character is C-d.
int VEOL [Macro]
This is the subscript for the EOL character in the special control character array.
termios.c_cc[VEOL] holds the character itself.
The EOL character is recognized only in canonical input mode. It acts as a line
terminator, just like a newline character. The EOL character is not discarded; it is
read as the last character in the input line.
You don’t need to use the EOL character to make RET end a line. Just set the
ICRNL ﬂag. In fact, this is the default state of aﬀairs.
int VEOL2 [Macro]
This is the subscript for the EOL2 character in the special control character array.
termios.c_cc[VEOL2] holds the character itself.
The EOL2 character works just like the EOL character (see above), but it can be a
diﬀerent character. Thus, you can specify two characters to terminate an input line,
by setting EOL to one of them and EOL2 to the other.
The EOL2 character is a BSD extension; it exists only on BSD systems and the GNU
system.

int VERASE [Macro]
This is the subscript for the ERASE character in the special control character array.
termios.c_cc[VERASE] holds the character itself.
The ERASE character is recognized only in canonical input mode. When the user
types the erase character, the previous character typed is discarded. (If the terminal
generates multibyte character sequences, this may cause more than one byte of input
to be discarded.) This cannot be used to erase past the beginning of the current line
of text. The ERASE character itself is discarded.
Usually, the ERASE character is DEL.
int VWERASE [Macro]
This is the subscript for the WERASE character in the special control character array.
termios.c_cc[VWERASE] holds the character itself.
The WERASE character is recognized only in canonical mode. It erases an entire
word of prior input, and any whitespace after it; whitespace characters before the
word are not erased.
The defnition of a “word” depends on the setting of the ALTWERASE mode; see
Section 17.4.7 [Local Modes], page 442.
If the ALTWERASE mode is not set, a word is defned as a sequence of any characters
except space or tab.
If the ALTWERASE mode is set, a word is defned as a sequence of characters containing
only letters, numbers, and underscores, optionally followed by one character that is
not a letter, number, or underscore.
The WERASE character is usually C-w.
This is a BSD extension.
int VKILL [Macro]
This is the subscript for the KILL character in the special control character array.
termios.c_cc[VKILL] holds the character itself.
The KILL character is recognized only in canonical input mode. When the user types
the kill character, the entire contents of the current line of input are discarded. The
kill character itself is discarded too.
The KILL character is usually C-u.
int VREPRINT [Macro]
This is the subscript for the REPRINT character in the special control character
array. termios.c_cc[VREPRINT] holds the character itself.
The REPRINT character is recognized only in canonical mode. It reprints the current
input line. If some asynchronous output has come while you are typing, this lets you
see the line you are typing clearly again.
The REPRINT character is usually C-r.
This is a BSD extension.


 */

#include <stdio.h>
#include <termios.h>

int main()
{
	struct termios t;

	tcgetattr(fileno(stdout), &t);

	printf("%2d:%4d:%c\n", VEOF, t.c_cc[VEOF], (char)t.c_cc[VEOF]);
	printf("%2d:%4d:%c\n", VEOL, t.c_cc[VEOL], (char)t.c_cc[VEOL]);
	printf("%2d:%4d:%c\n", VEOL2, t.c_cc[VEOL2], (char)t.c_cc[VEOL2]);
	printf("%2d:%4d:%c\n", VERASE, t.c_cc[VERASE], (char)t.c_cc[VERASE]);
	printf("%2d:%4d:%c\n", VWERASE, t.c_cc[VWERASE], (char)t.c_cc[VWERASE]);
	printf("%2d:%4d:%c\n", VKILL, t.c_cc[VKILL], (char)t.c_cc[VKILL]);
	printf("%2d:%4d:%c\n", VREPRINT, t.c_cc[VREPRINT], (char)t.c_cc[VREPRINT]);

    
    printf("%2d:%4d:%c\n", VINTR, t.c_cc[VINTR], (char)t.c_cc[VINTR]);
	printf("%2d:%4d:%c\n", VQUIT, t.c_cc[VQUIT], (char)t.c_cc[VQUIT]);
	printf("%2d:%4d:%c\n", VSUSP, t.c_cc[VSUSP], (char)t.c_cc[VSUSP]);
    
	return 0;
}
