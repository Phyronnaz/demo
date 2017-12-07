#include <string>
#include <iostream>
#include <signal.h>
#include <cassert>
#include <SDL.h>

#include "screen.hpp"

namespace rt {

int screen::initialized = 0;
SDL_Surface *screen::buffer = NULL;

static void sigint_handler(int)
{
    exit(0);
}

screen::screen(int width, int height)
{
    std::clog << "Screen created: " << initialized << std::endl;
    if(initialized == 0) {
        if(SDL_Init(SDL_INIT_VIDEO) == -1)
        {
            std::cerr << "Cannot initialize SDL: "
                      << SDL_GetError() << std::endl;
            exit(-1);
        }
        signal(SIGINT,sigint_handler);
        data = SDL_SetVideoMode(width, height, 24,
                                (SDL_HWSURFACE
                                 | SDL_DOUBLEBUF
                                 | SDL_ANYFORMAT));
        buffer = data;
    } else {
        data = buffer;
    }
    initialized += 1;
}

screen::~screen()
{
    initialized -= 1;
    if(initialized == 0) {
        data = NULL;
        buffer = NULL;
        SDL_Quit();
    }
}

void screen::update()
{
    if(data != NULL) {
        assert(SDL_Flip(data) == 0);
        std::clog << "Flip data = " << data << std::endl;
    }
}

bool screen::wait_quit_event()
{
    SDL_Event event;
    while(SDL_WaitEvent(&event)) {
        switch(event.type) {
        case SDL_QUIT:
            return true;
            break;
        }
    }
    return false;
}

}
