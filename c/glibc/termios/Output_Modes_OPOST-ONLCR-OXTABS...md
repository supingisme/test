17.4.5 Output Modes
This section describes the terminal ﬂags and felds that control how output characters are
translated and padded for display. All of these are contained in the c_oflag member of the
struct termios structure.
The c_oflag member itself is an integer, and you change the ﬂags and felds using the
operators &, |, and ^. Don’t try to specify the entire value for c_oflag—instead, change
only specifc ﬂags and leave the rest untouched (see Section 17.4.3 [Setting Terminal Modes
Properly], page 437).
tcflag_t OPOST [Macro]
If this bit is set, output data is processed in some unspecifed way so that it is dis
played appropriately on the terminal device. This typically includes mapping newline
characters (’\n’) onto carriage return and linefeed pairs.
If this bit isn’t set, the characters are transmitted as-is.
The following three bits are BSD features, and they exist only BSD systems and the
GNU system. They are eﬀective only if OPOST is set.
tcflag_t ONLCR [Macro]
If this bit is set, convert the newline character on output into a pair of characters,
carriage return followed by linefeed.
tcflag_t OXTABS [Macro]
If this bit is set, convert tab characters on output into the appropriate number of
spaces to emulate a tab stop every eight columns.
tcflag_t ONOEOT [Macro]
If this bit is set, discard C-d characters (code 004) on output. These characters cause
many dial-up terminals to disconnect.

