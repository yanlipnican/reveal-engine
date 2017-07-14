//
// Created by yan on 10.7.17.
//

#ifndef ENGINE_GLSHADER_H
#define ENGINE_GLSHADER_H

#include <string>
#include <engine/Rendering/Shader.h>
#include <engine/Rendering/OpenGL/GLRenderer.h>

namespace Engine {

    class GLShader : public Shader {
        GLuint id;
    public:
        GLShader(std::string, std::string);

        GLuint getProgram();
    };

}


#endif //ENGINE_GLSHADER_H
