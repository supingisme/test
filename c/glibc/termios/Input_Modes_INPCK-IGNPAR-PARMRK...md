17.4.4 Input Modes
This section describes the terminal attribute ﬂags that control fairly low-level aspects of
input processing: handling of parity errors, break signals, ﬂow control, and RET and LFD
characters.
All of these ﬂags are bits in the c_iflag member of the struct termios structure. The
member is an integer, and you change ﬂags using the operators &, | and ^. Don’t try to
specify the entire value for c_iflag—instead, change only specifc ﬂags and leave the rest
untouched (see Section 17.4.3 [Setting Terminal Modes Properly], page 437).
tcflag_t INPCK [Macro]
If this bit is set, input parity checking is enabled. If it is not set, no checking at all
is done for parity errors on input; the characters are simply passed through to the
application.
Parity checking on input processing is independent of whether parity detection and
generation on the underlying terminal hardware is enabled; see Section 17.4.6 [Control
Modes], page 440. For example, you could clear the INPCK input mode ﬂag and set
the PARENB control mode ﬂag to ignore parity errors on input, but still generate parity
on output.
If this bit is set, what happens when a parity error is detected depends on whether
the IGNPAR or PARMRK bits are set. If neither of these bits are set, a byte with a parity
error is passed to the application as a ’\0’ character.
tcflag_t IGNPAR [Macro]
If this bit is set, any byte with a framing or parity error is ignored. This is only useful
if INPCK is also set.
tcflag_t PARMRK [Macro]
If this bit is set, input bytes with parity or framing errors are marked when passed
to the program. This bit is meaningful only when INPCK is set and IGNPAR is not set.
The way erroneous bytes are marked is with two preceding bytes, 377 and 0. Thus, the
program actually reads three bytes for one erroneous byte received from the terminal.
If a valid byte has the value 0377, and ISTRIP (see below) is not set, the program
might confuse it with the prefx that marks a parity error. So a valid byte 0377 is
passed to the program as two bytes, 0377 0377, in this case.
tcflag_t ISTRIP [Macro]
If this bit is set, valid input bytes are stripped to seven bits; otherwise, all eight bits
are available for programs to read.

tcflag_t IGNBRK [Macro]
If this bit is set, break conditions are ignored.
A break condition is defned in the context of asynchronous serial data transmission
as a series of zero-value bits longer than a single byte.
tcflag_t BRKINT [Macro]
If this bit is set and IGNBRK is not set, a break condition clears the terminal input and
output queues and raises a SIGINT signal for the foreground process group associated
with the terminal.
If neither BRKINT nor IGNBRK are set, a break condition is passed to the application as
a single ’\0’ character if PARMRK is not set, or otherwise as a three-character sequence
’\377’, ’\0’, ’\0’.
tcflag_t IGNCR [Macro]
If this bit is set, carriage return characters (’\r’) are discarded on input. Discarding
carriage return may be useful on terminals that send both carriage return and linefeed
when you type the RET key.
tcflag_t ICRNL [Macro]
If this bit is set and IGNCR is not set, carriage return characters (’\r’) received as
input are passed to the application as newline characters (’\n’).
tcflag_t INLCR [Macro]
If this bit is set, newline characters (’\n’) received as input are passed to the appli
cation as carriage return characters (’\r’).
tcflag_t IXOFF [Macro]
If this bit is set, start/stop control on input is enabled. In other words, the computer
sends STOP and START characters as necessary to prevent input from coming in
faster than programs are reading it. The idea is that the actual terminal hardware
that is generating the input data responds to a STOP character by suspending trans
mission, and to a START character by resuming transmission. See Section 17.4.9.3
[Special Characters for Flow Control], page 449.
tcflag_t IXON [Macro]
If this bit is set, start/stop control on output is enabled. In other words, if the
computer receives a STOP character, it suspends output until a START character
is received. In this case, the STOP and START characters are never passed to the
application program. If this bit is not set, then START and STOP can be read
as ordinary characters. See Section 17.4.9.3 [Special Characters for Flow Control],
page 449.
tcflag_t IXANY [Macro]
If this bit is set, any input character restarts output when output has been suspended
with the STOP character. Otherwise, only the START character restarts output.
This is a BSD extension; it exists only on BSD systems and the GNU system.
tcflag_t IMAXBEL [Macro]
If this bit is set, then flling up the terminal input buﬀer sends a BEL character (code
007) to the terminal to ring the bell.
This is a BSD extension.