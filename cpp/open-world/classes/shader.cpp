#include "../headers/shader.hpp"
#include <iostream>
#include <fstream>

Shader::Shader(const std::string &fileName) {
  program = glCreateProgram();
  shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
  shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

  for(unsigned int i = 0; i < NUM_SHADERS; i++)
    glAttachShader(program, shaders[i]);

  glBindAttribLocation(program, 0, "position");

  glLinkProgram(program);
  CheckShaderError(program, GL_LINK_STATUS, true, "Error linking shader program");

  glValidateProgram(program);
  CheckShaderError(program, GL_LINK_STATUS, true, "Invalid shader program");
}

Shader::~Shader() {
  for(unsigned int i = 0; i < NUM_SHADERS; i++) {
    glDetachShader(program, shaders[i]);
    glDeleteShader(shaders[i]);
  }

  glDeleteProgram(program);
}

void Shader::Bind() {
  glUseProgram(program);
}

std::string Shader::LoadShader(const std::string &fileName) {
  std::ifstream file;
  file.open((fileName).c_str());

  std::string output;
  std::string line;

  if (file.is_open()) {
    while(file.good()) {
      getline(file, line);
      output.append(line + "\n");
    }
  } else {
	std::cerr << "Unable to load shader: " << fileName << std::endl;
  }

  return output;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage) {
  GLint success = 0;
  GLchar error[1024] = { 0 };

  if (isProgram)
    glGetProgramiv(shader, flag, &success);
  else
    glGetShaderiv(shader, flag, &success);

  if (success == GL_FALSE) {
    if (isProgram)
        glGetProgramInfoLog(shader, sizeof(error), NULL, error);
    else
        glGetShaderInfoLog(shader, sizeof(error), NULL, error);

    std::cerr << errorMessage << ": '" << error << "'" << std::endl;
  }
}

GLuint Shader::CreateShader(const std::string &text, unsigned int type) {
  GLuint shader = glCreateShader(type);

  if (shader == 0)
	  std::cerr << "Error compiling shader type " << type << std::endl;

  const GLchar* p[1];
  p[0] = text.c_str();
  GLint lengths[1];
  lengths[0] = text.length();

  glShaderSource(shader, 1, p, lengths);
  glCompileShader(shader);

  CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");

  return shader;
}
