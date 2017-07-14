//
// Created by yan on 15.7.17.
//

#ifndef ENGINE_GL2DRENDERER_H
#define ENGINE_GL2DRENDERER_H

#include "engine/Rendering/Renderer.h"

class GL2DRenderer: public Renderer {
public:
    void submit(GL2DRenderable* object) override;
    void flush() override;
};


#endif //ENGINE_GL2DRENDERER_H
