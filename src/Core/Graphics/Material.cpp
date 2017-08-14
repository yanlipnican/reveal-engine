//
// Created by yan on 14.8.17.
//

#include "Material.h"

const glm::vec3 &Engine::Core::Material::getDiffuse_color() const {
    return diffuse_color;
}

void Engine::Core::Material::setDiffuse_color(const glm::vec3 &diffuse_color) {
    Material::diffuse_color = diffuse_color;
}

Engine::Core::Texture *Engine::Core::Material::getDiffuse_texture() const {
    return diffuse_texture;
}

void Engine::Core::Material::setDiffuse_texture(Engine::Core::Texture *diffuse_texture) {
    Material::diffuse_texture = diffuse_texture;
}
