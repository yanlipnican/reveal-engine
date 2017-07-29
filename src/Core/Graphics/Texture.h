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

        bool m_isGPUload = false;
        bool m_isRAMload = false;
        const char* m_filename;
        unsigned char* m_image;
        GLuint m_id;
    public:
        Texture(const char* filename);
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

