//
// Created by edc on 10.04.23.
//
#include "App/App.h"
#include <stdexcept>
#include <iostream>

int main(int argc, char* args[]) {

    App* app = nullptr;

    try {
        app = new App(1080, 720);
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    if (app) {
        delete app;
    }
    return 0;
}