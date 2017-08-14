#include <iostream>
#include "src/Core/Engine.h"
#include "Modules/TestModule.h"
using namespace Engine;

int main(int argc, char** argv) {
    std::cout << argv[0] << std::endl;
    Core::Engine engine;
    engine.addModule(new Modules::TestModule(&engine), "Test");
    engine.start();

    return 0;
}