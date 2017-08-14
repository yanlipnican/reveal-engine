//
// Created by yan on 12.8.17.
//

#include "Chunk.h"
using namespace Voxel;

glm::vec3 Chunk::getPosition() {
    return m_position;
}

std::vector<Block>* Chunk::getBlocks() {
    return &m_blocks;
}

long Chunk::getSeed() {
    return m_seed;
}

void Chunk::generateMesh() {
    // WOMBO COMBO
}
