//
// Created by yan on 23.7.17.
//

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine { namespace Core {
    class Camera {
    public:
        Camera(){};
        Camera(float fov, float width, float height, float near, float far);
    private:
        glm::mat4 projection;
        glm::mat4 view;
    public:
        void setView(glm::mat4 matrix);
        void setProjection(glm::mat4 matrix);
        glm::mat4 getMatrix();
        glm::mat4 getView();
        glm::mat4 getProjection();
    };
}}

