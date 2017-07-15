//
// Created by yan on 15.7.17.
//

#pragma once

#include <src/Core/Engine.h>
#include <src/Core/Renderers/Renderer2D.h>

using namespace Engine::Core;

namespace Engine { namespace Modules {

    class TestModule: public Module {
    private:
        Renderer2D* renderer;
        Logger* logger;
    public:
        TestModule(Core::Engine* engine): Module(engine), logger(engine->getLogger()) {}
        void init() override;
        void update() override;
    };

} }


