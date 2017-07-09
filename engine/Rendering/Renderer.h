//
// Created by yan on 7.7.17.
//

#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H


class Renderer {
public:
    virtual void init();
    virtual void update();
    virtual void end();
    virtual bool isRunning();
};


#endif //ENGINE_RENDERER_H
