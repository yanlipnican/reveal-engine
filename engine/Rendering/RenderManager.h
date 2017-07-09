//
// Created by yan on 7.7.17.
//

#ifndef ENGINE_RENDERMANAGER_H
#define ENGINE_RENDERMANAGER_H

#include "Renderer.h"
#include "RendererApi.h"

namespace Engine {

    class RenderManager {
    private:
        Renderer* renderer;
        RendererAPI rendererAPI;
    public:
        RenderManager(RendererAPI);
        ~RenderManager();
        void init();
        void update();
        void end();
        bool isRunning();
    };

}

#endif //ENGINE_RENDERMANAGER_H
