//
// Created by yan on 24.7.17.
//

#include <src/Util/TimeUtil.h>
#include <iostream>
#include "Timing.h"
#define LOG_INTERVAL 400
static long m_last_log;

void Engine::Modules::Timing::init() {
    m_last_log = Engine::Util::TimeUtil::getMillis();
}

void Engine::Modules::Timing::update() {
    if (Engine::Util::TimeUtil::getMillis() - m_last_log >= LOG_INTERVAL) {
        m_last_log = Engine::Util::TimeUtil::getMillis();
        std::cout << (int) (1 / delta()) << "FPS" << std::endl;
    }


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

void Engine::Modules::Timing::start() {

}

void Engine::Modules::Timing::end() {

}
