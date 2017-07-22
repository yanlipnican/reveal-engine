#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 color;
out vec3 fcolor;
void main() {
    fcolor = color;
    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;
}