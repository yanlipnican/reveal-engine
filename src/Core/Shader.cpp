//
// Created by yan on 17.7.17.
//

#include <vector>
#include <sstream>
#include <iostream>
#include "Shader.h"
#include "src/Util/Util.h"

using namespace Engine::Util;
using namespace Engine::Core;

Shader::Shader(const char* vertex_filename, const char* fragment_filename) {

    GLuint vertex = compile(vertex_filename, GL_VERTEX_SHADER);
    GLuint fragment = compile(fragment_filename, GL_FRAGMENT_SHADER);

    if (check(vertex) || check(fragment)) {
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        return;
    }

    id = glCreateProgram();

    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);

    glDetachShader(id, vertex);
    glDetachShader(id, fragment);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    if (check(id, true)) {
        glDeleteProgram(id);
    }

}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::bind() {
    glUseProgram(id);
}

GLuint Shader::compile(const char* filename, GLenum type) {
    GLuint shaderId = glCreateShader(type);
    const char* src = FileUtil::loadFile(filename);

    glShaderSource(shaderId, 1, (const GLchar* const *)src , NULL);
    glCompileShader(shaderId);

    delete[] src;

    return id;
}

bool Shader::check(GLuint programID, bool isProgram = false) {
    GLint compilation_result = GL_FALSE;
    int info_log_length;

    if (isProgram) {
        glGetProgramiv(programID, GL_LINK_STATUS, &compilation_result);
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &info_log_length);
    } else {
        glGetShaderiv(programID, GL_COMPILE_STATUS, &compilation_result);
        glGetShaderiv(programID, GL_INFO_LOG_LENGTH, &info_log_length);
    }

    if ( info_log_length> 0 ){
        std::vector<char> VertexShaderErrorMessage(info_log_length + 1);
        glGetShaderInfoLog(programID, info_log_length, NULL, &VertexShaderErrorMessage[0]);
        std::stringstream stream;
        for(int i = 0; i < VertexShaderErrorMessage.size(); i++) {
            stream << VertexShaderErrorMessage[i];
        }
        printError(stream.str());
        return true;
    }

    return false;
}

void Shader::printError(std::string log) {
    std::cout << log << std::endl;
}
