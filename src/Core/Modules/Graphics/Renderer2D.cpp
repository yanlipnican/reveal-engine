//
// Created by yan on 15.7.17.
//

#include <GL/glew.h>
#include <iostream>
#include <src/Core/Shader.h>
#include <functional>
#include <src/Core/Modules/Graphics/Camera.h>
#include "Renderer2D.h"

#include "glm/gtc/matrix_transform.hpp"

using namespace Engine::Core;

Renderer2D::Renderer2D() {

    shader = new Shader("shaders/2Dshader.vert", "shaders/2Dshader.frag");
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    addVertexBuffer("vertex", 3, 0, 1, 0);
    addVertexBuffer("uv", 2, 0, 1, 0);
    addVertexBuffer("color", 3, 3 * sizeof(float), 1, 0, 1);
    addVertexBuffer("model_matrix", 4, sizeof(glm::mat4), 4, sizeof(glm::vec4), 1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Renderer2D::~Renderer2D() {
    delete shader;
}

uint Renderer2D::addVertexBuffer(const char* attrib, uint size, uint stride, uint length, uint offset) {
    vbo v;
    v.length = length;
    v.attrib_location = shader->getAttribLocation(attrib);
    glGenBuffers(1, &v.id);
    glBindBuffer(GL_ARRAY_BUFFER, v.id);
    for (uint i = 0; i < length; i++) {
        glVertexAttribPointer(v.attrib_location + i, size, GL_FLOAT, GL_FALSE, stride, (void*)(offset * i));
    }
    vbos[attrib] = v;
    return v.attrib_location;
}

uint Renderer2D::addVertexBuffer(const char* attrib, uint size, uint stride, uint length, uint offset, uint attrib_divisor) {
    uint location = addVertexBuffer(attrib, size, stride, length, offset);
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
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, loadBuffers());

    for (auto vbo = vbos.begin(); vbo != vbos.end(); vbo++) {
        for (uint l = 0; l < vbo->second.length; l++) {
            glDisableVertexAttribArray(vbo->second.attrib_location + l);
        }
    }
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    if (queue.size() > 0) {
        flush(camera);
    }

}

uint Renderer2D::loadBuffers() {

    // setup arrays
    glm::vec3* colorArray = new glm::vec3[queue.size()];
    glm::mat4* arr = new glm::mat4[queue.size()];

    uint count = 0;

    Queue secondPass;

    bool textureLimit = false;

    for (uint i = 0; i < queue.size(); i++) {
        if (textureLimit) {
            secondPass.push_back(queue[i]);
            continue;
        }

        // model matrix
        arr[count] = queue[i]->getModelMatrix();
        // color
        colorArray[count] = queue[i]->getColor();

        count++;
    }

    queue = secondPass;

    // vertex
    bindBuffer("vertex");
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);

    // uv
    bindBuffer("uv");
    glBufferData(GL_ARRAY_BUFFER, sizeof(uv), uv, GL_STATIC_DRAW);

    // color
    bindBuffer("color");
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * count, &colorArray[0], GL_STATIC_DRAW);
    delete[] colorArray;

    // model matrix
    bindBuffer("model_matrix");
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4) * count, &arr[0], GL_STATIC_DRAW);
    delete[] arr;

    // enable attrib arrays in VAO
    for (auto vbo = vbos.begin(); vbo != vbos.end(); vbo++) {
        for (uint l = 0; l < vbo->second.length; l++) {
            glEnableVertexAttribArray(vbo->second.attrib_location + l);
        }
    }

    return count;
}

void Renderer2D::submit(Engine::Core::Renderable2D* object) {
    queue.push_back(object);
}

void Renderer2D::bindBuffer(const char *name) {
    glBindBuffer(GL_ARRAY_BUFFER, vbos[name].id);
}
