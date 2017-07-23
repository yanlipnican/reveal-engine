#version 330 core

layout(location = 0) in vec3 vertexPos;
layout(location = 1) in mat4 modelMatrix;
layout(location = 2) in vec3 color;

uniform mat4 camera;

out vec3 fcolor;

void main() {
    fcolor = color;
    gl_Position = camera * modelMatrix * vec4(vertexPos, 1);
}
