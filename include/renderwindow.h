#ifndef RENDERWINDOW_H__
#define RENDERWINDOW_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
  public:
    RenderWindow(const char* p_title,int p_w,int p_h);
    SDL_Texture* loadTexture(const char* p_fileName);
    void destroy();
    void clear_screen();
    void render(SDL_Texture* p_tex);
    void display();
  private:
    SDL_Window* win;
    SDL_Renderer* ren;
};


#endif // RENDERWINDOW_H__
