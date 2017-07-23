#version 330 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 color;
layout(location = 2) in mat4 modelMatrix; //  2,3,4,5 locations because its 4 * vec4.

uniform mat4 cam;

out vec3 fcolor;

void main() {
    fcolor = color;
    gl_Position = cam * modelMatrix * vec4(vertex, 1);
}
