//
// Created by yan on 15.7.17.
//

#pragma once

#include "Engine.h"
#include "Logger.h"

namespace Engine { namespace Core {

    class Engine;

    class Module {
    protected:
        Engine* engine;
        Logger* logger;
    public:
        Module(Engine* engine): engine(engine) {};
        virtual void init() = 0;
        virtual void update() = 0;
    };

} }
