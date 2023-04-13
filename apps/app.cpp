//
// Created by edc on 10.04.23.
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Rendering/RenderWindow.h"
#include "Entity/Entity.h"

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "IMG_Init has failed. Error:" << SDL_GetError() << std::endl;
    }

    RenderWindow window("Ed's First Game!", 1280, 720);

    SDL_Texture* faceTexture = window.loadTexture("../resources/graphics/face.png");

    Entity eddyc(100, 100, faceTexture);

    if (!faceTexture) {
        std::cout << "face texture not found! Error: " << SDL_GetError() << std::endl;
    }
    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameRunning = false;
            }

            window.clear();
            window.render(eddyc);
            window.display();
        }
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}