//
// Created by yan on 15.7.17.
//

#pragma once

#include <src/Core/Renderer.h>
#include <vector>
#include "Renderable2D.h"

namespace Engine { namespace Core {

    class Renderer2D: public Renderer {
    private:
        typedef std::vector<Renderable2D*> Queue;
        Queue queue;
    public:
        void flush() override;
        void submit(Renderable2D* object);
    private:
        void sortQueue();
    };

} }



