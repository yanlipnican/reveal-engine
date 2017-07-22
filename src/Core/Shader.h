//
// Created by yan on 17.7.17.
//

#pragma once

#include <external/glew-2.0.0/include/GL/glew.h>
#include <iostream>
namespace Engine { namespace Core {

    class Shader {
    private:
        GLuint id;
    public:
        Shader(const char* vertex_filename, const char* fragment_filename);
        ~Shader();
        void bind();
    private:
        GLuint compile(const char* filename, GLenum type);
        bool check(GLuint programID, bool isProgram);
        void printError(std::string log);
    };

}}
