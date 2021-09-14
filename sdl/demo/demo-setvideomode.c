#include "SDL.h" /* All SDL App's need this */
#include <stdio.h>

int main() 
{
    printf("Initializing SDL.\n");
    /* Initialize defaults, Video and Audio */
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) 
	{
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
    printf("SDL initialized.\n");
    
    SDL_Surface *screen;
        
    /* Clean up on exit */
    atexit(SDL_Quit);
    /*
     * Initialize the display in a 640x480 8-bit palettized mode,
     * requesting a software surface
     */
    screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE);
    if ( screen == NULL ) 
	{
        fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
        SDL_GetError());
        exit(1);
    }

    printf("Quiting SDL.\n");
    /* Shutdown all subsystems */
    SDL_Quit();
    printf("Quiting....\n");
    exit(0);
}
