#!/usr/bin/env bash

BIN_DIR="out"
BIN_NAME="engine"
DIR_NAME=`readlink -f "$0"`
DIR_NAME=${DIR_NAME%/*}

download_file() {
    FILENAME=${DIR_NAME}/external/$2
    rm -rf $FILENAME $FILENAME.zip
    wget -O $FILENAME.zip $1
    unzip $FILENAME.zip -d ${DIR_NAME}/external
    rm -rf $FILENAME.zip
}

if [ $1 = "prepare" ]; then
    cmake $DIR_NAME
elif [ $1 = "deps" ]; then
    download_file "https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip" "glfw-3.2.1"
    download_file "https://sourceforge.net/projects/glew/files/glew/2.0.0/glew-2.0.0.zip" "glew-2.0.0"
    download_file "https://github.com/g-truc/glm/releases/download/0.9.8.4/glm-0.9.8.4.zip" "glm"
elif [ $1 = "build" ]; then
    make -C $DIR_NAME
elif [ $1 = "valgrind" ]; then
    valgrind ${DIR_NAME}/${BIN_DIR}/${BIN_NAME} --leak-check=full --show-reachable=yes --track-origins=yes
elif [ $1 = "start" ]; then
    ${DIR_NAME}/${BIN_DIR}/${BIN_NAME}
fi

echo "Done"