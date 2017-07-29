//
// Created by yan on 24.7.17.
//

#pragma once

#include "src/Core/Engine.h"

using namespace Engine::Core;

namespace Engine { namespace Modules {
    class Timing: public Module {
    private:
        Engine::Core::Engine* engine;
        float m_delta = 0;
        long m_last = 0;
    public:
        Timing(Engine::Core::Engine* engine): Module(engine){}
        void init();
        void update();
        void start();
        void end();
        float delta();
    };
}}

