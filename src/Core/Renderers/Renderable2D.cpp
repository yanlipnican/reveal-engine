//
// Created by yan on 15.7.17.
//

#include "Renderable2D.h"

void Engine::Core::Renderable2D::setColor(glm::vec3 color) {
    this->color = color;
}

glm::vec3 Engine::Core::Renderable2D::getColor() {
    return color;
}
