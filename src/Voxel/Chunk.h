//
// Created by yan on 12.8.17.
//

#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <src/Core/Graphics/Mesh.h>
#include <src/Core/Graphics/Renderable3D.h>
#include "Block.h"
using namespace Engine::Core;

namespace Voxel {

class Chunk : public Renderable3D {
    glm::vec3 m_position;
    std::vector<Block> m_blocks;
    long m_seed;
public:
    glm::vec3 getPosition();
    std::vector<Block>* getBlocks();
    long getSeed();
    void generateMesh();
};

}


