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
        typedef std::map<const char*, Renderer*, cmp_str> Renderers;
        typedef std::map<const char*, Module*, cmp_str> Modules;
        typedef std::map<const char*, Window*, cmp_str> Windows;
        Renderers renderers;
        Modules modules;
        Windows windows;
        Logger* logger;
    public:
        Engine();
        ~Engine();
        void start();
        void addRenderer(Renderer* renderer, const char* name);
        void addModule(Module* module, const char* name);
        void openWindow(const char* name);
        void closeWindow(const char* name);
        Window* getWindow(const char* name);
        Renderer* getRenderer(const char* name);
        Module* getModule(const char* name);
        Logger* getLogger();
    private:
        void iterateRenderers(void (*fun)(Renderer*));
        void iterateModules(void (*fun)(Module*));
        void iterateWindows(void (*fun)(Window*));
        bool isRunning();
    };

} }
