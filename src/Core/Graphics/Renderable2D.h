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
        // grid_size_x, grid_size_y, index_x, index_y
        glm::vec4 m_atlas = glm::vec4(1, 1, 0, 0);
    public:
        void setColor(glm::vec3 color);
        void translate(glm::vec3 vector);
        void setTexture(Texture* texture);
        Texture* getTexture();
        void rotate(float value, glm::vec3 axis);
        void scale(glm::vec3 scale);
        glm::vec3 getColor();
        glm::mat4 getModelMatrix();
        /**
         * Parameters of vec4 are int this order
         * grid_size_x, grid_size_y, index_x, index_y
         */
        void setAtlas(glm::vec4 atlas);
        glm::vec4 getAtlas();
    };

} }



