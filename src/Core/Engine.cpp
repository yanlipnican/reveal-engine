//
// Created by yan on 15.7.17.
//

#include <src/Core/Renderers/Renderer2D.h>
#include <src/Modules/TestModule.h>
#include <iostream>
#include <src/Core/Loggers/ConsoleLogger.h>

using namespace Engine::Modules;

namespace Engine { namespace Core {

    inline void deleteModule(Module* module) {delete module;}
    inline void initModule(Module* module) {module->init();}
    inline void updateModule(Module* module) {module->update();}
    inline void deleteRenderer(Renderer* renderer) {delete renderer;}
    inline void flushRenderer(Renderer* renderer) {renderer->flush();}
    inline void deleteWindow(Window* window) {delete window;}

    Engine::Engine() {
        logger = new ConsoleLogger();
        addRenderer(new Renderer2D(), "Renderer2D");
        addModule(new TestModule(this), "TestModule");
        openWindow("Engine");
    }

    Engine::~Engine() {
        iterateModules(deleteModule);
        iterateRenderers(deleteRenderer);
        iterateWindows(deleteWindow);
        delete logger;
    }

    void Engine::iterateModules(void (*fun)(Module *)) {
        for(Modules::iterator iterator = modules.begin(); iterator != modules.end(); iterator++) {
            fun(iterator->second);
        }
    }

    void Engine::iterateRenderers(void (*fun)(Renderer *)) {
        for(Renderers::iterator iterator = renderers.begin(); iterator != renderers.end(); iterator++) {
            fun(iterator->second);
        }
    }

    void Engine::iterateWindows(void (*fun)(Window *)) {
        for(Windows::iterator iterator = windows.begin(); iterator != windows.end(); iterator++) {
            fun(iterator->second);
        }
    }

    void Engine::start() {
        iterateModules(initModule);
        while (isRunning()) {
            iterateModules(updateModule);
            iterateRenderers(flushRenderer);
        }
    }

    bool Engine::isRunning() {
        for(Windows::iterator iterator = windows.begin(); iterator != windows.end(); iterator++) {
            if(!iterator->second->shouldClose()) {
                return true;
            }
        }
        return false;
    }

    void Engine::addRenderer(Renderer *renderer, std::string name) {
        renderers[name] = renderer;
    }

    void Engine::addModule(Module *module, std::string name) {
        modules[name] = module;
    }

    Renderer *Engine::getRenderer(std::string name) {
        return renderers[name];
    }

    Module *Engine::getModule(std::string name) {
        return modules[name];
    }

    Window *Engine::getWindow(std::string name) {
        return windows[name];
    }

    void Engine::openWindow(std::string name) {
        auto window = new Window(name);
        windows[name] = window;
    }

    void Engine::closeWindow(std::string name) {
        delete windows[name];
    }

    Logger *Engine::getLogger() {
        return logger;
    }

} }