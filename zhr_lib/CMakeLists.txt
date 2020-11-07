project(cts_lib)

#!/bin/bash
while [ -n "$1" ]
do
case "$1" in
-a | -b | -c) echo "Найдена опция $1" ;;
*) echo "$1 не опция" ;;
esac
shift
done

cmake_minimum_required(VERSION 3.4)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

get_filename_component(LIB_CTS_PRODUCT ${CMAKE_CURRENT_SOURCE_DIR}/../../ ABSOLUTE)
set(OS_IDENT "${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")
set(LIB_CTS_DESTINATION ${CTS_PRODUCT}/distr/lib/${OS_IDENT})

#-------------	TO REMOVE THIS BLOCK.
#include(../common.cmake)
#get_filename_component(CTS_PRODUCT ${CMAKE_CURRENT_SOURCE_DIR}/../../../ ABSOLUTE)
#set(CTS_OS_IDENT "${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")
#set(CTS_DESTINATION ${CTS_PRODUCT}/distr/lib/${CTS_OS_IDENT}) #

# Static library is created by command add_library(... STATIC ...)
# and always is treated as "archive", not (dynamic) library.

# To set output directory for it you can either set global 
# variable _before_ command "add_library":
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${DESTINATION}")
# (variable ARCHIVE_OUTPUT_DIRECTORY doesn't influence)

# or set current target property _after_ creation (preferred for subprojects): 
#set_target_properties( ${PROJECT_NAME}
#	PROPERTIES
#  ARCHIVE_OUTPUT_DIRECTORY "${DESTINATION}" )

# Ideally we suppose global variable is already set. 
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CTS_DESTINATION}")
#-------------

set(HEADER_FILES
	cts_basics.h
	cts_files.h  
	cts_lib.h  
	cts_strings.h  

	cts_arg_parser.h
	cts_conf_parser.h
	cts_sockets.h  
) 

set(SOURCE_FILES
	cts_basics.cpp
	cts_files.cpp  
	cts_lib.cpp  
	cts_strings.cpp  

	cts_arg_parser.cpp
	cts_conf_parser.cpp
	cts_sockets.cpp  
)

assign_source_group(${HEADER_FILES} ${SOURCE_FILES})

add_library ( ${PROJECT_NAME} STATIC 
	${HEADER_FILES}
	${SOURCE_FILES}
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_NAME libcts )
else ()
	set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_NAME cts )
endif()
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${LIB_CTS_DESTINATION}" )
