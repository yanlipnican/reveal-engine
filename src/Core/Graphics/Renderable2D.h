//
// Created by yan on 15.7.17.
//

#pragma once

#include "glm/glm.hpp"
#include "Texture.h"
#include "Transformation.h"

namespace Engine { namespace Core {

    class Renderable2D: public Transformation {
    public:
    private:
        glm::vec3 m_color = glm::vec3(0, 0, 0);
        Texture* m_texture;
        float m_uv[8];
    public:
        Renderable2D();
        void setColor(glm::vec3 color);
        void setTexture(Texture* texture);
        Texture* getTexture();
        glm::vec3 getColor();
        float* getUV();
        void setUV();
        void setUVDefault();
        void setUVAtlas(float gridSizeX, float gridSizeY, float indexX, float indexY);
    };

} }



