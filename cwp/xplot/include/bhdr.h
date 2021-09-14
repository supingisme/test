/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:51 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:24:51 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:35 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:08 CST. */
/* Copyright (c) Colorado School of Mines, 2011.*/
/* All rights reserved.                       */

/*
 * bhdr.h - include file for bhed offset array
 * THIS HEADER FILE IS FIXED FOR ALL MACHINES BY THE SEG_Y STANDARD 
 */

#ifndef BHDR_H
#define BHDR_H

static struct {
        char *key;      char *type;     int offs;
} bhdr[] = {
            {"jobid",             "i",            0},
            {"lino",              "i",            4},
            {"reno",              "i",            8},
            {"ntrpr",             "h",            12},
            {"nart",              "h",            14},
            {"hdt",               "h",            16},
            {"dto",               "h",            18},
            {"hns",               "h",            20},
            {"nso",               "h",            22},
            {"format",            "h",            24},
            {"fold",              "h",            26},
            {"tsort",             "h",            28},
            {"vscode",            "h",            30},
            {"hsfs",              "h",            32},
            {"hsfe",              "h",            34},
            {"hslen",             "h",            36},
            {"hstyp",             "h",            38},
            {"schn",              "h",            40},
            {"hstas",             "h",            42},
            {"hstae",             "h",            44},
            {"htatyp",            "h",            46},
            {"hcorr",             "h",            48},
            {"bgrcv",             "h",            50},
            {"rcvm",              "h",            52},
            {"mfeet",             "h",            54},
            {"polyt",             "h",            56},
            {"vpol",              "h",            58}
};
#endif
