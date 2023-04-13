//
// Created by edc on 12.04.23.
//
#include "Entity/Entity.h"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture) :
    m_x(p_x), m_y(p_y), m_texture(p_texture) {
    m_currentFrame.x = 0;
    m_currentFrame.y = 0;
    m_currentFrame.w = 64;
    m_currentFrame.h = 64;
}

float Entity::getX() const {
    return m_x;
}
float Entity::getY() const {
    return m_y;
}

SDL_Texture* Entity::getTexture() const {
    return m_texture;
}

SDL_Rect Entity::getCurrentFrame() const {
    return m_currentFrame;
}