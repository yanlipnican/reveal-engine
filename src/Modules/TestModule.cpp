//
// Created by yan on 15.7.17.
//

#include <iostream>
#include "TestModule.h"

using namespace Engine::Modules;
using namespace Engine::Core;

void TestModule::init() {
    renderer = (Renderer2D*) engine->getRenderer("Renderer2D");
}

void TestModule::update() {
}
