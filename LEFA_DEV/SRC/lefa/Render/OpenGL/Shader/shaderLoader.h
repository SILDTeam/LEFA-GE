#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lefa/ThirdParty/glad/OpenGl/glad_gl.h";

char* get_shader_content(const char* fileName);

void compile_shader(GLuint* shaderId, GLenum shaderType, const char* shaderFilePath);

void link_shader(GLuint programID, GLuint vertexShaderID, GLuint fragmentShaderID);

