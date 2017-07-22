//
// Created by yan on 18.7.17.
//

#include <src/Core/Shader.h>
#include "Renderer2DModule.h"

using namespace Engine::Modules;

Renderable2D test;

Shader* shader;

void Renderer2DModule::init() {
    renderer = new Renderer2D();
    test.setColor(glm::vec3(1, 0, 0));
    shader = new Shader("../shaders/2Dshader.vert", "../shaders/2Dshader.frag");
}

void Renderer2DModule::update() {
    renderer->submit(&test);
    shader->bind();
    renderer->flush();
}

