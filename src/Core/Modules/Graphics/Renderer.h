//
// Created by yan on 15.7.17.
//

#pragma once

#include "Camera.h"

namespace Engine {
    namespace Core {

        class Renderer {
        public:
            virtual void flush(Camera camera) = 0;
        };

    }
}