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
#include <signal.h>
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

void signalHandle(int sig)
{
	switch(sig){
		case SIGWINCH:
			break;
		default:
			break;
	}
}

/* int main(int argc, char *argv[])
 *
 * INPUT:
 * OUTPUT (to SO):
 */
int main(int argc, char *argv[])
{
#define FIELD1_SZ 50
#define FIELD2_SZ 30

	int cursor = 0;
	int cKey = 0;
	int lineCenter = 0, colCenter = 0;
	int win0_maxx = 0, win0_maxy = 0;
	char fmt_STATUS_BAR_1[FMT_STATUS_BAR_1_SZ +1] = {0};
	char *msg = NULL;
	char field1[FIELD1_SZ] = {'\0'}, field2[FIELD2_SZ] = {'\0'};
	WINDOW *board[3] = {NULL};

	if(initscr() == NULL){;
		printf("Erro initializating ncurses!\n");
		return(-1);
	}
	keypad(stdscr, TRUE);
	cbreak();
	noecho();

	/* https://invisible-island.net/ncurses/ncurses-intro.html */
	/* signal(SIGWINCH, signalHandle); */
	/* TODO: configurar o SCREEN RESIZE para nao ser recebido como user input: KEY_RESIZE */

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
		int keyResize = 0;
		lineCenter = LINES/2;
		colCenter = COLS/2;

		clear();

		snprintf(fmt_STATUS_BAR_1, FMT_STATUS_BAR_1_SZ, STATUS_BAR_1, "localhost:666", "Unknow");
		mvwprintw(stdscr, STATUS_BAR_1_LINE_N, STATUS_BAR_1_COL_N(fmt_STATUS_BAR_1), fmt_STATUS_BAR_1);
		mvwprintw(stdscr, STATUS_BAR_2_LINE_N, STATUS_BAR_2_COL_N, STATUS_BAR_2);
		refresh();
		wrefresh(stdscr);

		board[0] = newwin(10+10, 40+40, lineCenter-10, colCenter-40);
		win0_maxx = getmaxx(board[0]);
		win0_maxy = getmaxy(board[0]);
		/*
		board[1] = newwin(3, 15, 6, 1);
		board[2] = newwin(4, 30, 10, 1);
		*/

		wattron(board[0], A_BOLD);

		box(board[0], 0, 0);

		wattroff(board[0], A_BOLD);

		/*
		box(board[1], 0, 0);
		wborder(board[2], '1', '2', '3', '4', '5', '6', '7', '8');
		*/
		msg = "Title 1";
		wattron(board[0], A_UNDERLINE);
		mvwprintw(board[0], 1, ((win0_maxx-strlen(msg))/2), msg);
		wattroff(board[0], A_UNDERLINE);

		mvwprintw(board[0], 4, 2, "Field 1:");
		mvwprintw(board[0], 5, 2, "Field 2:");

		echo();
		curs_set(2);

		refresh();
		wrefresh(board[0]);

		keyResize = !KEY_RESIZE;
		do{
			keyResize = mvwgetnstr(board[0], 4, 2+sizeof("Field 1:"), field1, FIELD1_SZ);
		}while(keyResize == KEY_RESIZE);

		keyResize = !KEY_RESIZE;
		do{
			keyResize = mvwgetnstr(board[0], 5, 2+sizeof("Field 2:"), field2, FIELD2_SZ);
		}while(keyResize == KEY_RESIZE);

		/*
		mvwaddch(board[1], 1, 2, 'b');
		mvwprintw(board[2], 1, 2, "%s", "abcdef");
		*/

		mvwprintw(board[0], 8, 2, "Enter 1: [%s]", field1);
		mvwprintw(board[0], 9, 2, "Enter 2: [%s]", field2);


		mvwprintw(board[0], 12, 2, "[ESC] to exit");

		curs_set(0);

		refresh();
		wrefresh(board[0]);

		/*
		wrefresh(board[1]);
		wrefresh(board[2]);
		*/


		cKey = getch();

		delwin(board[0]);
		/*
		delwin(board[1]);
		delwin(board[2]);
		*/

	}while(cKey != ESC_KEY);



	curs_set(cursor);
	endwin();

	return(0);
}
