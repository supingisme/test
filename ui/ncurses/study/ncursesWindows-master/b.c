/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 *
 *
 * MIT License
 *
 */


/*
 *
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 13/08/2018 | Creation
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>


/* *** DEFINES AND LOCAL DATA TYPE DEFINATION ****************************************** */
#define STATUS_BAR_1                         "Connected [%s] User [%s]"
#define STATUS_BAR_2                         "[TAB] Next field | [ESC] Exit"

#define STATUS_BAR_1_LINE_N                  (LINES - 1)
#define STATUS_BAR_1_COL_N(__fmt_bar1_srt__) ((COLS - strlen(__fmt_bar1_srt__))/2)

#define STATUS_BAR_2_LINE_N                  (LINES - 2)
#define STATUS_BAR_2_COL_N                   ((COLS - sizeof(STATUS_BAR_2))/2)

#define FMT_STATUS_BAR_1_SZ                  (100)

#define ESC_KEY                              (27)


/* *** LOCAL PROTOTYPES (if applicable) ************************************************ */


/* *** EXTERNS / LOCAL / GLOBALS VARIEBLES ********************************************* */


/* *** FUNCTIONS *********************************************************************** */


/* -------------------------------------------------------------------------------------------------------- */

/* int main(int argc, char *argv[])
 *
 *
 *
 * INPUT:
 * OUTPUT:
 */
int main(int argc, char *argv[])
{
	int cursor = 0;
	int  cKey = 0;
	WINDOW *mainWindow = NULL;
	WINDOW *board[3] = {NULL};
	char fmt_STATUS_BAR_1[FMT_STATUS_BAR_1_SZ +1] = {0};

	mainWindow = initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nonl();

	if(mainWindow == NULL){
		printf("Erro initializating ncurses!\n");
		return(-1);
	}

	if((LINES < 24) || (COLS < 80)){
		endwin();
		printf("O terminal precisa ter no minimo 80x24");
		return(-2);
	}


	if(has_colors() == FALSE){
		endwin();
		printf("Terminal nao suporta cores (has_colors() = FALSE).\n");
		return(-2);
	}

	if(can_change_color() == FALSE){
		endwin();
		printf("Terminal nao suporta mudar as cores (can_change_colors() = FALSE).\n");
		return(-3);
	}

	if(start_color() != OK){
		endwin();
		printf("Erro em iniciar cores (start_colors() = FALSE).\n");
		return(-4);
	}

	set_escdelay(0);

	cursor = curs_set(0);

	do{
		board[0] = newwin(3, 5, 2, 1);
		board[1] = newwin(3, 15, 6, 1);
		board[2] = newwin(4, 30, 10, 1);

		clear();

		mvprintw(0,0, "[%d]", cKey);

		wattron(board[0], A_BOLD);

		box(board[0], 0, 0);
		box(board[1], 0, 0);
		wborder(board[2], '1', '2', '3', '4', '5', '6', '7', '8');

		mvwaddch(board[0], 1, 2, 'a');
		mvwaddch(board[1], 1, 2, 'b');
		mvwprintw(board[2], 1, 2, "%s", "abcdef");


		wattroff(board[0], A_BOLD);

		snprintf(fmt_STATUS_BAR_1, FMT_STATUS_BAR_1_SZ, STATUS_BAR_1, "localhost:666", "Unknow");
		mvprintw(STATUS_BAR_1_LINE_N, STATUS_BAR_1_COL_N(fmt_STATUS_BAR_1), fmt_STATUS_BAR_1);
		mvprintw(STATUS_BAR_2_LINE_N, STATUS_BAR_2_COL_N, STATUS_BAR_2);

		refresh();

		wrefresh(board[0]);
		wrefresh(board[1]);
		wrefresh(board[2]);

		cKey = getch();

		delwin(board[0]);
		delwin(board[1]);
		delwin(board[2]);

	}while(cKey != ESC_KEY);



	curs_set(cursor);
	endwin();

	return(0);
}
