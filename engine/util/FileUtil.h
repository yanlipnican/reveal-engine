//
// Created by yan on 10.7.17.
//

#ifndef ENGINE_STRINGUTIL_H
#define ENGINE_STRINGUTIL_H
#include <fstream>

namespace EngineUtil {

    std::string loadFromFile(std::string filename) {
        std::string str;
        std::ifstream file(filename, std::ios::in);
        if(file.is_open()){
            std::string Line = "";
            while(getline(file, Line))
                str += "\n" + Line;
            file.close();
        }
        return str;
    }

}

#endif //ENGINE_STRINGUTIL_H
