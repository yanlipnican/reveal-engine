//
// Created by yan on 15.7.17.
//

#pragma once

#include <map>
#include "Renderer.h"
#include "Window.h"

namespace Engine::Core {

    class Module {
    protected:
        Engine* engine;
    public:
        Module(Engine* engine): engine(engine) {};
        virtual void init() = 0;
        virtual void update() = 0;
    };

    class Engine {
    private:
        typedef std::map<std::string, Renderer*> Renderers;
        typedef std::map<std::string, Module*> Modules;
        typedef std::map<std::string, Window*> Windows;
        Renderers renderers;
        Modules modules;
        Windows windows;
    public:
        Engine();
        ~Engine();
        void start();
        void addRenderer(Renderer* renderer, std::string name);
        void addModule(Module* module, std::string name);
        Renderer* getRenderer(std::string name);
        Module* getModule(std::string name);
        Window* getWindow(std::string name);
    private:
        void iterateRenderers(void (*fun)(Renderer*));
        void iterateModules(void (*fun)(Module*));
        void iterateWindows(void (*fun)(Window*));
        bool isRunning();
    };

}

