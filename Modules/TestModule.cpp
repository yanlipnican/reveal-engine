//
// Created by yan on 18.7.17.
//

#include <src/Core/Graphics/Renderable3D.h>
#include <src/Core/Graphics/Renderer3D.h>
#include <src/Core/Graphics/BasicShapes.h>
#include "TestModule.h"

using namespace Engine::Modules;

static Camera cam = Camera(45, 4, 3, 0.1f, 100.0f);
static std::vector<Renderable3D> objs;
static Window* window;
static Timing* timing;
static Renderer3D* renderer;
float posx = 0;
float posy = 0;
float posz = -10;
float speed = 10;

void TestModule::init() {
    renderer = new Renderer3D();
    timing = (Timing*)engine->getModule("Timing");
    window = engine->getWindow("Engine");
    Material* material = new Material();
    material->setDiffuse_color(glm::vec3(1, 0, 0));
    material->setDiffuse_texture(new Texture("res/ol_razzle_dazzle.png"));
    BasicShape::Cube shape;
    Mesh* mesh = new Mesh(shape);

    for (int x = 0; x < 50; x++) {
        for (int y = 0; y < 50; y++) {
            Renderable3D obj;
            obj.setMaterial(material);
            obj.setMesh(mesh);
            obj.translate(glm::vec3(x * .3f, y* .3f, 0));
            obj.scale(glm::vec3(0.1f, 0.1f, 0.1f));
            objs.push_back(obj);
        }
    }
}

void TestModule::update() {

    if (glfwGetKey(window->getWindow() , GLFW_KEY_D) == GLFW_PRESS) {
        posx -= speed * timing->delta();
    }
    if (glfwGetKey(window->getWindow() , GLFW_KEY_A) == GLFW_PRESS) {
        posx += speed * timing->delta();
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
            glm::vec3(posx,posy,posz),
            glm::vec3(posx,posy,0),
            glm::vec3(0,1,0)
        )
    );

    for (auto it = objs.begin(); it < objs.end(); it++) {
        renderer->submit(it.base());
    }

    renderer->flush(cam);
}
