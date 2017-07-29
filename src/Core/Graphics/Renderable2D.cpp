//
// Created by yan on 15.7.17.
//
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Renderable2D.h"

using namespace Engine::Core;

void Renderable2D::setColor(glm::vec3 color) {
    this->color = color;
}

glm::vec3 Renderable2D::getColor() {
    return color;
}

glm::mat4 Renderable2D::getModelMatrix() {
    return model_matrix;
}

void Renderable2D::translate(glm::vec3 position) {
    model_matrix = glm::translate(model_matrix, position);
}

void Renderable2D::rotate(float value, glm::vec3 axis) {
    model_matrix = glm::rotate(model_matrix, value , axis);
}

void Renderable2D::scale(glm::vec3 scale) {
    model_matrix = glm::scale(model_matrix, scale);
}

void Renderable2D::setTexture(Texture *texture) {
    this->texture = texture;
}

Texture * Renderable2D::getTexture() {
    return texture;
}
