//
// Created by yan on 17.7.17.
//

#include <vector>
#include <sstream>
#include <iostream>
#include <cstring>
#include "Shader.h"
#include "src/Util/FileUtil.h"

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
    int length = (int)strlen(src);
    glShaderSource(shaderId, 1, &src , &length);
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

    if ( info_log_length > 0 ){
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

GLuint Shader::getUniformLocation(const char *uniform) {
    if (!shader_locations.count(uniform)) {
        shader_locations[uniform] = glGetUniformLocation(id, uniform);
    }
    return shader_locations[uniform];
}

GLuint Shader::getAttribLocation(const char *attrib) {
    if (!shader_locations.count(attrib)) {
        shader_locations[attrib] = glGetAttribLocation(id, attrib);
    }
    return shader_locations[attrib];
}

void Shader::setMat4fUniform(const char *uniform, glm::mat4 matrix) {
    glUniformMatrix4fv(getUniformLocation(uniform), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::set3fUniform(const char *uniform, glm::vec3 vec) {
    glUniform3f(getUniformLocation(uniform), vec[0], vec[1], vec[2]);
}

void Shader::set1iUniform(const char *uniform, int i) {
    glUniform1i(getUniformLocation(uniform), i);
}
