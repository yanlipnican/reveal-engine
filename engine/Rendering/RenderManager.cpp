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

RenderManager::RenderManager(RendererAPI api): rendererAPI(api) {
    // initialise base renderers for api
    if(api == RendererAPI::OPEN_GL) {
        renderers[RENDERER_2D] = new GL2DRenderer();
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

Renderer *RenderManager::getRenderer(int id) {
    return renderers[id];
}

void RenderManager::iterateTroughRenderers(void (*fun)(Renderer *)) {
    for(std::map<int, Renderer*>::iterator iterator = renderers.begin(); iterator != renderers.end(); iterator++) {
        fun(iterator->second);
    }
}

void RenderManager::addRenderer(Renderer *renderer, int id) {
    if (renderers[id] != NULL) {
        std::cout << "Renderer with id\"" << id << "\" is already loaded.";
        return;
    }
    renderers[id] = renderer;
}

Renderer *RenderManager::get2DRenderer() {
    return renderers[RENDERER_2D];
}