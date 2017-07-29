//
// Created by yan on 28.7.17.
//

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"
#include "Texture.h"

using namespace Engine::Core;

Texture::Texture(const char *filename): m_filename(filename) {
    RAMload();
    GPUload();
}

Texture::Texture(const char *filename, GLint texture_filter): m_filename(filename), m_texture_filter(texture_filter) {
    RAMload();
    GPUload();
}

void Texture::RAMload() {
    if (m_isRAMload) return;
    m_image = stbi_load(m_filename, &m_width, &m_height, &m_comp, STBI_rgb_alpha);
    m_isRAMload = true;
}

void Texture::GPUload() {
    if (m_isGPUload) return;
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_texture_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_texture_filter);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    m_isGPUload = true;
}

Texture::~Texture() {
    GPUunload();
    RAMunload();
}

GLuint Texture::getId() {
    return m_id;
}

void Texture::RAMunload() {
    if (!m_isRAMload) return;
    stbi_image_free(m_image);
    m_isRAMload = false;

}

void Texture::GPUunload() {
    if (m_isGPUload) return;
    glDeleteTextures(1, &m_id);
    m_isGPUload = false;
}

bool Texture::isGPUload() {
    return m_isGPUload;
}

bool Texture::isRAMload() {
    return m_isRAMload;
}
