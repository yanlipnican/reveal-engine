//
// Created by yan on 7.7.17.
//

#include "GLRenderer.h"
#include <iostream>

void setOpenGLvariables() {
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void GLRenderer::init() {

    if( !glfwInit() )
    {
        return;
    }

    setOpenGLvariables();

    window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);

    if( window == NULL ){
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glewExperimental=(GLboolean)true;

    if (glewInit() != GLEW_OK) {
        return;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    running = true;

}

void GLRenderer::update() {

    if (!(glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0)) {
        running = false;
        return;
    }

    glfwSwapBuffers(window);
    glfwPollEvents();

}

void GLRenderer::end() {

}

bool GLRenderer::isRunning() {
    return running;
}