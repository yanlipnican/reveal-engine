//
// Created by yan on 15.7.17.
//

#pragma once

#include <string>

namespace Engine { namespace Core {

    class Window {
    public:
        Window(std::string title);
        ~Window();
        bool shouldClose();
    };

} }


