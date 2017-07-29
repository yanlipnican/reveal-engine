#version 410 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 uv;
layout(location = 2) in float texture_id;
layout(location = 3) in vec3 color;
layout(location = 4) in mat4 model_matrix; //  2,3,4,5 locations because its 4 * vec4, its best practise to put it at end

uniform mat4 view;
uniform mat4 projection;

out vec3 fcolor;
out vec2 texCord;
out float textureId;
void main() {
    fcolor = color;
    textureId = texture_id;
    texCord = uv;
    gl_Position = projection * view * model_matrix * vec4(vertex, 1);

}
