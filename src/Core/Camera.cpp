//
// Created by yan on 23.7.17.
//

#include "Camera.h"

Engine::Core::Camera::Camera(float fov, float width, float height, float near, float far) {
    projection = glm::perspective(glm::radians(fov), width / height, near, far);
    view = glm::mat4(1.0f);
}

glm::mat4 Engine::Core::Camera::getMatrix() {
    return projection * view;
}

void Engine::Core::Camera::setView(glm::mat4 matrix) {
    view = matrix;
}

void Engine::Core::Camera::setProjection(glm::mat4 matrix) {
    projection = matrix;
}

