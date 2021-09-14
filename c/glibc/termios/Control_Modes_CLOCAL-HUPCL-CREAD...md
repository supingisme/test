17.4.6 Control Modes
This section describes the terminal ﬂags and felds that control parameters usually associ
ated with asynchronous serial data transmission. These ﬂags may not make sense for other
kinds of terminal ports (such as a network connection pseudo-terminal). All of these are
contained in the c_cflag member of the struct termios structure.
The c_cflag member itself is an integer, and you change the ﬂags and felds using the
operators &, |, and ^. Don’t try to specify the entire value for c_cflag—instead, change
only specifc ﬂags and leave the rest untouched (see Section 17.4.3 [Setting Terminal Modes
Properly], page 437).
tcflag_t CLOCAL [Macro]
If this bit is set, it indicates that the terminal is connected “locally” and that the
modem status lines (such as carrier detect) should be ignored.
On many systems if this bit is not set and you call open without the O_NONBLOCK ﬂag
set, open blocks until a modem connection is established.
If this bit is not set and a modem disconnect is detected, a SIGHUP signal is sent to
the controlling process group for the terminal (if it has one). Normally, this causes
the process to exit; see Chapter 24 [Signal Handling], page 602. Reading from the
terminal after a disconnect causes an end-of-fle condition, and writing causes an EIO
error to be returned. The terminal device must be closed and reopened to clear the
condition.
tcflag_t HUPCL [Macro]
If this bit is set, a modem disconnect is generated when all processes that have the
terminal device open have either closed the fle or exited.
tcflag_t CREAD [Macro]
If this bit is set, input can be read from the terminal. Otherwise, input is discarded
when it arrives.
tcflag_t CSTOPB [Macro]
If this bit is set, two stop bits are used. Otherwise, only one stop bit is used.
tcflag_t PARENB [Macro]
If this bit is set, generation and detection of a parity bit are enabled. See Section 17.4.4
[Input Modes], page 438, for information on how input parity errors are handled.
If this bit is not set, no parity bit is added to output characters, and input characters
are not checked for correct parity.
tcflag_t PARODD [Macro]
This bit is only useful if PARENB is set. If PARODD is set, odd parity is used, otherwise
even parity is used.
The control mode ﬂags also includes a feld for the number of bits per character. You
can use the CSIZE macro as a mask to extract the value, like this: settings.c_cflag &
CSIZE.
tcflag_t CSIZE [Macro]
This is a mask for the number of bits per character.
tcflag_t CS5 [Macro]
This specifes fve bits per byte.
tcflag_t CS6 [Macro]
This specifes six bits per byte.
tcflag_t CS7 [Macro]
This specifes seven bits per byte.
tcflag_t CS8 [Macro]
This specifes eight bits per byte.
The following four bits are BSD extensions; this exist only on BSD systems and the
GNU system.
tcflag_t CCTS_OFLOW [Macro]
If this bit is set, enable ﬂow control of output based on the CTS wire (RS232 protocol).
tcflag_t CRTS_IFLOW [Macro]
If this bit is set, enable ﬂow control of input based on the RTS wire (RS232 protocol).
tcflag_t MDMBUF [Macro]
If this bit is set, enable carrier-based ﬂow control of output.
tcflag_t CIGNORE [Macro]
If this bit is set, it says to ignore the control modes and line speed values entirely.
This is only meaningful in a call to tcsetattr.
The c_cflag member and the line speed values returned by cfgetispeed and
cfgetospeed will be unaﬀected by the call. CIGNORE is useful if you want to set all
the software modes in the other members, but leave the hardware details in c_cflag
unchanged. (This is how the TCSASOFT ﬂag to tcsettattr works.)
This bit is never set in the structure flled in by tcgetattr.