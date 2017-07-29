#version 410 core

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec4 atlas;
layout(location = 3) in float texture_id;
layout(location = 4) in vec3 color;
layout(location = 5) in mat4 model_matrix; //  5,6,7,8 locations because its 4 * vec4, its best practise to put it at end

uniform mat4 view;
uniform mat4 projection;

out vec3 fcolor;
out vec2 texCord;
out float textureId;

vec2 getUVAtlas(vec2 uv, vec4 atlas) {
    float x = 1.0 / atlas.x * atlas.z;
    float y = 1.0 / atlas.y * atlas.w;
    return vec2(x + uv.x / atlas.x, y + uv.y / atlas.y);
}

void main() {
    fcolor = color;
    textureId = texture_id;
    texCord = getUVAtlas(uv, atlas);
    gl_Position = projection * view * model_matrix * vec4(vertex, 1);

}
