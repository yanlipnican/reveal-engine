//
// Created by yan on 7.7.17.
//

#ifndef ENGINE_GLRENDERER_H
#define ENGINE_GLRENDERER_H

#include "../Renderer.h"

#include <external/glew-2.0.0/include/GL/glew.h>
#include <external/glfw-3.2.1/include/GLFW/glfw3.h>

/**
 * Renderer implementation using OpenGL api
 */
class GLRenderer : public Renderer {
public:
    void init() override;
    void update() override;
    void end() override;
    bool isRunning() override;
private:
    GLFWwindow* window;
    bool running;
};


#endif //ENGINE_GLRENDERER_H
