//
// Created by yan on 15.7.17.
//

#include <GL/glew.h>
#include <iostream>
#include <src/Core/Shader.h>
#include <functional>
#include <src/Core/Camera.h>
#include "Renderer2D.h"

#include "glm/gtc/matrix_transform.hpp"

using namespace Engine::Core;

Renderer2D::Renderer2D() {

    shader = new Shader("../shaders/2Dshader.vert", "../shaders/2Dshader.frag");
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    addVertexBuffer("vertex", 3, 0, 1, 0, [this](){
        glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);
    });

    addVertexBuffer("color", 3, 3 * sizeof(float), 1, 0, 1, [this](){
        glm::vec3* colorArray = new glm::vec3[queue.size()];
        for (uint i = 0; i < queue.size(); i++) {
            colorArray[i] = queue[i]->getColor();
        }
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * queue.size(), &colorArray[0], GL_STATIC_DRAW);
        delete[] colorArray;
    });

    addVertexBuffer("model_matrix", 4, sizeof(glm::mat4), 4, sizeof(glm::vec4), 1, [this](){
        glm::mat4* arr = new glm::mat4[queue.size()];
        for (uint i = 0; i < queue.size(); i++) {
            arr[i] = queue[i]->getModelMatrix();
        }
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4) * queue.size(), &arr[0], GL_STATIC_DRAW);
        delete[] arr;
    });

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Renderer2D::~Renderer2D() {
    delete shader;
}

uint Renderer2D::addVertexBuffer(const char* attrib, uint size, uint stride, uint length, uint offset, std::function<void()> onData) {
    vbo v;
    v.onData = onData;
    v.length = length;
    v.attrib_location = shader->getAttribLocation(attrib);
    glGenBuffers(1, &v.id);
    glBindBuffer(GL_ARRAY_BUFFER, v.id);
    for (uint i = 0; i < length; i++) {
        glVertexAttribPointer(v.attrib_location + i, size, GL_FLOAT, GL_FALSE, stride, (void*)(offset * i));
    }
    vbos.push_back(v);
    return v.attrib_location;
}

uint Renderer2D::addVertexBuffer(const char* attrib, uint size, uint stride, uint length, uint offset, uint attrib_divisor, std::function<void()> onData) {
    uint location = addVertexBuffer(attrib, size, stride, length, offset, onData);
    for (uint i = 0; i < length; i++) {
        glVertexAttribDivisor(location + i, attrib_divisor);
    }
    return location;
}

void Renderer2D::flush(Camera camera) {

    shader->bind();
    shader->setMat4fUniform("view", camera.getView());
    shader->setMat4fUniform("projection", camera.getProjection());
    glBindVertexArray(vao);
    loadBuffers();
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, (int)queue.size());
    queue.clear();

    for (uint i = 0 ; i < vbos.size(); i++) {
        for (uint l = 0; l < vbos[i].length; l++) {
            glDisableVertexAttribArray(vbos[i].attrib_location + l);
        }
    }
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Renderer2D::loadBuffers() {
    for (uint i = 0; i < vbos.size(); i++) {
        glBindBuffer(GL_ARRAY_BUFFER, vbos[i].id);
        vbos[i].onData();
        for (uint l = 0; l < vbos[i].length; l++) {
            glEnableVertexAttribArray(vbos[i].attrib_location + l);
        }
    }
}

void Renderer2D::submit(Engine::Core::Renderable2D* object) {
    queue.push_back(object);
}

void Renderer2D::sortQueue() {

}

