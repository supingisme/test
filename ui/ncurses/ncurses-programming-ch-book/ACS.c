/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:53 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 14日 星期四 19:25:16 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 08日 星期五 08:10:57 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 07日 星期四 20:28:26 CST. */
#include<ncurses.h>
int main()
{
    initscr();
    printw("Upperleft corner ");addch(ACS_ULCORNER); printw("\n");
    printw("Lowerleft corner ");addch(ACS_LLCORNER); printw("\n");
    printw("Lowerrightcorner ");addch(ACS_LRCORNER); printw("\n");
    printw("Teepointingright ");addch(ACS_LTEE);printw("\n");
    printw("Teepointingleft ");addch(ACS_RTEE);printw("\n");
    printw("Teepointingup ");addch(ACS_BTEE); printw("\n");
    printw("Teepointingdown ");addch(ACS_TTEE);printw("\n");
    printw("Horizontalline ");addch(ACS_HLINE); printw("\n");
    printw("Verticalline ");addch(ACS_VLINE); printw("\n");
    printw("LargePlus orcross over ");addch(ACS_PLUS); printw("\n");
    printw("ScanLine1 ");addch(ACS_S1);printw("\n");
    printw("ScanLine3 ");addch(ACS_S3);printw("\n");
    printw("ScanLine7 ");addch(ACS_S7);printw("\n");
    printw("ScanLine9 ");addch(ACS_S9);printw("\n");
    printw("Diamond ");addch(ACS_DIAMOND);printw("\n");
    printw("Checkerboard(stipple) ");addch(ACS_CKBOARD); printw("\n");
    printw("DegreeSymbol ");addch(ACS_DEGREE); printw("\n");
    printw("Plus/MinusSymbol ");addch(ACS_PLMINUS); printw("\n");
    printw("Bullet ");addch(ACS_BULLET);printw("\n");
    printw("ArrowPointingLeft ");addch(ACS_LARROW); printw("\n");
    printw("ArrowPointingRight ");addch(ACS_RARROW); printw("\n");
    printw("ArrowPointingDown ");addch(ACS_DARROW); printw("\n");
    printw("ArrowPointingUp ");addch(ACS_UARROW); printw("\n");
    printw("Boardof squares ");addch(ACS_BOARD); printw("\n");
    printw("LanternSymbol ");addch(ACS_LANTERN); printw("\n");
    printw("SolidSquareBlock ");addch(ACS_BLOCK); printw("\n");
    printw("Less/Equalsign ");addch(ACS_LEQUAL); printw("\n");
    printw("Greater/Equalsign ");addch(ACS_GEQUAL); printw("\n");
    printw("Pi ");addch(ACS_PI);printw("\n");
    printw("Notequal ");addch(ACS_NEQUAL);printw("\n");
    printw("UKpoundsign ");addch(ACS_STERLING);printw("\n");
    refresh();
    getch();
    endwin();
    return 0;
}