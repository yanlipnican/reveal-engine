#include <chrono>
#include "Timing.h"

using namespace Engine;
using namespace std::chrono;

long getMilliseconds() {
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    return ms.count();
}

Timing::Timing() {
    lastTimestamp = getMilliseconds();
}

void Timing::resetTime() {
    lastTimestamp = getMilliseconds();
}

float Timing::delta() {
    return getMilliseconds() - lastTimestamp;
}