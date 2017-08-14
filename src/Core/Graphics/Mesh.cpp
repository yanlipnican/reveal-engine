//
// Created by yan on 12.8.17.
//

#include "Mesh.h"
using namespace Engine::Core;

typedef unsigned int uint;

Mesh::Mesh(std::vector<float>& vertices, std::vector<uint>& indices, std::vector<float>& uv, std::vector<float>& normals) {
    float* vertices_arr = new float[vertices.size()];
    float* uv_arr = new float[uv.size()];
    float* normals_arr = new float[normals.size()];
    m_indices = new uint[indices.size()];

    for (uint i = 0; i < vertices.size(); i++) {
        vertices_arr[i] = vertices[i];
    }
    for (uint i = 0; i < indices.size(); i++) {
        m_indices[i] = indices[i];
    }
    for (uint i = 0; i < uv.size(); i++) {
        uv_arr[i] = uv[i];
    }
    for (uint i = 0; i < normals.size(); i++) {
        normals_arr[i] = normals[i];
    }

    m_indices_length = (uint)indices.size();

    glGenVertexArrays(1, &m_vao);

    glBindBuffer(GL_ARRAY_BUFFER, createBuffer());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices_arr, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, createBuffer());
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * uv.size(), uv_arr, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, createBuffer());
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * normals.size(), normals_arr, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    delete[] vertices_arr;
    delete[] uv_arr;
    delete[] normals_arr;
}

Mesh::~Mesh() {
    for (auto it = vbos.begin(); it != vbos.end(); it++) {
        glDeleteBuffers(1, it.base());
    }
    glDeleteVertexArrays(1, &m_vao);
    delete[] m_indices;
}

void Mesh::bind() {
    glBindVertexArray(m_vao);
}

GLuint Mesh::createBuffer() {
    GLuint vbo;
    glGenBuffers(1, &vbo);
    vbos.push_back(vbo);
    return vbo;
}

uint Mesh::size() {
    return m_indices_length;
}

uint *Mesh::getIndices() {
    return m_indices;
}
