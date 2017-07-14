//
// Created by yan on 7.7.17.
//

#include "EngineManager.h"

using namespace Engine;

EngineManager::EngineManager() {

    renderManager = new RenderManager(RendererAPI::OPEN_GL);
    sceneManager = new SceneManager();
    timing = new Timing();
    logger = new Logger();

}

EngineManager::~EngineManager() {
    delete renderManager;
    delete sceneManager;
    delete timing;
    delete logger;
}

// lifecycle

void EngineManager::init() {

    renderManager->init();

    while (isRunning()) {
        update();
    }

    end();
}

void EngineManager::update() {

    if (timing->delta() >= 1000/120) {
        renderManager->update();
        timing->resetTime();
    }

}

void EngineManager::end() {
}


bool EngineManager::isRunning() {
    return true;
}

// geters and setters

RenderManager *EngineManager::getRenderManager() const {
    return renderManager;
}

void EngineManager::setRenderManager(RenderManager *renderManager) {
    EngineManager::renderManager = renderManager;
}

SceneManager *EngineManager::getSceneManager() const {
    return sceneManager;
}

void EngineManager::setSceneManager(SceneManager *sceneManager) {
    EngineManager::sceneManager = sceneManager;
}
