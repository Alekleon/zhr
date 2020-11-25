#!/bin/bash

#initial input values
CXX_COMPILER=g++
C_COMPILER=gcc
COMPILE_MODE=Debug
BUILD_DIR=Build
#BUILD_NAME=zhr

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
#		-f) 
#			shift
#			if [ -n "$1" ]; then
#				BUILD_NAME=$1
#			fi
#			;;			
		*) echo "$1 не опция" ;;
	esac
	shift
done

# rm -rf ./"$BUILD_DIR"
install -d "$BUILD_DIR"
cd "$BUILD_DIR"
cmake -DCMAKE_CXX_COMPILER=$CXX_COMPILER -DCMAKE_C_COMPILER=$C_COMPILER -DCMAKE_BUILD_TYPE=$COMPILE_MODE ../
make
