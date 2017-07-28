//
// Created by yan on 28.7.17.
//

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Texture.h"

using namespace Engine::Core;

Texture::Texture(const char *filename): m_filename(filename) {
    m_image = stbi_load(filename, &m_width, &m_height, &m_comp, STBI_rgb_alpha);
}

Texture::~Texture() {
    stbi_image_free(m_image);
}
