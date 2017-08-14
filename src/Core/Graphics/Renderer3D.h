//
// Created by yan on 12.8.17.
//

#pragma once

#include "Renderable3D.h"
#include "Camera.h"
#include "Shader.h"

namespace Engine {
namespace Core {

class Renderer3D {
private:
    std::vector<Renderable3D*> queue;
    Shader* m_shader;
public:
    void submit(Renderable3D* object);
    void flush(Camera cam);
    Renderer3D();
    ~Renderer3D();
};

}
}


