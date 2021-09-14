#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define ESC_KEY                              (27)

int main(int argc, char *argv[])
{
	int cursor = 0;

	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nonl();

	cursor = curs_set(0);

	mvprintw(0, 0, "ACS_PI: ");
	addch(ACS_PI);
	mvprintw(1, 0, "ACS_ULCORNER: ");
	addch(ACS_ULCORNER);
	mvprintw(2, 0, "ACS_LLCORNER: ");
	addch(ACS_LLCORNER);
	mvprintw(3, 0, "ACS_URCORNER: ");
	addch(ACS_URCORNER);
	mvprintw(4, 0, "ACS_LRCORNER: ");
	addch(ACS_LRCORNER);
	mvprintw(5, 0, "ACS_LTEE: ");
	addch(ACS_LTEE);
	mvprintw(6, 0, "ACS_RTEE: ");
	addch(ACS_RTEE);
	mvprintw(7, 0, "ACS_BTEE: ");
	addch(ACS_BTEE);
	mvprintw(8, 0, "ACS_TTEE: ");
	addch(ACS_TTEE);
	mvprintw(9, 0, "ACS_HLINE: ");
	addch(ACS_HLINE);
	mvprintw(10, 0, "ACS_VLINE: ");
	addch(ACS_VLINE);
	mvprintw(11, 0, "ACS_PLUS: ");
	addch(ACS_PLUS);
	mvprintw(12, 0, "ACS_S1: ");
	addch(ACS_S1);
	mvprintw(13, 0, "ACS_S9: ");
	addch(ACS_S9);
	mvprintw(14, 0, "ACS_DIAMOND: ");
	addch(ACS_DIAMOND);
	mvprintw(15, 0, "ACS_CKBOARD: ");
	addch(ACS_CKBOARD);
	mvprintw(16, 0, "ACS_DEGREE: ");
	addch(ACS_DEGREE);
	mvprintw(17, 0, "ACS_PLMINUS: ");
	addch(ACS_PLMINUS);
	mvprintw(18, 0, "ACS_BULLET: ");
	addch(ACS_BULLET);
	mvprintw(19, 0, "ACS_LARROW: ");
	addch(ACS_LARROW);
	mvprintw(20, 0, "ACS_RARROW: ");
	addch(ACS_RARROW);
	mvprintw(21, 0, "ACS_DARROW: ");
	addch(ACS_DARROW);
	mvprintw(22, 0, "ACS_UARROW: ");
	addch(ACS_UARROW);
	mvprintw(23, 0, "ACS_BOARD: ");
	addch(ACS_BOARD);
	mvprintw(24, 0, "ACS_LANTERN: ");
	addch(ACS_LANTERN);
	mvprintw(25, 0, "ACS_BLOCK: ");
	addch(ACS_BLOCK);
	mvprintw(26, 0, "ACS_S3: ");
	addch(ACS_S3);
	mvprintw(27, 0, "ACS_S7: ");
	addch(ACS_S7);
	mvprintw(28, 0, "ACS_LEQUAL: ");
	addch(ACS_LEQUAL);
	mvprintw(29, 0, "ACS_GEQUAL: ");
	addch(ACS_GEQUAL);
	mvprintw(30, 0, "ACS_NEQUAL: ");
	addch(ACS_NEQUAL);
	mvprintw(31, 0, "ACS_STERLING: ");
	addch(ACS_STERLING);

	refresh();

	getch();


	curs_set(cursor);
	endwin();

	return(0);
}
