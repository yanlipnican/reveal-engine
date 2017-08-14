#version 410 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

uniform mat4 camera;
uniform mat4 model_matrix;

out vec2 texCord;

void main() {
    texCord = uv;
    gl_Position = camera * model_matrix * vec4(vertex, 1);
}
