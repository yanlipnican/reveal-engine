//
// Created by yan on 18.7.17.
//

#include "Renderer2DModule.h"

using namespace Engine::Modules;

static Renderable2D test;
static Camera cam = Camera(45, 4, 3, 0.1f, 100.0f);
static std::vector<Renderable2D> objs;
static float pos = 0;

void Renderer2DModule::init() {
    renderer = new Renderer2D();
    Texture* tex = new Texture("res/test_image.png");
    Texture* tex2 = new Texture("res/ol_razzle_dazzle.png");
    timing = (Timing*)engine->getModule("Timing");

    bool a = true;

    for (int k = 0; k < 270; k++){
        for ( int i = 0; i < 200; i++ ) {
            Renderable2D item;
            item.setColor(glm::vec3(.6, .5, .0 + 1.0/255.0 * i));
            item.translate(glm::vec3(-5 + .3 * i, .3 * k, 0));
            item.scale(glm::vec3(.1, .1, .1));
            item.setTexture(a ? tex : tex2);
            a = !a;
            objs.push_back(item);
        }
    }

    cam.setView(
            glm::lookAt(
                    glm::vec3(0,0,5), // position
                    glm::vec3(0,0,0), // look at
                    glm::vec3(0,1,0)  // rotation
            )
    );
}

void Renderer2DModule::update() {
    pos += 1.0f * timing->delta();
    std::cout << 1 / timing->delta() << std::endl;
    cam.setView(
            glm::lookAt(
                    glm::vec3(pos,pos* 2,10), // Camera is at (4,3,3), in World Space
                    glm::vec3(pos/2.0,pos,0), // and looks at the origin
                    glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
            )
    );
    for (auto it = objs.begin(); it < objs.end(); it++) {
        renderer->submit(it.base());
    }
    renderer->flush(cam);
}

