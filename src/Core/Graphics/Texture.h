//
// Created by yan on 28.7.17.
//

#pragma once

#include <src/OpenGL.h>
namespace Engine { namespace Core {

    class Texture {
    private:
        int m_width;
        int m_height;
        int m_comp;
        const char* m_filename;
        GLint m_texture_filter = GL_LINEAR;
        bool m_isGPUload = false;
        bool m_isRAMload = false;
        unsigned char* m_image;
        GLuint m_id;
    public:
        Texture(const char* filename);
        Texture(const char* filename, GLint texture_filter);
        ~Texture();
        GLuint getId();
        void GPUload();
        void GPUunload();
        void RAMload();
        void RAMunload();
        bool isGPUload();
        bool isRAMload();
    };

}}

