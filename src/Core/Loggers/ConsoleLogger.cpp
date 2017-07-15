//
// Created by yan on 15.7.17.
//

#include <iostream>
#include "ConsoleLogger.h"

void Engine::Core::ConsoleLogger::log(std::string msg) {
    std::cout << msg << std::endl;
}

void Engine::Core::ConsoleLogger::log(int msg) {
    std::cout << msg << std::endl;
}

void Engine::Core::ConsoleLogger::log(float msg) {
    std::cout << msg << std::endl;
}

void Engine::Core::ConsoleLogger::log(long msg) {
    std::cout << msg << std::endl;
}
