//
// Created by yan on 7.7.17.
//

#ifndef ENGINE_TIMING_H
#define ENGINE_TIMING_H

namespace Engine {

    class Timing {
    private:
        long lastTimestamp;
    public:
        Timing();
        float delta();
        void resetTime();
    };

}


#endif //ENGINE_TIMING_H
