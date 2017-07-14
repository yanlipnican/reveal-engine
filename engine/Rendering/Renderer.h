//
// Created by yan on 7.7.17.
//

#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "engine/Rendering/Renderable.h"

class Renderer {
public:
    virtual void submit(Renderable* object) = 0;
    virtual void flush() = 0;
    virtual void init() = 0;
};


#endif //ENGINE_RENDERER_H
