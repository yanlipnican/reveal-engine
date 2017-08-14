//
// Created by yan on 12.8.17.
//

#pragma once

#include <glm/glm.hpp>
#include "Mesh.h"
#include "Texture.h"
#include "Transformation.h"
#include "Material.h"

using namespace Engine::Core;

namespace Engine{
namespace Core {

    class Renderable3D: public Transformation {
    private:
        Mesh* m_mesh;
        Material* m_material;
    public:
        Mesh* getMesh();
        Material* getMaterial();
    };

}
}


