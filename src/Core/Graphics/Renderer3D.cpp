//
// Created by yan on 12.8.17.
//

#include "Renderer3D.h"

Renderer3D::Renderer3D() {
    m_shader = new Shader("shaders/3Dshader.vert", "shaders/3Dshader.frag");
}

void Renderer3D::submit(Renderable3D *object) {
    queue.push_back(object);
}

void Renderer3D::flush(Camera cam) {
    // shader
    m_shader->bind();
    m_shader->setMat4fUniform("camera", cam.getMatrix());
    glEnable(GL_DEPTH_TEST);

    for (uint i = 0; i < queue.size(); i++) {
        // model matrix
        m_shader->setMat4fUniform("model_matrix", queue[i]->getModelMatrix());

        // material
        Material* material = queue[i]->getMaterial();

        // diffuse
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, material->getDiffuse_texture()->getId());
        m_shader->set1iUniform("diffuse_texture", 0);
        m_shader->set3fUniform("diffuse_color", material->getDiffuse_color());

        // mesh (vao)
        Mesh* mesh = queue[i]->getMesh();
        mesh->bind();

        // draw
        glDrawElements(GL_TRIANGLES, mesh->size(), GL_UNSIGNED_INT, mesh->getIndices());
    }

    // cleanup
    queue.clear();
}

Renderer3D::~Renderer3D() {
    delete m_shader;
}
