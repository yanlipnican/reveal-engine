#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Renderable2D.h"

using namespace Engine::Core;

Renderable2D::Renderable2D() {
    setUVDefault();
}

void Renderable2D::setUVDefault() {
    m_uv[0] = 0;
    m_uv[1] = 1;
    m_uv[2] = 1;
    m_uv[3] = 1;
    m_uv[4] = 1;
    m_uv[5] = 0;
    m_uv[6] = 0;
    m_uv[7] = 0;
}

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
    return m_uv;
}

void Renderable2D::setUVAtlas(float gridSizeX, float gridSizeY, float indexX, float indexY) {
    for (int i = 0; i < 8;i+=2) {
        float x = 1.0f / gridSizeX * indexX;
        float y = 1.0f / gridSizeY * indexY;
        m_uv[i] = x + m_uv[i] / gridSizeX ;
        m_uv[i + 1] = y + m_uv[i + 1] / gridSizeY;
    }
}
