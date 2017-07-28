//
// Created by yan on 28.7.17.
//

#pragma once
namespace Engine { namespace Core {

    class Texture {
    private:
        int m_width;
        int m_height;
        int m_comp;
        const char* m_filename;
        unsigned char* m_image;
    public:
        Texture(const char* filename);
        ~Texture();
    };

}}

