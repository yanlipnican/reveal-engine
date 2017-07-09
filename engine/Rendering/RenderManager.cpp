//
// Created by yan on 7.7.17.
//

#include "RenderManager.h"
#include "OpenGL/GLRenderer.h"

using namespace Engine;

RenderManager::RenderManager(RendererAPI api) {
    if(api == RendererAPI::OPEN_GL) {
        renderer = new GLRenderer();
    }
}

RenderManager::~RenderManager() {
    delete renderer;
}

void RenderManager::init() {
    renderer->init();
}

void RenderManager::update() {
    renderer->update();
}

void RenderManager::end() {
    renderer->end();
}

bool RenderManager::isRunning() {
    return renderer->isRunning();
}
