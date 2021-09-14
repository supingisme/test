#include "SDL.h" /* All SDL App's need this */
#include <stdio.h>

/*
* Return the pixel value at (x, y)
* NOTE: The surface must be locked before calling this!
*/
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    switch(bpp) {
        case 1:
            return *p;
        case 2:
            return *(Uint16 *)p;
        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;
        case 4:
            return *(Uint32 *)p;
        default:
            return 0; /* shouldn't happen, but avoids warnings */
    }
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
        
    getpixel(screen, 12, 12);
    
    printf("Quiting SDL.\n");
    /* Shutdown all subsystems */
    SDL_Quit();
    printf("Quiting....\n");
    exit(0);
}
