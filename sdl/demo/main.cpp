/////////////////// 
//按下ESC（或者点x）退出SDL窗口
//联系我： znln426@163.com 
//再别流年的技术实验室
//http://www.cppblog.com/lf426/ 
/////////////////// 
#include <iostream> 
#include "SDL/SDL.h" 
void pressESCtoQuit(); 
void doSomeLoopThings();
int main(int argc,char* argv[]) 
{ 
    try { 
        if ( SDL_Init(SDL_INIT_VIDEO == -1 )) 
        throw SDL_GetError(); 
    } catch ( const char* s ) { 
        std::cerr << s << std::endl; 
        return -1; 
    } 
    atexit(SDL_Quit); 
    SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE); 
    std::cout << "Program is running, press ESC to quit.\n"; 
    pressESCtoQuit(); 
    std::cout << "GAME OVER" << std::endl; 
    return 0; 
}
void pressESCtoQuit() 
{ 
    std::cout << "pressESCtoQuit() function begin\n"; 
    bool gameOver = false; 
    while( gameOver == false )
    { 
        SDL_Event gameEvent; 
        SDL_PollEvent(&gameEvent); 
        if ( &gameEvent != 0 )
        { 
            if ( gameEvent.type == SDL_QUIT )
            { 
                gameOver = true; 
            } 
            if ( gameEvent.type == SDL_KEYDOWN )
            { 
                if ( gameEvent.key.keysym.sym == SDLK_ESCAPE )
                { 
                gameOver = true; 
                } 
            } 
        }    
        doSomeLoopThings(); 
    }                                               
    return; 
} 
void doSomeLoopThings()
{ 
    std::cout << "."; 
    return; 
}
