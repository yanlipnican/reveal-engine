//
// Created by yan on 12.8.17.
//

#pragma once

#include <vector>
#include <src/OpenGL.h>

namespace Engine {
namespace Core {

typedef unsigned int uint;

class Mesh {
private:
    GLuint m_vao;
    std::vector<GLuint> vbos;
    GLuint createBuffer();
    uint m_indices_length;
    uint* m_indices;
public:
    Mesh(std::vector<float>& vertices, std::vector<uint>& indices, std::vector<float>& uv, std::vector<float>& normals);
    ~Mesh();
    void bind();
    /**
     * How much vertices to render
     */
    uint size();
    uint* getIndices();
};

}
}


