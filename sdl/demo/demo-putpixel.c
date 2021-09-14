#include "SDL.h" /* All SDL App's need this */
#include <stdio.h>

/*
* Return the pixel value at (x, y)
* NOTE: The surface must be locked before calling this!
*/
void putpixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    *p = color;
}

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

    /* Have a preference for 8-bit, but accept any depth */
    screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
    if ( screen == NULL ) {
        fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
        SDL_GetError());
        exit(1);
    }
    printf("Set 640x480 at %d bits-per-pixel mode\n",
        screen->format->BitsPerPixel);
        
    /* Code to set a yellow pixel at the center of the screen */
    int x, y;
    Uint32 yellow;
    /* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
    Note: If the display is palettized, you must set the palette first.
    */
    yellow = SDL_MapRGB(screen->format, 0xff, 0xff, 0x00);
    x = screen->w / 2;
    y = screen->h / 2;
    /* Lock the screen for direct access to the pixels */
    if ( SDL_MUSTLOCK(screen) ) {
        if ( SDL_LockSurface(screen) < 0 ) {
            fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
            return;
        }
    }
    putpixel(screen, x, y, yellow);
    if ( SDL_MUSTLOCK(screen) ) {
        SDL_UnlockSurface(screen);
    }
    
    /* Update just the part of the display that we've changed */
    SDL_UpdateRect(screen, x, y, 1, 1);
    
    sleep(4);

    printf("Quiting SDL.\n");
    /* Shutdown all subsystems */
    SDL_Quit();
    printf("Quiting....\n");
    exit(0);
}
