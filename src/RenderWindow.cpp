//
// Created by edc on 11.04.23.
//

#include "Rendering/RenderWindow.h"
#include <iostream>

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h) {
    m_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if (!m_window) {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(m_renderer, p_filePath);
    if (!texture) {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(m_window);
}

void RenderWindow::clear() {
    SDL_RenderClear(m_renderer);
}
void RenderWindow::render(const Entity& p_entity) {

    // the source rect is the part of the texture we want (useful for storyboard textures)
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    // texture fills this destination rect
    SDL_Rect dst;
    dst.x = p_entity.getX();
    dst.y = p_entity.getY();
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(m_renderer, p_entity.getTexture(), nullptr, &dst);
}
void RenderWindow::display() {
    SDL_RenderPresent(m_renderer);
}