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
}

Renderer2D::~Renderer2D() {
    delete shader;
}

void Renderer2D::flush() {

    shader->bind();
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    static const GLfloat quad_vertices[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            1.0f,  1.0f, 0.0f,
            //
            1.0f,  1.0f, 0.0f,
            -1.0f, 1.0f, 0.0f,
            -1.0f, -1.0f, 0.0f
    };
    // This will identify our vertex buffer
    GLuint vertexbuffer;
// Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
// The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
// Give our vertices to OpenGL.
    glBindVertexArray(VertexArrayID);

    glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), quad_vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );


    GLuint color_buffer;
    glGenBuffers(1, &color_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, color_buffer);
    glm::vec3 colorArray[queue.size()];

    for (uint i = 0; i < queue.size(); i++) {
        colorArray[i] = queue[i]->getColor();
    }
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * queue.size(), &colorArray[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
            1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            3 * sizeof(float),  // stride
            (void*)0            // array buffer offset
    );
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glVertexAttribDivisor(1, 1);
// Draw the triangle !
    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, queue.size()); // Starting from vertex 0; 6 vertices total -> 2 triangles
    queue.clear();
}

void Renderer2D::submit(Engine::Core::Renderable2D* object) {
    queue.push_back(object);
}

void Renderer2D::sortQueue() {

}

