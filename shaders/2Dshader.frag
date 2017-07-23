#version 410 core
out vec3 color;
in vec3 fcolor;
void main(){
  color = vec3(1,1,1) * fcolor;
}
