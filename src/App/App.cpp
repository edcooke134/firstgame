//
// Created by edc on 23.04.23.
//
#include "App/App.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <fstream>

// VAO's encapsulate all of the items needed to render an object. For example, we could reference multiple vertex buffers.
GLuint gVertexArrayObject = 0;

// VBO's store info relating to specifically vertices (e.g. position, normals, textures). These are our mechanisms for
// arranging geometry on the GPU.
GLuint gVertexBufferObject = 0;
GLuint gVertexBufferObject2 = 0;

// ID for the program object for shaders ( graphics pipeline)
GLuint gGraphicsPipelineShaderProgram = 0;

// ######################################################################################################################
App::App(int screenWidth, int screenHeight) : mScreenWidth(screenWidth), mScreenHeight(screenHeight) {
    // setup graphics program
    try {
        init();
        // setup geometry
        vertexSpecification();
        // create our graphics pipeline (vertex and fragment shader at a minimum - for position and color resp.)
        createGraphicsPipeline();
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    // main application loop
    mainLoop();
}

void App::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error("Could not initialise SDL video subsystem. Error: " + std::string(SDL_GetError()));
    }

    // set minimum version of OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    // don't allow old OpenGL code to be available
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // turn on double buffering (having two frame buffers, one to display and one to build - allows smooth transitioning between frames)
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // minimum number of bits in the depth buffer (buffer used to represent depth information in 3D space)
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    mGraphicsApplicationWindow = SDL_CreateWindow("I spawned this window!", 0, 0, mScreenWidth, mScreenHeight, SDL_WINDOW_OPENGL);
    if (!mGraphicsApplicationWindow) {
        throw std::runtime_error("Window failed to init. Error: " + std::string(SDL_GetError()));
    }

    mOpenGLContext = SDL_GL_CreateContext(mGraphicsApplicationWindow);
    if (!mOpenGLContext) {
        throw std::runtime_error("OpenGL Context failed to init. Error: " + std::string(SDL_GetError()));
    }

    // init glad lib
    // getProcAddress gets an openGL function by name. Glad library is just loading up a bunch of glad function pointers.
    if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
        throw std::runtime_error("Failed to load Glad library." + std::string(SDL_GetError()));
    }

    mRunning = true;

    std::cout << "successfully initialised." << std::endl;
    // add some logs
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void App::vertexSpecification() {
    // cpu setup
    const std::vector<GLfloat> vertexPositions {
        // openGL co-ordinate system is [-1, 1]
        // x     y     z
        -0.8f, -0.8f, 0.0f,  // vertex 1
        0.8f, -0.8f, 0.0f,   // vertex 2
        0.0f, 0.8f, 0.0f     // vertex 3
    };
    const std::vector<GLfloat> vertexColors {
            // rgb system is [0, 1]
            // r     g     b
            1.0f, 0.0f, 0.0f,  // vertex 1
            0.0f, 1.0f, 0.0f,  // vertex 2
            0.0f, 0.0f, 1.0f   // vertex 3
    };

    // gpu setup

    glGenVertexArrays(1, &gVertexArrayObject);
    glBindVertexArray(gVertexArrayObject);

    // start generating our VBOs
    glGenBuffers(1, &gVertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject); // we must specify what target we bind too
    glBufferData(GL_ARRAY_BUFFER,
                 vertexPositions.size() * sizeof(GLfloat),
                 vertexPositions.data(),
                 GL_STATIC_DRAW
                 );

    // this attribute array will tell openGL how our data is organised
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,                // Attribute 0 corresponds to the enabled glEnableVertexAttribArray
                          3,
                          GL_FLOAT,         // type
                          GL_FALSE,         // is the data normalised
                          0,                // stride
                          (void*)0          // offset
                          );

    glGenBuffers(1, &gVertexBufferObject2);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject2); // we must specify what target we bind too
    glBufferData(GL_ARRAY_BUFFER,
                 vertexColors.size() * sizeof(GLfloat),
                 vertexColors.data(),
                 GL_STATIC_DRAW
    );

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,                // Attribute 1 corresponds to the enabled glEnableVertexAttribArray
                          3,
                          GL_FLOAT,         // type
                          GL_FALSE,         // is the data normalised
                          0,                // stride
                          (void*)0          // offset
                          );
    // cleanup
    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void App::mainLoop() noexcept {
    while (mRunning) {
        pollInput();

        preDraw();

        draw();

        // redraw
        SDL_GL_SwapWindow(mGraphicsApplicationWindow);
    }
}

namespace {

    std::string loadShaderAsString(const std::string& filename) {
        std::string result = "";
        std::string line = "";
        std::ifstream myFile(filename.c_str());

        if (myFile.is_open()) {
            while (std::getline(myFile, line)) {
                result += line + '\n';
            }
            myFile.close();
        } else {
            throw std::runtime_error("Can't load shader with file name: " + filename);
        }
        return result;
    }

    GLuint compileShader(GLuint type, const std::string& source) {
        GLuint shaderObject;

        if (type == GL_VERTEX_SHADER) {
            shaderObject = glCreateShader(GL_VERTEX_SHADER);
        } else if (type == GL_FRAGMENT_SHADER) {
            shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
        }

        const char* str = source.c_str();
        glShaderSource(shaderObject, 1, &str, nullptr);
        glCompileShader(shaderObject);

        int result = -1;

        glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &result);

        if (result == GL_FALSE) {
            int length = -1;
            glGetShaderiv(shaderObject, GL_INFO_LOG_LENGTH, &length);
            char* errorMsg = new char[length];
            glGetShaderInfoLog(shaderObject, length, &length, errorMsg);

            std::string error;
            if (type == GL_VERTEX_SHADER) {
                error = "ERROR: GL_VERTEX_SHADER compilation failed!\n" + std::string(errorMsg);
            } else if (type == GL_FRAGMENT_SHADER) {
                error = "ERROR: GL_FRAGMENT_SHADER compilation failed!\n" + std::string(errorMsg);
            }

            delete[] errorMsg;

            glDeleteShader(shaderObject);

            throw std::runtime_error(std::move(error));
        }

        return shaderObject;
    }

    GLuint createShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
        GLuint programObject = glCreateProgram();

        GLuint myVertexShader;
        GLuint myFragmentShader;
        try {
            myVertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
            myFragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
        }
        catch (std::runtime_error& e) {
            throw std::runtime_error(e.what());
        }

        glAttachShader(programObject, myVertexShader);
        glAttachShader(programObject, myFragmentShader);
        glLinkProgram(programObject);

        // validate program
        glValidateProgram(programObject);

        glDetachShader(programObject, myVertexShader);
        glDetachShader(programObject, myFragmentShader);

        glDeleteShader(myVertexShader);
        glDeleteShader(myFragmentShader);

        return programObject;
    }
}

void App::createGraphicsPipeline() {
    try {
        // vertex shader: executes once per vertex, and dictates the final position of the vertex
        std::string vertexShaderSource = loadShaderAsString("./../resources/shaders/vert.glsl");

        // fragment shader: executes once per fragment (pixels that are rasterised
        // determines the final color sent to the screen (kinda)
        std::string fragmentShaderSource = loadShaderAsString("./../resources/shaders/frag.glsl");
        gGraphicsPipelineShaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);
    }
    catch (std::runtime_error& e) {
        throw std::runtime_error(e.what());
    }
}

void App::pollInput() noexcept {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            mRunning = false;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            std::cout << "Oi!" << std::endl;
        }
    }
}

void App::preDraw() noexcept {
    // sets openGL state

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0,0, mScreenWidth, mScreenHeight);
    glClearColor(1.f,1.f,0.f,1.f);

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glUseProgram(gGraphicsPipelineShaderProgram);
}

void App::draw() noexcept {
    glBindVertexArray(gVertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

App::~App() {
    SDL_DestroyWindow(mGraphicsApplicationWindow);
    // automatically shut down all active subsystems
    SDL_Quit();
}