//
// Created by yan on 28.7.17.
//

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "Texture.h"

using namespace Engine::Core;

Texture::Texture(const char *filename): m_filename(filename) {
    m_image = stbi_load(filename, &m_width, &m_height, &m_comp, STBI_rgb_alpha);
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    stbi_image_free(m_image);
}

GLuint Texture::getId() {
    return m_id;
}
