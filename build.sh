#!/bin/bash

CXX_C=g++
C_C=gcc

if [[ -n "$1" ]]; then
	BUILD_DIR=$1
else
	BUILD_DIR=build
fi

rm -rf ./$BUILD_DIR
install -d $BUILD_DIR
cd $BUILD_DIR
cmake -DCMAKE_CXX_COMPILER=$CXX_C -DCMAKE_C_COMPILER=$C_C -DCMAKE_BUILD_TYPE=Debug ../
make
