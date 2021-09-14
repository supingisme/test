#include "SDL.h" /* All SDL App's need this */
#include <stdio.h>

void display_bmp(char *file_name)
{
    SDL_Surface *image;
    SDL_Surface *screen;
    
    /* Load the BMP file into a surface */
    image = SDL_LoadBMP(file_name);
    if (image == NULL) {
        fprintf(stderr, "Couldn't load %s: %s\n", file_name, SDL_GetError());
        return;
    }
    /* Have a preference for 8-bit, but accept any depth */
    screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
    if ( screen == NULL ) {
        fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
        SDL_GetError());
        exit(1);
    }
    printf("Set 640x480 at %d bits-per-pixel mode\n",
        screen->format->BitsPerPixel);
        
    /*
    * Palettized screen modes will have a default palette (a standard
    * 8*8*4 colour cube), but if the image is palettized as well we can
    * use that palette for a nicer colour matching
    */
    if (image->format->palette && screen->format->palette) {
        SDL_SetColors(screen, image->format->palette->colors, 0,
        image->format->palette->ncolors);
    }
    /* Blit onto the screen surface */
    if(SDL_BlitSurface(image, NULL, screen, NULL) < 0)
        fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());
    
    SDL_UpdateRect(screen, 0, 0, image->w, image->h);
    
    /* Free the allocated BMP surface */
    SDL_FreeSurface(image);
    
    sleep(2);
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

    display_bmp("a.bmp");
    
    printf("Quiting SDL.\n");
    /* Shutdown all subsystems */
    //SDL_Quit();
    printf("Quiting....\n");
    exit(0);
}
