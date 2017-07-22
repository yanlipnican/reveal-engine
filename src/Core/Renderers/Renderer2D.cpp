//
// Created by yan on 15.7.17.
//

#include <GL/glew.h>
#include <iostream>
#include <src/Core/Shader.h>
#include "Renderer2D.h"

using namespace Engine::Core;

Renderer2D::Renderer2D() {
    shader = new Shader("../shaders/2Dshader.vert", "../shaders/2Dshader.frag");
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    vbos.push_back(vertexBuffer);

    GLuint colorBuffer;
    glGenBuffers(1, &colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glVertexAttribDivisor(1, 1);
    vbos.push_back(colorBuffer);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Renderer2D::~Renderer2D() {
    delete shader;
    delete[] quad;
}

void Renderer2D::flush() {

    shader->bind();
    glBindVertexArray(vao);
    loadBuffers();
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, (int)queue.size());
    queue.clear();

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glUseProgram(0);
    glBindBuffer(GL_VERTEX_ARRAY, 0);
    glBindVertexArray(0);

}

void Renderer2D::loadBuffers() {

    // load vertices
    glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);

    // load colors
    glm::vec3 colorArray[queue.size()];
    for (uint i = 0; i < queue.size(); i++) {
        colorArray[i] = queue[i]->getColor();
    }

    glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * queue.size(), &colorArray[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);

}

void Renderer2D::submit(Engine::Core::Renderable2D* object) {
    queue.push_back(object);
}

void Renderer2D::sortQueue() {

}

