#include <stdio.h>
#include <SDL2/SDL.h>
#include "constands.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int isGameRunning = FALSE;

int initializeWindow(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ){
	fprintf(stderr, "Error initializing SDL,\n");
	return FALSE;
    }

    window = SDL_CreateWindow(
	    "wolfenStein3D",
	    SDL_WINDOWPOS_CENTERED,
	    SDL_WINDOWPOS_CENTERED,
	    WINDOW_WIDTH,
	    WINDOW_HEIGHT,
	    SDL_WINDOW_BORDERLESS
    );

    if(!window){
	fprintf(stderr, "Error creating SDL window.\n");
	return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer){
	fprintf(stderr, "Error creating SDL renderer");
	return FALSE;
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    return TRUE;
}

void destroyWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void processInput(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
	case SDL_QUIT:{
	    isGameRunning = FALSE;
	    break;
	}
	
	case SDL_KEYDOWN: {
	    if(event.key.keysym.sym == SDLK_ESCAPE)
		isGameRunning = FALSE;
		break;
	}

    }
}

void setup(){
    
}

void render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

int main(){
    isGameRunning = initializeWindow();

    setup();

    while(isGameRunning){
	processInput();
	// update();
	render();
    }

    destroyWindow();

    return 0;
}
