//
// Created by yan on 12.8.17.
//

#include <glm/glm/gtc/matrix_transform.hpp>
#include "Transformation.h"

using namespace Engine::Core;

glm::mat4 Transformation::getModelMatrix() {
    return m_model_matrix;
}

void Transformation::translate(glm::vec3 position) {
    m_model_matrix = glm::translate(m_model_matrix, position);
}

void Transformation::rotate(float value, glm::vec3 axis) {
    m_model_matrix = glm::rotate(m_model_matrix, value , axis);
}

void Transformation::scale(glm::vec3 scale) {
    m_model_matrix = glm::scale(m_model_matrix, scale);
}