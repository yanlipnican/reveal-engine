//
// Created by yan on 18.7.17.
//

#include "Renderer2DModule.h"

using namespace Engine::Modules;

Renderable2D test;

void Renderer2DModule::init() {
    renderer = new Renderer2D();
    test.setColor(glm::vec3(1, 0, 0));
}

void Renderer2DModule::update() {
    renderer->submit(&test);
    renderer->flush();
}

