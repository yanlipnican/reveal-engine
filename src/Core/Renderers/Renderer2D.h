//
// Created by yan on 15.7.17.
//

#pragma once

#include <src/Core/Renderer.h>
#include "src/Core/Shader.h"
#include <vector>
#include "Renderable2D.h"
#include <functional>

namespace Engine { namespace Core {

    class Renderer2D: public Renderer {
    private:
        typedef std::vector<Renderable2D*> Queue;
        struct vbo {
            GLuint id;
            GLuint attrib_location;
            uint length;
            std::function<void()> onData;
        };
        Queue queue;
        Shader* shader;
        GLuint vao;
        std::vector<vbo> vbos;
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
        void sortQueue();

        void loadBuffers();

        uint addVertexBuffer(const char* attrib, uint size, uint stride, uint length, uint offset, std::function<void()> onData);

        uint addVertexBuffer(const char* attrib, uint size, uint stride, uint attrib_divisor, uint length, uint offset, std::function<void()> onData);

    };

} }



