//
// Created by yan on 12.8.17.
//

#include "Renderable3D.h"

Mesh *Renderable3D::getMesh() {
    return m_mesh;
}

Material* Renderable3D::getMaterial() {
    return m_material;
}

void Renderable3D::setMesh(Mesh* mesh) {
    m_mesh = mesh;
}

void Renderable3D::setMaterial(Material *material) {
    m_material = material;
}
