#version 120

attribute position;

void main() {
  glPosition = vec4(position, 1.0);
}
