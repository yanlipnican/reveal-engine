//
// Created by yan on 7.7.17.
//

#ifndef ENGINE_ENGINEMANAGER_H
#define ENGINE_ENGINEMANAGER_H

#include "Rendering/RenderManager.h"
#include "Scene/SceneManager.h"
#include "Timing.h"
#include "Logger.h"

namespace Engine {

    class EngineManager {
    private:
        RenderManager* renderManager;
        SceneManager* sceneManager;
        Timing* timing;
        Logger* logger;
    public:
        EngineManager();
        ~EngineManager();
        void init();    
        void update();
        void end();
        bool isRunning();

        RenderManager *getRenderManager() const;

        void setRenderManager(RenderManager *renderManager);

        SceneManager *getSceneManager() const;

        void setSceneManager(SceneManager *sceneManager);
    };

}


#endif //ENGINE_ENGINEMANAGER_H
