/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:12 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:24 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 13日 星期三 08:53:54 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 12日 星期二 15:07:31 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:08 CST. */
/* Copyright (c) Colorado School of Mines, CST.*/
/* All rights reserved.                       */

/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:27:47 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:26:54 CST. */
/**
20.6 Rounding Modes
Floating-point calculations are carried out internally with extra precision, and then rounded
to ft into the destination type. This ensures that results are as precise as the input data.
IEEE 754 defnes four possible rounding modes:
Round to nearest.
This is the default mode. It should be used unless there is a specifc need for
one of the others. In this mode results are rounded to the nearest representable
value. If the result is midway between two representable values, the even repre
sentable is chosen. Even here means the lowest-order bit is zero. This rounding
mode prevents statistical bias and guarantees numeric stability: round-oﬀ errors
in a lengthy calculation will remain smaller than half of FLT_EPSILON.
Round toward plus Infnity.
All results are rounded to the smallest representable value which is greater than
the result.
Round toward minus Infnity.
All results are rounded to the largest representable value which is less than the
result.
Round toward zero.
All results are rounded to the largest representable value whose magnitude is
less than that of the result. In other words, if the result is negative it is rounded
up; if it is positive, it is rounded down.
‘fenv.h’ defnes constants which you can use to refer to the various rounding modes. Each
one will be defned if and only if the FPU supports the corresponding rounding mode.
FE_TONEAREST
Round to nearest.
FE_UPWARD
Round toward +1.
FE_DOWNWARD
Round toward −1.
FE_TOWARDZERO
Round toward zero.
Underﬂow is an unusual case. Normally, IEEE 754 ﬂoating point numbers are always
normalized (see Section A.5.3.1 [Floating Point Representation Concepts], page 809). Num
bers smaller than 2r (where r is the minimum exponent, FLT_MIN_RADIX-1 for ﬂoat) cannot
be represented as normalized numbers. Rounding all such numbers to zero or 2r would cause
some algorithms to fail at 0. Therefore, they are left in denormalized form. That produces
loss of precision, since some bits of the mantissa are stolen to indicate the decimal point.
If a result is too small to be represented as a denormalized number, it is rounded to
zero. However, the sign of the result is preserved; if the calculation was negative, the result
is negative zero. Negative zero can also result from some operations on infnity, such as
4= − 1. Negative zero behaves identically to zero except when the copysign or signbit
functions are used to check the sign bit directly.
At any time one of the above four rounding modes is selected. You can fnd out which
one with this function:
int fegetround (void) [Function]
Returns the currently selected rounding mode, represented by one of the values of the
defned rounding mode macros.
*/

#include <fenv.h>
#include <stdio.h>
#include <math.h>

//int fegetround (void);
#define _print(val) printf("%s:%x\n", #val, val)

int main()
{
    _print(FE_TONEAREST);
    _print(FE_UPWARD);
    _print(FE_DOWNWARD);
    _print(FE_TOWARDZERO);
    
    float f = sqrtf(-1);
    
    fesetround(FE_DOWNWARD|FE_TONEAREST|FE_TOWARDZERO|FE_UPWARD);
    
    printf("%x\n", fegetround());
    
    
    return 0;
}