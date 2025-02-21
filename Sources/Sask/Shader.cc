#include <Sask/Shader.hpp>
#include <iostream>
using sask::Shader;

Shader::Shader(std::string content, ShaderKind kind)
{
  this->id = glCreateShader(kind);

  const char *glShader = content.c_str();
  glShaderSource(id, 1, &glShader, NULL);
  glCompileShader(id);
}

void Shader::Attach(unsigned int programme)
{
  glAttachShader(programme, this->id);
}