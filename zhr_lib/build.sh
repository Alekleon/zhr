#!/bin/bash

#FLEX_PATH must be supplied as parameter from konfig system, or elswere if konfig is not built yet
FLEX_PATH="../../../../../../3rdparty/flex/flex-2.6.4/distr/bin/Linux/gcc_centos7_x64_centos7_x64-2.0/"

FLEX_DIR_V=$FLEX_PATH
FLEX_EXECUTABLE_V=${FLEX_DIR_V}/flex

CXX_C=g++
C_C=gcc

function help
{
echo "info: $1 compilator not supplied as parameter"
echo "info: $0 <c++ compilator> <c compilator> [intermediate_dir]"
echo "info: Example : $0 /opt/cross/gcc_centos7_x64_centos7_x64-2.0/bin/x86_64-pc-linux-g++ /opt/cross/gcc_centos7_x64_centos7_x64-2.0/bin/x86_64-pc-linux-gcc"
echo "info: using default system compilator"
}

if [[ -z "$2" ]]; then
C_C=gcc
help "c++"
else
C_C=$2
fi

if [[ -z "$1" ]]; then
C_C=gcc
help "c"
else
CXX_C=$1
fi

rm -rf ./build
install -d build
cd build
cmake -DFLSEX_DIR=${FLEX_DIR_V} -DFLEX_EXECUTABLE=${FLEX_EXECUTABLE_V} -DCMAKE_CXX_COMPILER=$CXX_C -DCMAKE_C_COMPILER=$C_C ../
make
