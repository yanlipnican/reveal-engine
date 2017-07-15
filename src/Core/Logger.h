//
// Created by yan on 15.7.17.
//

#pragma once

#include <tgmath.h>

namespace Engine {
    namespace Core {

        class Logger {
        public:
            virtual void log(std::string msg) = 0;
            virtual void log(int msg) = 0;
            virtual void log(float msg) = 0;
            virtual void log(long msg) = 0;
        };

    }
}