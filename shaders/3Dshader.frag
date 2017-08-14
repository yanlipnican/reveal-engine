#version 410 core
out vec4 color;
in vec2 texCord;

uniform sampler2D diffuse_texture;
uniform vec3 diffuse_color;

void main(){
    color = texture2D(diffuse_texture, texCord);
}
