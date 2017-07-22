//
// Created by yan on 15.7.17.
//

#pragma once

#include <src/Core/Renderer.h>
#include "src/Core/Shader.h"
#include <vector>
#include "Renderable2D.h"

namespace Engine { namespace Core {

    class Renderer2D: public Renderer {
    private:
        typedef std::vector<Renderable2D*> Queue;
        Queue queue;
        Shader* shader;
    public:
        Renderer2D();
        ~Renderer2D();
        void flush() override;
        void submit(Renderable2D* object);
    private:
        void sortQueue();
    };

} }



