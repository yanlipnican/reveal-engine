//
// Created by yan on 17.7.17.
//

#pragma once

#include <external/glew-2.0.0/include/GL/glew.h>

namespace Engine { namespace Core {

    class Shader {
    private:
        Shader(const char* vertex_filename, const char* fragment_filename);
        ~Shader();
        GLuint id;
    public:
        void bind();
    private:
        GLuint compile(const char* filename, GLenum type);
        bool check(GLuint programID, bool isProgram = false);
        void printError(std::string log);
    };

}}
