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
        std::map<std::string, Renderer*> renderers;
        void iterateTroughRenderers(void (*fun)(Renderer*));
        RendererAPI rendererAPI;
    public:
        RenderManager(RendererAPI);
        ~RenderManager();
        void init();
        void update();
        void addRenderer(Renderer* renderer, std::string type);
        Renderer* getRenderer(std::string type);
    };

}

#endif //ENGINE_RENDERMANAGER_H
