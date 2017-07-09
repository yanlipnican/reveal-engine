//
// Created by yan on 9.7.17.
//

#include "Logger.h"

using namespace Engine;

void Logger::log(std::string value) {
    std::cout << value << std::endl;
}

void Logger::log(long value) {
    std::cout << value << std::endl;
}

void Logger::log(int value) {
    std::cout << value << std::endl;
}

void Logger::log(float value) {
    std::cout << value << std::endl;
}