//
// Created by yan on 15.7.17.
//

#pragma once

#include "glm/glm.hpp"

namespace Engine { namespace Core {

    class Renderable2D {
    public:
    private:
        glm::vec3 color;
    public:
        void setColor(glm::vec3 color);
        glm::vec3 getColor();
    };

} }



