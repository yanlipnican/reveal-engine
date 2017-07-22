//
// Created by yan on 15.7.17.
//

#pragma once

#include <string>

#include "src/OpenGL.h"

namespace Engine { namespace Core {

    class Window {
    private:
        GLFWwindow* window;
    public:
        Window(const char* title);
        ~Window();
        void bind();
        void pollEvents();
        void swapBuffers();
        bool shouldClose();
        GLFWwindow* getWindow();
        void close();
    };

} }


