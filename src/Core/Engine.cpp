//
// Created by yan on 15.7.17.
//

#include <src/Core/Loggers/ConsoleLogger.h>
#include <iostream>
#include <src/Core/Timing.h>
#include "Module.h"
#include "Window.h"

#include <chrono>
#include <thread>

#define FPS_CAP 120.0f

using namespace Engine::Modules;

static Timing* timing;

namespace Engine { namespace Core {

    static inline void initModule(Module* module) {module->init();}
    static inline void updateModule(Module* module) {module->update();}

    Engine::Engine() {
        setupGL();
        // core modules
        timing = (Timing*)addModule(new Timing(this), "Timing");
    }

    Engine::~Engine() {
        glfwTerminate();
    }

    void Engine::iterateModules(void (*fun)(Module *)) {
        for(Modules::iterator iterator = modules.begin(); iterator != modules.end(); iterator++) {
            fun(iterator->second);
        }
    }

    void Engine::iterateWindows(void (*fun)(Window *)) {
        for(Windows::iterator iterator = windows.begin(); iterator != windows.end(); iterator++) {
            fun(iterator->second);
        }
    }

    void Engine::compensateSleep() {
        std::this_thread::sleep_for(std::chrono::milliseconds((long)(1000.0f / FPS_CAP - timing->delta())));
    }

    void Engine::start() {
        iterateModules(initModule);
        Window* window = getWindow("Engine");
        window->bind();
        glClearColor(0.2f, 0.2f, 0.3f, 0.0f);
        while (isRunning()) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            iterateModules(updateModule);
            window->swapBuffers();
            window->pollEvents();
            //compensateSleep();
        }
    }

    bool Engine::isRunning() {
        // close if all windows are closed
        return closeWindows();
    }

    Module* Engine::addModule(Module *module, const char* name) {
        modules[name] = module;
        return module;
    }

    Module *Engine::getModule(const char* name) {
        return modules[name];
    }

    Window *Engine::getWindow(const char* name) {
        return windows[name];
    }

    Window * Engine::openWindow(const char *name) {
        auto window = new Window(name);
        windows[name] = window;
        return window;
    }

    void Engine::closeWindow(const char* name) {
        delete windows[name];
    }

    bool Engine::setupGL() {
        // Initialise GLFW
        if( !glfwInit() )
        {
            return false;
        }

        glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
        Window* window = openWindow("Engine");
        glfwMakeContextCurrent(window->getWindow());
        glewExperimental=true;
        //glfwSwapInterval(1);
        if (glewInit() != GLEW_OK) {
            return false;
        }
        return true;
    }

        bool Engine::closeWindows() {
            for(auto it = windows.cbegin(); it != windows.cend();) {
                if (it->second->shouldClose()) {
                    delete it->second;
                    windows.erase(it);
                } else {
                    it++;
                }
            }
            return windows.size() > 0;
        }


    } }