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
    
    /* Have a preference for 8-bit, but accept any depth */
    screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
    if ( screen == NULL ) {
        fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
        SDL_GetError());
        exit(1);
    }
    printf("Set 640x480 at %d bits-per-pixel mode\n",
        screen->format->BitsPerPixel);

    printf("Quiting SDL.\n");
    /* Shutdown all subsystems */
    //SDL_Quit();
    printf("Quiting....\n");
    exit(0);
}
