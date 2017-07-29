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
        glm::vec3 color = glm::vec3(0, 0, 0);
        glm::mat4 model_matrix = glm::mat4(1);
        Texture* texture;
    public:
        void setColor(glm::vec3 color);
        void translate(glm::vec3 vector);
        void setTexture(Texture* texture);
        Texture* getTexture();
        void rotate(float value, glm::vec3 axis);
        void scale(glm::vec3 scale);
        glm::vec3 getColor();
        glm::mat4 getModelMatrix();
    };

} }



