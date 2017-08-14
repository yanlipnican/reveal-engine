//
// Created by yan on 14.8.17.
//

#pragma once

#include <glm/glm.hpp>
#include "Texture.h"

namespace Engine {
namespace Core {

class Material {
private:
    glm::vec3 diffuse_color;
    Texture* diffuse_texture;
public:
    glm::vec3 getDiffuse_color();
    void setDiffuse_color(glm::vec3 diffuse_color);
    Texture *getDiffuse_texture();
    void setDiffuse_texture(Texture *diffuse_texture);
};

}
}

