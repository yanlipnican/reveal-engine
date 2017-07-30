//
// Created by yan on 15.7.17.
//

#pragma once

#include <src/Core/Graphics/Renderer.h>
#include "Shader.h"
#include <vector>
#include "Renderable2D.h"
#include <functional>

namespace Engine { namespace Core {

    class Renderer2D: public Renderer {
    private:
        struct vbo {
            GLuint id;
            GLuint attrib_location;
            uint length;
        };
        typedef std::vector<Renderable2D*> Queue;
        typedef std::map<const char*, vbo> VBOs;
        Queue queue;
        Shader* shader;
        GLuint vao;
        VBOs vbos;
        GLuint uv_tex;
        GLuint textureBuffer;
        const float quad[18] = {
                -1.0f, -1.0f, 0.0f,
                1.0f, -1.0f, 0.0f,
                1.0f,  1.0f, 0.0f,
        //
        1.0f,  1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f
        };
    public:
        Renderer2D();
        ~Renderer2D();
        void flush(Camera camera) override;
        void submit(Renderable2D* object);
    private:
        void bindBuffer(const char* name);
        /**
         * Returns number of loaded instances
         */
        uint loadBuffers();

        uint addVertexBuffer(const char* attrib, uint size, uint stride, uint length, std::size_t offset);

        uint addVertexBuffer(const char* attrib, uint size, uint stride, uint length, std::size_t offset, uint attrib_divisor);

    };

} }



