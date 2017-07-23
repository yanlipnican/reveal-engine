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

    if (check(vertex, false) || check(fragment, false)) {
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        printError("LOL1");
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
        printError("LOL2");
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

    if (src == nullptr) {
        return 0;
    }

    glShaderSource(shaderId, 1, &src , NULL);
    glCompileShader(shaderId);

    delete[] src;

    return shaderId;
}

bool Shader::check(GLuint programID, bool isProgram) {
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
        for(uint i = 0; i < VertexShaderErrorMessage.size(); i++) {
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

void Shader::setMat4fUniform(const char *uniform, glm::mat4 matrix) {
    glUniformMatrix4fv(getUniformLocation(uniform), 1, GL_FALSE, &matrix[0][0]);
}

int Shader::getUniformLocation(const char *uniform) {
    if (uniform_locations.count(uniform)) {
        uniform_locations[uniform] = glGetUniformLocation(id, uniform);
    }
    return uniform_locations[uniform];
}
