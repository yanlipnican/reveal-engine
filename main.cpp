#include <iostream>
#include "src/Core/Engine.h"

using namespace Engine;

int main(int argc, char** argv) {
    std::cout << argv[0] << std::endl;
    Core::Engine engine;
    engine.start();

    return 0;
}