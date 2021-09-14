#include "SDL.h" /* All SDL App's need this */
#include <stdio.h>

int main() 
{
    printf("Initializing SDL.\n");
    /* Initialize defaults, Video and SDL_INIT_JOYSTICK */
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)==-1)) 
	{
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
    printf("SDL initialized.\n");
    
    printf("%i joysticks were found.\n\n", SDL_NumJoysticks() );
    printf("The names of the joysticks are:\n");
    
    int i;
    for( i=0; i < SDL_NumJoysticks(); i++ )
    {
        printf(" %s\n", SDL_JoystickName(i));
    }
    
    SDL_Joystick *joystick;
    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);
    
    SDL_Event event;
    /* Other initializtion code goes here */
    /* Start main game loop here */
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
                /* handle keyboard stuff here */
                break;
            case SDL_QUIT:
                /* Set whatever flags are necessary to */
                /* end the main game loop here */
                break;
            case SDL_JOYAXISMOTION: /* Handle Joystick Motion */
                if ( ( event.jaxis.value < -3200 ) || (event.jaxis.value > 3200 ) )
                {
                    if( event.jaxis.axis == 0)
                    {
                        /* Left-right movement code goes here */
                    }
                    if( event.jaxis.axis == 1)
                    {
                        /* Up-Down movement code goes here */
                    }
                }
                break;
            case SDL_JOYBUTTONDOWN: /* Handle Joystick Button Presses */
                if ( event.jbutton.button == 0 )
                {
                    /* code goes here */
                }
                break;
            case SDL_JOYBALLMOTION: /* Handle Joyball Motion */
                if( event.jball.ball == 0 )
                {
                    /* ball handling */
                }
                break;
            /*
            SDL_HAT_CENTERED
            SDL_HAT_UP
            SDL_HAT_RIGHT
            SDL_HAT_DOWN
            SDL_HAT_LEFT
            */
            /*
            SDL_HAT_RIGHTUP
            SDL_HAT_RIGHTDOWN
            SDL_HAT_LEFTUP
            SDL_HAT_LEFTDOWN
            */
            case SDL_JOYHATMOTION: /* Handle Hat Motion */
                if ( event.jhat.hat | SDL_HAT_UP )
                {
                    /* Do up stuff here */
                }
                if ( event.jhat.hat | SDL_HAT_LEFT )
                {
                    /* Do left stuff here */
                }
                if ( event.jhat.hat | SDL_HAT_RIGHTDOWN )
                {
                    /* Do right and down together stuff here */
                }
                break;
        }
    }
    
    /*这个代码将会得到第一个控制杆的按钮个数。*/
    int number_of_buttons = SDL_JoystickNumButtons(joystick);
    
    /* End loop here */
    SDL_JoystickClose(joystick);
    
    
    printf("Quiting SDL.\n");
    /* Shutdown all subsystems */
    SDL_Quit();
    printf("Quiting....\n");
    exit(0);
}
