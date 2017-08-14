//
// Created by yan on 14.8.17.
//

#include "Material.h"

using namespace Engine::Core;

glm::vec3 Material::getDiffuse_color(){
    return diffuse_color;
}

void Material::setDiffuse_color(glm::vec3 diffuse_color) {
    this->diffuse_color = diffuse_color;
}

Texture *Material::getDiffuse_texture(){
    return diffuse_texture;
}

void Material::setDiffuse_texture(Texture *diffuse_texture) {
    this->diffuse_texture = diffuse_texture;
}
