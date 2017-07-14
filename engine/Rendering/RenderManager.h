//
// Created by yan on 7.7.17.
//

#pragma once

#include <map>
#include "Renderer.h"
#include "RendererApi.h"

namespace Engine {

    class RenderManager {
    private:
        typedef std::map<int, Renderer*> renderersMap;
        renderersMap renderers;
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
