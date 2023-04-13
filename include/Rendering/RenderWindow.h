//
// Created by edc on 11.04.23.
//

#ifndef FIRSTGAME_RENDERWINDOW_H
#define FIRSTGAME_RENDERWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity/Entity.h"

class RenderWindow {
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();

    void clear();
    void render(const Entity& p_entity);
    void display();
private:
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr; // uses openGL
};

#endif //FIRSTGAME_RENDERWINDOW_H
