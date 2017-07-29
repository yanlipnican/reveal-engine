#version 410 core
out vec4 color;
in vec3 fcolor;
in vec2 texCord;
in float textureId;

uniform sampler2D textures[32];

void main(){
    highp int id = int(textureId + .5);
    color = texture2D(textures[id], texCord);
}
