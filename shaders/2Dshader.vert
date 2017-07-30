#version 410 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in float texture_id;
layout(location = 2) in vec3 color;
layout(location = 3) in mat4 model_matrix; //  5,6,7,8 locations because its 4 * vec4, its best practise to put it at end

uniform mat4 camera;

out vec3 fcolor;
out vec2 texCord;
out float textureId;

uniform samplerBuffer uvTexture;

void main() {
    fcolor = color;
    textureId = texture_id;
    texCord = texelFetch(uvTexture, gl_InstanceID * 6 + gl_VertexID).rg;
    gl_Position = camera * model_matrix * vec4(vertex, 1);

}
