/* Information about the current video settings. */
const SDL_VideoInfo* info = NULL;
/* Dimensions of our window. */
int width = 0;
int height = 0;
/* Color depth in bits of our window. */
int bpp = 0;
/* Flags we will pass into SDL_SetVideoMode. */
int flags = 0;
/* First, initialize SDL's video subsystem. */
if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    /* Failed, exit. */
    fprintf( stderr, "Video initialization failed: %s\n",
    SDL_GetError( ) );
    quit_tutorial( 1 );
}
/* Let's get some video information. */
info = SDL_GetVideoInfo( );
if( !info ) {
    /* This should probably never happen. */
    fprintf( stderr, "Video query failed: %s\n",
    SDL_GetError( ) );
    quit_tutorial( 1 );
}
/*
* Set our width/height to 640/480 (you would
* of course let the user decide this in a normal
* app). We get the bpp we will request from
* the display. On X11, VidMode can't change
* resolution, so this is probably being overly
* safe. Under Win32, ChangeDisplaySettings
* can change the bpp.
*/
width = 640;
height = 480;
bpp = info->vfmt->BitsPerPixel;
/*
* Now, we want to setup our requested
* window attributes for our OpenGL window.
* We want *at least* 5 bits of red, green
* and blue. We also want at least a 16-bit
* depth buffer.
*
* The last thing we do is request a double
* buffered window. '1' turns on double
* buffering, '0' turns it off.
*
* Note that we do not use SDL_DOUBLEBUF in
* the flags to SDL_SetVideoMode. That does
* not affect the GL attribute state, only
* the standard 2D blitting setup.
*/
SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
/*
* We want to request that SDL provide us
* with an OpenGL window, in a fullscreen
* video mode.
*
* EXERCISE:
* Make starting windowed an option, and
* handle the resize events properly with
* glViewport.
*/
flags = SDL_OPENGL | SDL_FULLSCREEN;

/*
* Set the video mode
*/
if( SDL_SetVideoMode( width, height, bpp, flags ) == 0 ) {
    /*
    * This could happen for a variety of reasons,
    * including DISPLAY not being set, the specified
    * resolution not being available, etc.
    */
    fprintf( stderr, "Video mode set failed: %s\n",
    SDL_GetError( ) );
    quit_tutorial( 1 );
}