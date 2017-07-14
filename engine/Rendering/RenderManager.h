//
// Created by yan on 7.7.17.
//

#ifndef ENGINE_RENDERMANAGER_H
#define ENGINE_RENDERMANAGER_H

#include <map>
#include "Renderer.h"
#include "RendererApi.h"

namespace Engine {

    class RenderManager {
    private:
        std::map<int, Renderer*> renderers;
        void iterateTroughRenderers(void (*fun)(Renderer*));
        RendererAPI rendererAPI;
    public:
        RenderManager(RendererAPI);
        ~RenderManager();
        void init();
        void update();
        enum BASE_RENDERER_TYPE {
            RENDERER_2D = 2,
        };
        void addRenderer(Renderer* renderer, int id);
        Renderer* getRenderer(int id);
        Renderer* get2DRenderer();
    };

}

#endif //ENGINE_RENDERMANAGER_H
