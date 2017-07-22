//
// Created by yan on 15.7.17.
//

#include "Window.h"

Engine::Core::Window::Window(const char* title) {
    window = glfwCreateWindow( 1024, 768, title, NULL, NULL);
}

Engine::Core::Window::~Window() {
    close();
}

void Engine::Core::Window::bind() {
    glfwMakeContextCurrent(window);
}

void Engine::Core::Window::pollEvents() {
    glfwPollEvents();
}

bool Engine::Core::Window::shouldClose() {
    return (bool)glfwWindowShouldClose(window);
}

void Engine::Core::Window::close() {
    glfwDestroyWindow(window);
}

void Engine::Core::Window::swapBuffers() {
    glfwSwapBuffers(window);
}

GLFWwindow* Engine::Core::Window::getWindow() {
    return window;
}
