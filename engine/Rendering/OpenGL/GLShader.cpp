//
// Created by yan on 10.7.17.
//

#include "GLShader.h"
#include "engine/util/FileUtil.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace Engine;

typedef const char* const * shader_source;

struct ShaderCompilationError {
    bool isError;
    std::string error;
};

ShaderCompilationError compileShader(GLuint, std::string);

ShaderCompilationError checkProgram(GLuint);

GLShader::GLShader(std::string vert_filename, std::string frag_filename) {

    GLuint ProgramID = glCreateProgram();

    std::string vert_src = EngineUtil::loadFromFile(vert_filename);
    std::string frag_src = EngineUtil::loadFromFile(frag_filename);

    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    ShaderCompilationError vert_compilation = compileShader(VertexShaderID, vert_src);
    if (vert_compilation.isError) {
        std::cout << vert_compilation.error << std::endl;
        compiled = false;
    }

    ShaderCompilationError frag_compilation = compileShader(FragmentShaderID, frag_src);
    if (frag_compilation.isError) {
        std::cout << frag_compilation.error << std::endl;
        compiled = false;
    }

    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    checkProgram(ProgramID);

    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

}

GLuint GLShader::getProgram() {
    return id;
}

ShaderCompilationError checkProgram(GLuint id) {
    // Check the program

    GLint Result = GL_FALSE;
    int InfoLogLength;

    glGetProgramiv(id, GL_LINK_STATUS, &Result);
    glGetProgramiv(id, GL_INFO_LOG_LENGTH, &InfoLogLength);

    ShaderCompilationError result;
    result.isError = false;

    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(id, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        std::stringstream stream;
        for(int i = 0; i < ProgramErrorMessage.size(); i++) {
            stream << ProgramErrorMessage[i];
        }
        result.isError = true;
        result.error = stream.str();
    }

    return result;
}

ShaderCompilationError compileShader(GLuint id, std::string source) {
    GLint Result = GL_FALSE;
    int InfoLogLength;

    glShaderSource(id, 1, (shader_source)source.c_str() , NULL);
    glCompileShader(id);

    glGetShaderiv(id, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &InfoLogLength);

    ShaderCompilationError result;
    result.isError = false;

    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(id, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        std::stringstream stream;
        for(int i = 0; i < VertexShaderErrorMessage.size(); i++) {
            stream << VertexShaderErrorMessage[i];
        }
        result.isError = true;
        result.error = stream.str();
    }

    return result;
}