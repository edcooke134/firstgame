//
// Created by edc on 12.04.23.
//

#ifndef FIRSTGAME_ENTITY_H
#define FIRSTGAME_ENTITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
private:
    float m_x, m_y = 0.;
    SDL_Rect m_currentFrame;
    SDL_Texture* m_texture = nullptr;
public:
    Entity() = default;
    Entity(float p_x, float p_y, SDL_Texture* p_texture);

    float getX() const;
    float getY() const;
    SDL_Texture* getTexture() const;
    SDL_Rect getCurrentFrame() const;

};

#endif //FIRSTGAME_ENTITY_H
