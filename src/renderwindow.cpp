#include "../include/renderwindow.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstdio>

RenderWindow::RenderWindow(const char* p_title,int p_w,int p_h) :
  win(nullptr),ren(nullptr)
{
  win = SDL_CreateWindow(p_title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);
  if(win == nullptr) {
    fprintf(stderr, "Window Creation error : %s\n",SDL_GetError());
  }
  ren = SDL_CreateRenderer(win, -1,SDL_RENDERER_ACCELERATED);
}

void RenderWindow::destroy() {
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
}
void RenderWindow::clear_screen() {
  SDL_SetRenderDrawColor(ren, 128,128,128,128);
  SDL_RenderClear(ren);
}
void RenderWindow::display() {
  SDL_RenderPresent(ren);
}

SDL_Texture* RenderWindow::loadTexture(const char *p_fileName) {
  SDL_Texture* texture = nullptr;
  texture = IMG_LoadTexture(ren,p_fileName);
  if(texture == nullptr) {
    fprintf(stderr,"failed to load texture!\n");
  }
  return texture;
}

void RenderWindow::render(SDL_Texture *p_tex) {
  SDL_RenderCopy(ren,p_tex,nullptr,nullptr);
}

