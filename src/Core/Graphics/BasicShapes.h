//
// Created by yan on 14.8.17.
//

#pragma once

#include <vector>

namespace BasicShape {

    class Shape{
    public:
        std::vector<float> vertices;
        std::vector<float> uv;
        std::vector<float> normals;
        std::vector<unsigned int> indices;
    };

    class Cube: public Shape {
    public:
        Cube() {
            vertices = {
                // back
                -1.0f, -1.0f,  1.0f, // bottom left
                1.0f, -1.0f,  1.0f,  // bottom right
                -1.0f,  1.0f,  1.0f, // top left
                1.0f,  1.0f,  1.0f,  // top right;
                // front
                -1.0f, -1.0f, -1.0f, // bottom left
                1.0f, -1.0f, -1.0f,  // bottom right
                -1.0f,  1.0f, -1.0f, // top left
                1.0f,  1.0f, -1.0f,  // top right
            };
            uv = {
                0, 1,
                1, 1,
                0, 0,
                1, 0,

                0, 1,
                1, 1,
                0, 0,
                1, 0,

                0, 1,
                1, 1,
                0, 0,
                1, 0,

                0, 1,
                1, 1,
                0, 0,
                1, 0,

                0, 1,
                1, 1,
                0, 0,
                1, 0,

                0, 1,
                1, 1,
                0, 0,
                1, 0,
            };
            normals = {

            };
            indices = {
                0, 1, 2, 2, 3, 1,
                4, 5, 6, 6, 7, 5,
                2, 3, 7, 7, 6, 2,
                0, 1, 5, 5, 4, 0,
            };
        };
    };

}