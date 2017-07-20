//
// Created by yan on 18.7.17.
//

#pragma once

#include <src/Core/Engine.h>
#include <src/Core/Renderers/Renderer2D.h>

using namespace Engine::Core;

namespace Engine { namespace Modules {

    class Renderer2DModule: public Module {
    private:
        Renderer2D* renderer;
    public:
        Renderer2DModule(Engine::Core::Engine* e): Module(e) {};
        void update() override;
        void init() override;
    };

}}


