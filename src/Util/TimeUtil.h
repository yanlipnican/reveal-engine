//
// Created by yan on 24.7.17.
//

#pragma once

#include <chrono>

namespace Engine { namespace Util { namespace TimeUtil {

    long getNanoTime() {
        return std::chrono::system_clock::now().time_since_epoch().count();
    }
    long getMillis() {
        return getNanoTime() / 1000000;
    }

}}}