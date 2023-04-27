//
// Created by edc on 23.04.23.
//

#ifndef FIRSTGAME_APP_H
#define FIRSTGAME_APP_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glad/glad.h>

class App {

private:
    int mScreenWidth = 0;
    int mScreenHeight = 0;
    SDL_Window* mGraphicsApplicationWindow = nullptr;
    SDL_GLContext mOpenGLContext = nullptr;
    bool mRunning = false; // if false we quit

public:
    App() = delete;
    App(int screenWidth = 1080, int screenHeight = 720);

    App(const App&) = delete;
    App(const App&&) = delete;
    App& operator=(const App&) = delete;
    App& operator=(const App&&) = delete;

    ~App();

private:
    void init();

    void vertexSpecification();
    void mainLoop() noexcept;
    void createGraphicsPipeline();
    void pollInput() noexcept;
    void preDraw() noexcept;
    void draw() noexcept;
public:


};

#endif //FIRSTGAME_APP_H
