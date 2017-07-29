//
// Created by yan on 24.7.17.
//

#include <src/Util/TimeUtil.h>
#include "Timing.h"

void Engine::Modules::Timing::init() {

}

void Engine::Modules::Timing::update() {
    long now = Engine::Util::TimeUtil::getNanoTime();
    if (m_last != 0) {
        m_delta = (now - m_last) / 1000000000.0f; // 1 000 000 000 (nanosecond -> second)
    }
    m_last = now;
}
/*
 * Returns delta in seconds
 */
float Engine::Modules::Timing::delta() {
    return m_delta;
}
