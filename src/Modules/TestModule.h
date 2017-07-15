//
// Created by yan on 15.7.17.
//

#pragma once

#include <src/Core/Engine.h>
#include <src/Core/Renderers/Renderer2D.h>

using namespace Engine::Core;

namespace Engine::Modules {

    class TestModule: public Core::Module {
    private:
        Renderer2D* renderer;
    public:
        TestModule(Core::Engine* engine): Module(engine) {}
        void init() override;
        void update() override;
    };

}


