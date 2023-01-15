#include <SDL2/SDL_render.h>
#include <iostream>
#include <SDL2/SDL.h>
#include "../include/renderwindow.h"


int main(int argc,char** argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  auto window = RenderWindow("GAME v1.0",1280,720);
  SDL_Texture* cat = window.loadTexture("assets/cat.png");
  bool gameRunning = true;
  while(gameRunning) {
    SDL_Event ev;
    while(SDL_PollEvent(&ev)) {
      if (ev.type == SDL_QUIT) gameRunning = false;
    }
    window.clear_screen();
    window.render(cat);
    window.display();
  }
  window.destroy();
  SDL_DestroyTexture(cat);
  SDL_Quit();
  return 0;
}
