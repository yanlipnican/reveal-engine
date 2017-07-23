//
// Created by yan on 18.7.17.
//

#include "Renderer2DModule.h"

using namespace Engine::Modules;

static Renderable2D test;
static Camera cam = Camera(45, 4, 3, 0.1f, 100.0f);
static float pos = 0;
void Renderer2DModule::init() {
    renderer = new Renderer2D();
    test.setColor(glm::vec3(.4, .5, 0));
    cam.setView(
            glm::lookAt(
                    glm::vec3(4,4,-10), // Camera is at (4,3,3), in World Space
                    glm::vec3(0,0,0), // and looks at the origin
                    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
            )
    );
}

void Renderer2DModule::update() {
    pos += 0.001f;
    test.rotate(0.001f, glm::vec3(1, 0, 0));
    cam.setView(
            glm::lookAt(
                    glm::vec3(0,0,pos), // Camera is at (4,3,3), in World Space
                    glm::vec3(0,0,0), // and looks at the origin
                    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
            )
    );
    renderer->submit(&test);
    renderer->flush(cam);
}

