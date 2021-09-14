17.4.7 Local Modes
This section describes the ﬂags for the c_lflag member of the struct termios structure.
These ﬂags generally control higher-level aspects of input processing than the input modes
ﬂags described in Section 17.4.4 [Input Modes], page 438, such as echoing, signals, and the
choice of canonical or noncanonical input.
The c_lflag member itself is an integer, and you change the ﬂags and felds using the
operators &, |, and ^. Don’t try to specify the entire value for c_lflag—instead, change
only specifc ﬂags and leave the rest untouched (see Section 17.4.3 [Setting Terminal Modes
Properly], page 437).
tcflag_t ICANON [Macro]
This bit, if set, enables canonical input processing mode. Otherwise, input is pro
cessed in noncanonical mode. See Section 17.3 [Two Styles of Input: Canonical or
Not], page 434.
tcflag_t ECHO [Macro]
If this bit is set, echoing of input characters back to the terminal is enabled.
tcflag_t ECHOE [Macro]
If this bit is set, echoing indicates erasure of input with the ERASE character by
erasing the last character in the current line from the screen. Otherwise, the character
erased is re-echoed to show what has happened (suitable for a printing terminal).
This bit only controls the display behavior; the ICANON bit by itself controls actual
recognition of the ERASE character and erasure of input, without which ECHOE is
simply irrelevant.
tcflag_t ECHOPRT [Macro]
This bit is like ECHOE, enables display of the ERASE character in a way that is geared
to a hardcopy terminal. When you type the ERASE character, a ‘\’ character is
printed followed by the frst character erased. Typing the ERASE character again just
prints the next character erased. Then, the next time you type a normal character, a
‘/’ character is printed before the character echoes.
This is a BSD extension, and exists only in BSD systems and the GNU system.
tcflag_t ECHOK [Macro]
This bit enables special display of the KILL character by moving to a new line after
echoing the KILL character normally. The behavior of ECHOKE (below) is nicer to
look at.
If this bit is not set, the KILL character echoes just as it would if it were not the
KILL character. Then it is up to the user to remember that the KILL character has
erased the preceding input; there is no indication of this on the screen.
This bit only controls the display behavior; the ICANON bit by itself controls actual
recognition of the KILL character and erasure of input, without which ECHOK is simply
irrelevant.
tcflag_t ECHOKE [Macro]
This bit is similar to ECHOK. It enables special display of the KILL character by
erasing on the screen the entire line that has been killed. This is a BSD extension,
and exists only in BSD systems and the GNU system.
tcflag_t ECHONL [Macro]
If this bit is set and the ICANON bit is also set, then the newline (’\n’) character is
echoed even if the ECHO bit is not set.
tcflag_t ECHOCTL [Macro]
If this bit is set and the ECHO bit is also set, echo control characters with ‘^’ followed
by the corresponding text character. Thus, control-A echoes as ‘^A’. This is usually
the preferred mode for interactive input, because echoing a control character back to
the terminal could have some undesired eﬀect on the terminal.
This is a BSD extension, and exists only in BSD systems and the GNU system.
tcflag_t ISIG [Macro]
This bit controls whether the INTR, QUIT, and SUSP characters are recognized. The
functions associated with these characters are performed if and only if this bit is set.
Being in canonical or noncanonical input mode has no aﬀect on the interpretation of
these characters.
You should use caution when disabling recognition of these characters. Programs that
cannot be interrupted interactively are very user-unfriendly. If you clear this bit, your
program should provide some alternate interface that allows the user to interactively
send the signals associated with these characters, or to escape from the program.
See Section 17.4.9.2 [Characters that Cause Signals], page 448.
tcflag_t IEXTEN [Macro]
POSIX.1 gives IEXTEN implementation-defned meaning, so you cannot rely on this
interpretation on all systems.
On BSD systems and the GNU system, it enables the LNEXT and DISCARD char
acters. See Section 17.4.9.4 [Other Special Characters], page 449.
tcflag_t NOFLSH [Macro]
Normally, the INTR, QUIT, and SUSP characters cause input and output queues for
the terminal to be cleared. If this bit is set, the queues are not cleared.
tcflag_t TOSTOP [Macro]
If this bit is set and the system supports job control, then SIGTTOU signals are gener
ated by background processes that attempt to write to the terminal. See Section 27.4
[Access to the Controlling Terminal], page 700.
The following bits are BSD extensions; they exist only in BSD systems and the GNU
system.
tcflag_t ALTWERASE [Macro]
This bit determines how far the WERASE character should erase. The WERASE
character erases back to the beginning of a word; the question is, where do words
begin?
If this bit is clear, then the beginning of a word is a nonwhitespace character fol
lowing a whitespace character. If the bit is set, then the beginning of a word is an
alphanumeric character or underscore following a character which is none of those.
See Section 17.4.9.1 [Characters for Input Editing], page 446, for more information
about the WERASE character.
tcflag_t FLUSHO [Macro]
This is the bit that toggles when the user types the DISCARD character. While this
bit is set, all output is discarded. See Section 17.4.9.4 [Other Special Characters],
page 449.
tcflag_t NOKERNINFO [Macro]
Setting this bit disables handling of the STATUS character. See Section 17.4.9.4
[Other Special Characters], page 449.
tcflag_t PENDIN [Macro]
If this bit is set, it indicates that there is a line of input that needs to be reprinted.
Typing the REPRINT character sets this bit; the bit remains set until reprinting is
fnished. See Section 17.4.9.1 [Characters for Input Editing], page 446.