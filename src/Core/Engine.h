//
// Created by yan on 15.7.17.
//

#pragma once

#include <map>
#include <cstring>
#include "Renderer.h"
#include "Window.h"
#include "Module.h"
#include "Logger.h"

#include "src/OpenGL.h"

namespace Engine { namespace Core {

    class Module;

    struct cmp_str
    {
        bool operator()(char const *a, char const *b)
        {
            return std::strcmp(a, b) < 0;
        }
    };

    class Engine {
    private:
        typedef std::map<const char*, Module*, cmp_str> Modules;
        typedef std::map<const char*, Window*, cmp_str> Windows;
        Modules modules;
        Windows windows;
        bool setupGL();
    public:
        Engine();
        ~Engine();
        void start();
        void addModule(Module* module, const char* name);
        Window * openWindow(const char *name);
        void closeWindow(const char* name);
        Window* getWindow(const char* name);
        Module* getModule(const char* name);
    private:
        void iterateModules(void (*fun)(Module*));
        void iterateWindows(void (*fun)(Window*));
        bool isRunning();
        bool closeWindows();
    };

} }
