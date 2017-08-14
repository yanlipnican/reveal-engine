//
// Created by yan on 18.7.17.
//

#pragma once

#include <src/Core/Engine.h>
#include <src/Core/Graphics/Renderer2D.h>
#include "src/Core/Timing.h"

using namespace Engine::Core;

namespace Engine { namespace Modules {

    class TestModule: public Module {
    private:
        Renderer2D* renderer;
        Timing* timing;
    public:
        TestModule(Engine::Core::Engine* e): Module(e) {};
        void update() override;
        void init() override;
    };

}}


