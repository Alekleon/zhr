#!/bin/bash

#initial input values
CXX_COMP=g++
C_COMP=gcc
COMP_MODE=Debug
BUILD_DIR=build
BUILD_NAME=zhr

while [ -n "$1" ]
do
	case "$1" in
		-D) COMPILE_MODE=Debug ;;
		-R) COMPILE_MODE=Release ;;
		-d) 
			shift
			if [ -n "$1" ]; then
				BUILD_DIR=$1
			fi
			;;			
		-f) 
			shift
			if [ -n "$1" ]; then
				BUILD_NAME=$1
			fi
			;;			
		*) echo "$1 не опция" ;;
	esac
	shift
done

rm -rf ./"$BUILD_DIR"
install -d "$BUILD_DIR"
cd "$BUILD_DIR"
cmake -DCMAKE_CXX_COMPILER=$CXX_COMP -DCMAKE_C_COMPILER=$C_COMP -DCMAKE_BUILD_TYPE=$COMP_MODE ../
make
