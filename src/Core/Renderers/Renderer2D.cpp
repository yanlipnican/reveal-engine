//
// Created by yan on 15.7.17.
//

#include <GL/glew.h>
#include <iostream>
#include <src/Core/Shader.h>
#include <functional>
#include "Renderer2D.h"

#include "glm/gtc/matrix_transform.hpp"

using namespace Engine::Core;

Renderer2D::Renderer2D() {

    shader = new Shader("../shaders/2Dshader.vert", "../shaders/2Dshader.frag");
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    addVertexBuffer(3, 0, [this](){
        glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);
    });

    addVertexBuffer(3, 3* sizeof(float), 1, [this](){
        glm::vec3* colorArray = new glm::vec3[queue.size()];
        for (uint i = 0; i < queue.size(); i++) {
            colorArray[i] = queue[i]->getColor();
        }
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * queue.size(), &colorArray[0], GL_STATIC_DRAW);
        delete[] colorArray;
    });

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Renderer2D::~Renderer2D() {
    delete shader;
}

uint Renderer2D::addVertexBuffer(uint size, uint stride, std::function<void()> onData) {
    vbo v;
    v.onData = onData;
    uint location = (uint)vbos.size();
    glGenBuffers(1, &v.id);
    glBindBuffer(GL_ARRAY_BUFFER, v.id);
    glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, stride, (void*)0);
    vbos.push_back(v);
    return location;
}

uint Renderer2D::addVertexBuffer(uint size, uint stride, uint attrib_divisor, std::function<void()> onData) {
    uint location = addVertexBuffer(size, stride, onData);
    glVertexAttribDivisor(location, attrib_divisor);
    return location;
}

void Renderer2D::flush() {

    shader->bind();
    glBindVertexArray(vao);
    loadBuffers();
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, (int)queue.size());
    queue.clear();

    for (uint i = 0 ; i < vbos.size(); i++) {
        glDisableVertexAttribArray(i);
    }
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Renderer2D::loadBuffers() {
    for (uint i = 0; i < vbos.size(); i++) {
        glBindBuffer(GL_ARRAY_BUFFER, vbos[i].id);
        vbos[i].onData();
        glEnableVertexAttribArray(i);
    }
}

void Renderer2D::submit(Engine::Core::Renderable2D* object) {
    queue.push_back(object);
}

void Renderer2D::sortQueue() {

}

