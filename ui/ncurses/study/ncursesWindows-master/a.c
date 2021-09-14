#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define ESC_KEY                              (27)

int main(int argc, char *argv[])
{
	int cursor = 0;
	WINDOW *board = NULL;

	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nonl();

	cursor = curs_set(0);

	board = newwin(10, 10, 1, 1);

	box(board, 0, 0);

	refresh();
	wrefresh(board);

	getch();

	delwin(board);

	curs_set(cursor);
	endwin();

	return(0);
}
