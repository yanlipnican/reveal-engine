//
// Created by yan on 18.7.17.
//

#pragma once

#include <src/Core/Engine.h>

using namespace Engine::Core;

namespace Engine { namespace Modules {
    class Renderer2DModule: public Module {
    public:
        Renderer2DModule();
        void update() override;
        void init() override;
    };
}}


