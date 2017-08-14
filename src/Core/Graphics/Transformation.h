//
// Created by yan on 12.8.17.
//

#pragma once

#include <glm/glm.hpp>

namespace Engine {
namespace Core {

    class Transformation {
    private:
        glm::mat4 m_model_matrix = glm::mat4(1);
    public:
        void translate(glm::vec3 vector);
        void rotate(float value, glm::vec3 axis);
        void scale(glm::vec3 scale);
        glm::mat4 getModelMatrix();
    };
}
}


