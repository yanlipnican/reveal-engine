//
// Created by yan on 15.7.17.
//
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Renderable2D.h"

using namespace Engine::Core;

void Renderable2D::setColor(glm::vec3 color) {
    m_color = color;
}

glm::vec3 Renderable2D::getColor() {
    return m_color;
}

glm::mat4 Renderable2D::getModelMatrix() {
    return m_model_matrix;
}

void Renderable2D::translate(glm::vec3 position) {
    m_model_matrix = glm::translate(m_model_matrix, position);
}

void Renderable2D::rotate(float value, glm::vec3 axis) {
    m_model_matrix = glm::rotate(m_model_matrix, value , axis);
}

void Renderable2D::scale(glm::vec3 scale) {
    m_model_matrix = glm::scale(m_model_matrix, scale);
}

void Renderable2D::setTexture(Texture *texture) {
    m_texture = texture;
}

Texture * Renderable2D::getTexture() {
    return m_texture;
}

float *Renderable2D::getUV() {
    return uv;
}
