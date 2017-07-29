//
// Created by yan on 18.7.17.
//

#include "Renderer2DModule.h"

using namespace Engine::Modules;

static Renderable2D test;
static Camera cam = Camera(45, 4, 3, 0.1f, 100.0f);
static std::vector<Renderable2D> objs;
static float posx = 0;
static float posy = 0;
static float posz = 3;
static Window* window;
static float speed = 3;

void Renderer2DModule::init() {
    renderer = new Renderer2D();
    Texture* atlas = new Texture("res/atlas.png", GL_NEAREST);
    timing = (Timing*)engine->getModule("Timing");
    window = engine->getWindow("Engine");

    for (int k = 0; k < 16; k++){
        for ( int i = 0; i < 16; i++ ) {
            Renderable2D item;
            item.setColor(glm::vec3(.6, .5, .0 + 1.0/255.0 * i));
            item.translate(glm::vec3( .6 * i, .6 * k, 0));
            item.scale(glm::vec3(.3, .3, .3));
            item.setTexture(atlas);
            item.setAtlas(glm::vec4(16, 16, (float)i, (float)k));
            objs.push_back(item);
        }
    }

    cam.setView(
            glm::lookAt(
                    glm::vec3(2,2,7), // position
                    glm::vec3(2,2,0), // look at
                    glm::vec3(0,1,0)  // rotation
            )
    );
}

void Renderer2DModule::update() {

    if (glfwGetKey(window->getWindow() , GLFW_KEY_D) == GLFW_PRESS) {
        posx += speed * timing->delta();
    }
    if (glfwGetKey(window->getWindow() , GLFW_KEY_A) == GLFW_PRESS) {
        posx -= speed * timing->delta();
    }
    if (glfwGetKey(window->getWindow() , GLFW_KEY_W) == GLFW_PRESS) {
        posy += speed * timing->delta();
    }
    if (glfwGetKey(window->getWindow() , GLFW_KEY_S) == GLFW_PRESS) {
        posy -= speed * timing->delta();
    }
    if (glfwGetKey(window->getWindow() , GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        posz -= speed * timing->delta();
    }
    if (glfwGetKey(window->getWindow() , GLFW_KEY_SPACE) == GLFW_PRESS) {
        posz += speed * timing->delta();
    }

    cam.setView(
            glm::lookAt(
                    glm::vec3(posx,posy,posz), // Camera is at (4,3,3), in World Space
                    glm::vec3(posx,posy,0), // and looks at the origin
                    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
            )
    );
    for (auto it = objs.begin(); it < objs.end(); it++) {
        renderer->submit(it.base());
    }
    renderer->flush(cam);
}

