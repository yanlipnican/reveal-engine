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
    const glm::vec3 &getDiffuse_color() const;
    void setDiffuse_color(const glm::vec3 &diffuse_color);
    Texture *getDiffuse_texture() const;
    void setDiffuse_texture(Texture *diffuse_texture);
};

}
}

