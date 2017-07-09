//
// Created by yan on 9.7.17.
//

#ifndef ENGINE_LOGGER_H
#define ENGINE_LOGGER_H

#include <iostream>

namespace Engine {
    class Logger {
    public:
        void log(std::string);
        void log(long);
        void log(int);
        void log(float);
    };
}


#endif //ENGINE_LOGGER_H
