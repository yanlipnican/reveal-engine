//
// Created by yan on 15.7.17.
//

#pragma once

#include <src/Core/Logger.h>

namespace Engine {
    namespace Core {

        class ConsoleLogger: public Logger {
        public:
            void log(std::string msg);
            void log(int msg);
            void log(float msg);
            void log(long msg);
        };

    }
}

