//
// Created by yan on 15.7.17.
//

#include <GL/glew.h>
#include <iostream>
#include <src/Core/Graphics/Shader.h>
#include <src/Core/Graphics/Camera.h>
#include "Renderer2D.h"

#define TEXTURE_LIMIT 31

using namespace Engine::Core;

Renderer2D::Renderer2D() {

    shader = new Shader("shaders/2Dshader.vert", "shaders/2Dshader.frag");
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    addVertexBuffer("vertex", 3, 0, 1, 0);
    addVertexBuffer("texture_id", 1, sizeof(float), 1, 0, 1);
    addVertexBuffer("color", 3, 3 * sizeof(float), 1, 0, 1);
    addVertexBuffer("model_matrix", 4, sizeof(glm::mat4), 4, sizeof(glm::vec4), 1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenTextures(1, &uv_tex);
    glGenBuffers(1, &textureBuffer);
}

Renderer2D::~Renderer2D() {
    delete shader;
}

uint Renderer2D::addVertexBuffer(const char* attrib, uint size, uint stride, uint length, std::size_t offset) {
    vbo v;
    v.length = length;
    v.attrib_location = shader->getAttribLocation(attrib);
    glGenBuffers(1, &v.id);
    glBindBuffer(GL_ARRAY_BUFFER, v.id);
    for (uint i = 0; i < length; i++) {
        glVertexAttribPointer(v.attrib_location + i, size, GL_FLOAT, GL_FALSE, stride, (GLvoid*)(offset * i));
    }
    vbos[attrib] = v;
    return v.attrib_location;
}

uint Renderer2D::addVertexBuffer(const char* attrib, uint size, uint stride, uint length, std::size_t offset, uint attrib_divisor) {
    uint location = addVertexBuffer(attrib, size, stride, length, offset);
    for (uint i = 0; i < length; i++) {
        glVertexAttribDivisor(location + i, attrib_divisor);
    }
    return location;
}

void Renderer2D::flush(Camera camera) {
    glEnable(GL_CULL_FACE);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);

    if (queue.size() > 0) {
        flush(camera);
    }

}

uint Renderer2D::loadBuffers() {

    // setup arrays
    unsigned long queueSize = queue.size();
    glm::vec3* color_arr = new glm::vec3[queueSize];
    float* uvTextureArray = new float[queueSize * 12];
    glm::mat4* model_matrix_arr = new glm::mat4[queueSize];
    float* texture_ids = new float[queueSize];

    Queue secondPass;

    // setup textures
    std::map<uint, uint> textures;
    uint textureCount = 0;
    uint count = 0;
    char textureAttrib[13];

    for (uint i = 0; i < queue.size(); i++) {

        // Textures
        // TODO: in release mode this works fast, but in debug it slows engine. Create better algorithm
        uint texId = queue[i]->getTexture()->getId();
        if (!textures.count(texId)) {
            if (textureCount > TEXTURE_LIMIT) {
                secondPass.push_back(queue[i]);
                std::cout << "texture_overflow" << std::endl;
                continue;
            }
            textures[texId] = textureCount;
            sprintf(textureAttrib, "textures[%u]", textureCount);

            glActiveTexture(GL_TEXTURE0 + textureCount);
            glBindTexture(GL_TEXTURE_2D, texId);
            glUniform1i(shader->getUniformLocation(textureAttrib), textureCount);
            textureCount++;
        }
        texture_ids[count] = textures[texId];

        float* uv = queue[i]->getUV();

        for (int t = 0; t < 12; t++) {
            uvTextureArray[count * 12 + t] = uv[t];
        }

        // model matrix
        model_matrix_arr[count] = queue[i]->getModelMatrix();
        // color
        color_arr[count] = queue[i]->getColor();

        count++;
    }

    queue = secondPass;

    // vertex
    bindBuffer("vertex");
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);

    // uv texture
    glBindBuffer(GL_TEXTURE_BUFFER, textureBuffer);
    glBufferData(GL_TEXTURE_BUFFER, sizeof(float) * 12 * count, uvTextureArray, GL_STATIC_DRAW);
    glActiveTexture(GL_TEXTURE31);
    glBindTexture(GL_TEXTURE_BUFFER, uv_tex);
    glTexBuffer(GL_TEXTURE_BUFFER, GL_RG32F, textureBuffer);
    glUniform1i(shader->getUniformLocation("uvTexture"), 31);
    delete[] uvTextureArray;

    // texture id
    bindBuffer("texture_id");
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, texture_ids, GL_STATIC_DRAW);
    delete[] texture_ids;

    // color
    bindBuffer("color");
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * count, color_arr, GL_STATIC_DRAW);
    delete[] color_arr;

    // model matrix
    bindBuffer("model_matrix");
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::mat4) * count, model_matrix_arr, GL_STATIC_DRAW);
    delete[] model_matrix_arr;

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

