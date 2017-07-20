#!/usr/bin/env bash

BIN_DIR="out"
BIN_NAME="engine"
DIR_NAME=`readlink -f "$0"`
DIR_NAME=${DIR_NAME%/*}

if [ $1 = "prepare" ]; then
    cmake $DIR_NAME
elif [ $1 = "build" ]; then
    make -C $DIR_NAME
elif [ $1 = "valgrind" ]; then
    valgrind ${DIR_NAME}/${BIN_DIR}/${BIN_NAME} --leak-check=full --show-reachable=yes
elif [ $1 = "start" ]; then
    ${DIR_NAME}/${BIN_DIR}/${BIN_NAME}
fi