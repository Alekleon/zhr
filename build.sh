#!/bin/bash

CXX_C=g++
C_C=gcc

rm -rf ./build
install -d build
cd build
cmake -DCMAKE_CXX_COMPILER=$CXX_C -DCMAKE_C_COMPILER=$C_C -DCMAKE_BUILD_TYPE=Debug ../
make
