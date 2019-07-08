#ifndef SHADER_INCLUDED_H
#define SHADER_INCLUDED_H

#include <string>
#include <GL/glew.h>

class Shader {
  public:
    Shader(const std::string &filename);

    void Bind();

    virtual ~Shader();

  private:
    static const unsigned int NUM_SHADERS = 2;

    std::string LoadShader(const std::string &fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);
    GLuint CreateShader(const std::string &text, unsigned int type);

    GLuint program;
    GLuint shaders[NUM_SHADERS];
};

#endif
