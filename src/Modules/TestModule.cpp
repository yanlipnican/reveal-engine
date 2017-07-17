//
// Created by yan on 15.7.17.
//

#include "TestModule.h"

using namespace Engine::Modules;
using namespace Engine::Core;

Renderable2D obj;

void TestModule::init() {
    renderer = (Renderer2D*) engine->getRenderer("Renderer2D");
}

void TestModule::update() {
    renderer->submit(obj);
}
