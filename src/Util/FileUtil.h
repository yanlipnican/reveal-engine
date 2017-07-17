//
// Created by yan on 15.7.17.
//

#pragma once

#include <cstdio>

namespace Engine::Util::FileUtil {

    const char* loadFile(const char* filename) const {
        char *buffer;
        unsigned long length;
        FILE *file = fopen(filename, "rb");

        if (file) {
            fseek(file, 0, SEEK_END);
            length = (unsigned long) ftell(file);
            fseek(file, 0, SEEK_SET);
            buffer = new char[length];
            fread(buffer, 1, length, file);
            fclose(file);
            return buffer;
        }

        return nullptr;
    }

}