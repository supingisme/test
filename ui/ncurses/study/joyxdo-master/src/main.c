

/* System headers. We use the standard C library, C bool, and curses. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <curses.h>

/* Our local headers, in inc/ directory. */
#include "joyevdev.h"
#include "mapper.h"
#include "keyboard.h"


/* character code for escape key, used to determine when user wants to exit
 * program */
#define ESCAPE_KEY      27


static void usage_message(void)
{
    const char message[] = "Usage: joyxdo FILE\n"
        "FILE will typically be a valid profile configuration for your\n"
        "gamepad device. If FILE is not found, joyxdo will read gamepad\n"
        "and build a default configuration profile based on your device.\n";
    printf("%s", message);
}


/* -------------------------------*/
/**
 * @Synopsis  Program start. After loading the systems we're going to use,
 * begin a loop that exits only when user presses escape key. While inside
 * loop, we will poll the joystick and update the screen. On exit, shutdown the
 * various systems so we avoid memory leaks.
 *
 * @Param argc Argument count. Must be 2, or we show the "Usage" message.
 * @Param argv[] Argument vector. We only care about argv[1], which should
 * contain the name of a profile.
 *
 * @Returns   OS exit code.
 */
/* ---------------------------------*/
int main(int argc, char *argv[])
{

    /* Load joystick. If not available, exit and tell user that (apparently) no
     * valid joystick device is plugged in. */
    if (!init_joystick()) {
        fprintf(stderr, "\nCould not load valid joystick.\n");
        return 1;
    }

    /* Assume argument count is two. If not, explain to user how to use this
     * program. Tell OS that everything is fine. */
    if (argc != 2) {
        usage_message();
        kill_joystick();
        return 0;
    }

    /* If profile configuration is not found, generate a default and exit. */
    if (access(argv[1], F_OK ) == -1) {
        printf("Generating default profile: %s\n", argv[1]);
        make_default_joystick_config(argv[1]);
        printf("You'll want to check the default keys set in %s.\n", argv[1]);
        kill_joystick();
        return 0;
    } 

    /* We have found a file by that name, but if it is not a valid
     * configuration file, exit. */
    if (!load_ini(argv[1])) {
        fprintf(stderr, "\nCould not read profile: %s\n", argv[1]);
        kill_joystick();
        return 1;
    }

    /* Ok, we've made it this far. That means we've loaded a valid
     * configuration profile into memory and the joystick is good to go. Set up
     * keyboard mapper system and start ncurses so we can begin pollling
     * joystick. */
    init_mapper();
    initscr();
    noecho();
    cbreak();
    timeout(0);
    print_joystick_info();

    /* Loop until exit key is pressed. While we're looping, check joystick
     * state for update and show user onscreen what's happening. */
    while (getch() != ESCAPE_KEY)
        get_joystick_info();

    /* User has terminated program. Now, shutdown systems and return control to
     * OS with exit code 0. */
    endwin();
    kill_mapper();
    kill_joystick();
    return 0;

}
