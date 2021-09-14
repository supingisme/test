/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:31 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:33 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:54:05 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:17 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:54 CST. */
/*
struct timex [Data Type]
This structure is used to control and monitor the system clock. It contains the
following members:
unsigned int modes
This variable controls whether and which values are set. Several symbolic
constants have to be combined with binary or to specify the eﬀective
mode. These constants start with MOD_.
long int offset
This value indicates the current oﬀset of the system clock from the true
calendar time. The value is given in microseconds. If bit MOD_OFFSET is
set in modes, the oﬀset (and possibly other dependent values) can be set.
The oﬀset’s absolute value must not exceed MAXPHASE.
long int frequency
This value indicates the diﬀerence in frequency between the true calendar
time and the system clock. The value is expressed as scaled PPM (parts
per million, 0.0001%). The scaling is 1 << SHIFT_USEC. The value can
be set with bit MOD_FREQUENCY, but the absolute value must not exceed
MAXFREQ.
long int maxerror
This is the maximum error, measured in microseconds. A new value
can be set using bit MOD_MAXERROR. Unless updated via ntp_adjtime
periodically, this value will increase steadily and reach some platform
specifc maximum value.
long int esterror
This is the estimated error, measured in microseconds. This value can be
set using bit MOD_ESTERROR.
int status
This variable reﬂects the various states of the clock machinery. There are
symbolic constants for the signifcant bits, starting with STA_. Some of
these ﬂags can be updated using the MOD_STATUS bit.
long int constant
This value represents the bandwidth or stiﬀness of the PLL (phase locked
loop) implemented in the kernel. The value can be changed using bit MOD_
TIMECONST.
long int precision
This value represents the accuracy or the maximum error when reading
the system clock. The value is expressed in microseconds.
long int tolerance
This value represents the maximum frequency error of the system clock
in scaled PPM. This value is used to increase the maxerror every second.
struct timeval time
The current calendar time.

long int tick
The elapsed time between clock ticks in microseconds. A clock tick is a
periodic timer interrupt on which the system clock is based.
long int ppsfreq
This is the frst of a few optional variables that are present only if the
system clock can use a PPS (pulse per second) signal to discipline the
system clock. The value is expressed in scaled PPM and it denotes the
diﬀerence in frequency between the system clock and the PPS signal.
long int jitter
This value expresses a median fltered average of the PPS signal’s disper
sion in microseconds.
int shift This value is a binary exponent for the duration of the PPS calibration
interval, ranging from PPS_SHIFT to PPS_SHIFTMAX.
long int stabil
This value represents the median fltered dispersion of the PPS frequency
in scaled PPM.
long int jitcnt
This counter represents the number of pulses where the jitter exceeded
the allowed maximum MAXTIME.
long int calcnt
This counter reﬂects the number of successful calibration intervals.
long int errcnt
This counter represents the number of calibration errors (caused by large
oﬀsets or jitter).
long int stbcnt
This counter denotes the number of calibrations where the stability ex
ceeded the threshold.
*/

#include <sys/timex.h>

struct timex{
    unsigned int modes;
    long int offset;
    long int frequency;
    long int maxerror;
    long int esterror;
    int status;
    long int constant;
    long int precision;
    long int tolerance;
    struct timeval time;
    long int tick;
    long int ppsfreq;
    long int jitter;
    int shift;
    long int stabil;
    long int jitcnt;
    long int calcnt;
    long int errcnt;
    long int stbcnt;
};