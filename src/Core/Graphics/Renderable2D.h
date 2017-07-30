//
// Created by yan on 15.7.17.
//

#pragma once

#include "glm/glm.hpp"
#include "Texture.h"

namespace Engine { namespace Core {

    class Renderable2D {
    public:
    private:
        glm::vec3 m_color = glm::vec3(0, 0, 0);
        glm::mat4 m_model_matrix = glm::mat4(1);
        Texture* m_texture;
        float m_uv[8];
    public:
        Renderable2D();
        void setColor(glm::vec3 color);
        void translate(glm::vec3 vector);
        void setTexture(Texture* texture);
        void rotate(float value, glm::vec3 axis);
        void scale(glm::vec3 scale);
        Texture* getTexture();
        glm::vec3 getColor();
        glm::mat4 getModelMatrix();
        float* getUV();
        void setUV();
        void setUVDefault();
        void setUVAtlas(float gridSizeX, float gridSizeY, float indexX, float indexY);
    };

} }



