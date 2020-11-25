#!/bin/bash

RUN_MODE=Debug
RUN_NAME=zhr

while [ -n "$1" ]
do
	case "$1" in
		-D) RUN_MODE=Debug ;;
		-R) RUN_MODE=Release ;;
		-f) 
			shift
			if [ -n "$1" ]; then
				RUN_NAME=$1
			fi
			;;			
		*) echo "$1 не опция" ;;
	esac
	shift
done

./Distrib/Linux_x86_64/"$RUN_MODE"/bin/"$RUN_NAME"
