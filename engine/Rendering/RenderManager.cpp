//
// Created by yan on 7.7.17.
//

#include <iostream>
#include "RenderManager.h"
#include "OpenGL/GL2DRenderer.h"

using namespace Engine;

inline void deleteRenderer(Renderer* renderer) { delete renderer; }
inline void flushRenderer(Renderer* renderer) { renderer->flush(); }
inline void initRenderer(Renderer* renderer) { renderer->init(); }

RenderManager::RenderManager(RendererAPI api) {
    // initialise base renderers for api
    if(api == RendererAPI::OPEN_GL) {
        renderers["2D"] = new GL2DRenderer();
    }
}

RenderManager::~RenderManager() {
    iterateTroughRenderers(deleteRenderer);
}

void RenderManager::init() {
    iterateTroughRenderers(initRenderer);
}

void RenderManager::update() {
    iterateTroughRenderers(flushRenderer);
}

Renderer *RenderManager::getRenderer(std::string type) {
    return renderers[type];
}

void RenderManager::iterateTroughRenderers(void (*fun)(Renderer *)) {
    for(std::map<std::string, Renderer*>::iterator iterator = renderers.begin(); iterator != renderers.end(); iterator++) {
        fun(iterator->second);
    }
}

void RenderManager::addRenderer(Renderer *renderer, std::string type) {
    if (renderers[type] != NULL) {
        std::cout << "Renderer with type\"" << type << "\" is already loaded.";
        return;
    }
    renderers[type] = renderer;
}
