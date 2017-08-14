//
// Created by yan on 17.7.17.
//

#pragma once

#include <external/glew-2.0.0/include/GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>
#include <map>

namespace Engine { namespace Core {

    class Shader {
    private:
        GLuint id;
        std::map<const char*, GLuint> shader_locations;
    public:
        Shader(const char* vertex_filename, const char* fragment_filename);
        ~Shader();
        void bind();
        GLuint getUniformLocation(const char* uniform);
        GLuint getAttribLocation(const char* attrib);
        void setMat4fUniform(const char* uniform, glm::mat4 matrix);
        void set3fUniform(const char *uniform, glm::vec3 vec);
        void set1iUniform(const char *uniform, int i);
    private:
        GLuint compile(const char* filename, GLenum type);
        bool check(GLuint programID, bool isProgram);
        void printError(std::string log);
    };

}}
