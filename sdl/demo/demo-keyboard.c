// typedef struct{
    // Uint8 scancode;
    // SDLKey sym;
    // SDLMod mod;
    // Uint16 unicode;
// } SDL_keysym;

// typedef struct{
    // Uint8 type;
    // Uint8 state;
    // SDL_keysym keysym;
// } SDL_KeyboardEvent;

// SDL_Event event;

// /* Poll for events. SDL_PollEvent() returns 0 when there are no */
// /* more events on the event queue, our while loop will exit when */
// /* that occurs. */
// while( SDL_PollEvent( &event ) ){
    // /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
    // switch( event.type ){
        // case SDL_KEYDOWN:
            // printf( "Key press detected\n" );
            // break;
        // case SDL_KEYUP:
            // printf( "Key release detected\n" );
            // break;
        // default:
            // break;
    // }
// }

#include "SDL.h"

/* Function Prototypes */
void PrintKeyInfo( SDL_KeyboardEvent *key );
void PrintModifiers( SDLMod mod );

/* main */
int main( int argc, char *argv[] ){
    SDL_Event event;
    int quit = 0;
    /* Initialise SDL */
    if( SDL_Init( SDL_INIT_VIDEO ) ){
    fprintf( stderr, "Could not initialise SDL: %s\n", SDL_GetError() );
    exit( -1 );
    }
    /* Set a video mode */
    if( !SDL_SetVideoMode( 320, 200, 0, 0 ) ){
    fprintf( stderr, "Could not set video mode: %s\n", SDL_GetError() );
    SDL_Quit();
    exit( -1 );
    }
    /* Enable Unicode translation */
    SDL_EnableUNICODE( 1 );
    /* Loop until an SDL_QUIT event is found */
    while( !quit ){
        /* Poll for events */
        while( SDL_PollEvent( &event ) ){
            switch( event.type ){
                /* Keyboard event */
                /* Pass the event data onto PrintKeyInfo() */
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    PrintKeyInfo( &event.key );
                    break;
                /* SDL_QUIT event (window close) */
                case SDL_QUIT:
                    quit = 1;
                    break;
                default:
                    break;
            }
        }
    }
    /* Clean up */
    SDL_Quit();
    exit( 0 );
}
/* Print all information about a key event */
void PrintKeyInfo( SDL_KeyboardEvent *key ){
    /* Is it a release or a press? */
    if( key->type == SDL_KEYUP )
        printf( "Release:- " );
    else
        printf( "Press:- " );
    /* Print the hardware scancode first */
    printf( "Scancode: 0x%02X", key->keysym.scancode );
    /* Print the name of the key */
    printf( ", Name: %s", SDL_GetKeyName( key->keysym.sym ) );
    /* We want to print the unicode info, but we need to make */
    /* sure its a press event first (remember, release events */
    /* don't have unicode info */
    if( key->type == SDL_KEYDOWN ){
        /* If the Unicode value is less than 0x80 then the */
        /* unicode value can be used to get a printable */
        /* representation of the key, using (char)unicode. */
        printf(", Unicode: " );
        if( key->keysym.unicode < 0x80 && key->keysym.unicode > 0 ){
            printf( "%c (0x%04X)", (char)key->keysym.unicode,
            key->keysym.unicode );
        }
        else{
            printf( "? (0x%04X)", key->keysym.unicode );
        }
    }
    printf( "\n" );
    /* Print modifier info */
    PrintModifiers( key->keysym.mod );
}


/* Print modifier info */
void PrintModifiers( SDLMod mod )
{
    printf( "Modifers: " );
    /* If there are none then say so and return */
    if( mod == KMOD_NONE ){
        printf( "None\n" );
        return;
    }
    /* Check for the presence of each SDLMod value */
    /* This looks messy, but there really isn't */
    /* a clearer way. */
    if( mod & KMOD_NUM ) printf( "NUMLOCK " );
    if( mod & KMOD_CAPS ) printf( "CAPSLOCK " );
    if( mod & KMOD_LCTRL ) printf( "LCTRL " );
    if( mod & KMOD_RCTRL ) printf( "RCTRL " );
    if( mod & KMOD_RSHIFT ) printf( "RSHIFT " );
    if( mod & KMOD_LSHIFT ) printf( "LSHIFT " );
    if( mod & KMOD_RALT ) printf( "RALT " );
    if( mod & KMOD_LALT ) printf( "LALT " );
    if( mod & KMOD_CTRL ) printf( "CTRL " );
    if( mod & KMOD_SHIFT ) printf( "SHIFT " );
    if( mod & KMOD_ALT ) printf( "ALT " );
    printf( "\n" );
}

/* Alien screen coordinates */
int alien_x=0, alien_y=0;
/* Initialise SDL and video modes and all that */
/* Main game loop */
/* Check for events */
while( SDL_PollEvent( &event ) ){
    switch( event.type ){
        /* Look for a keypress */
        case SDL_KEYDOWN:
            /* Check the SDLKey values and move change the coords */
            switch( event.key.keysym.sym ){
        case SDLK_LEFT:
            alien_x -= 1;
            break;
        case SDLK_RIGHT:
            alien_x += 1;
            break;
        case SDLK_UP:
            alien_y -= 1;
            break;
        case SDLK_DOWN:
            alien_y += 1;
            break;
        default:
            break;
        }
    }
}



/* Alien screen coordinates */
int alien_x=0, alien_y=0;
int alien_xvel=0, alien_yvel=0;
/* Initialise SDL and video modes and all that */
/* Main game loop */
/* Check for events */
while( SDL_PollEvent( &event ) ){
    switch( event.type ){
        /* Look for a keypress */
        case SDL_KEYDOWN:
            /* Check the SDLKey values and move change the coords */
            switch( event.key.keysym.sym ){
                case SDLK_LEFT:
                    alien_xvel = -1;
                    break;
                case SDLK_RIGHT:
                    alien_xvel = 1;
                    break;
                case SDLK_UP:
                    alien_yvel = -1;
                    break;
                case SDLK_DOWN:
                    alien_yvel = 1;
                    break;
                default:
                    break;
            }
            break;
        /* We must also use the SDL_KEYUP events to zero the x */
        /* and y velocity variables. But we must also be */
        /* careful not to zero the velocities when we shouldn't*/
        case SDL_KEYUP:
            switch( event.key.keysym.sym ){
                case SDLK_LEFT:
                    /* We check to make sure the alien is moving */
                    /* to the left. If it is then we zero the */
                    /* velocity. If the alien is moving to the */
                    /* right then the right key is still press */
                    /* so we don't tocuh the velocity */
                    if( alien_xvel < 0 )
                    alien_xvel = 0;
                    break;
                case SDLK_RIGHT:
                    if( alien_xvel > 0 )
                    alien_xvel = 0;
                    break;
                case SDLK_UP:
                    if( alien_yvel < 0 )
                    alien_yvel = 0;
                    break;
                case SDLK_DOWN:
                    if( alien_yvel > 0 )
                    alien_yvel = 0;
                    break;
                default:
                    break;
            }
            break;
        default:
        break;
    }
}
/* Update the alien position */
alien_x += alien_xvel;
alien_y += alien_yvel;