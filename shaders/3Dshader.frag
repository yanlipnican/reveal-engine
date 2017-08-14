#version 410 core
out vec4 color;
in vec2 texCord;

uniform sampler2D diffuse_texture;
uniform vec3 diffuse_color;

void main(){
    color = mix(texture2D(texture, texCord), diffuse_color, 0.5);
}
