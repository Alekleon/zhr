cmake_minimum_required(VERSION 3.4)

project(zhr)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

#get_filename_component(LIB_ZHR_PRODUCT ${CMAKE_CURRENT_SOURCE_DIR}/../../ ABSOLUTE)
#set(OS_IDENT "${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")
#set(LIB_ZHR_DESTINATION ${ZHR_PRODUCT}/distr/lib/${OS_IDENT})

#-------------	TO REMOVE THIS BLOCK.
#include(../common.cmake)

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
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ZHR_DESTINATION}")
#-------------

set(HEADER_FILES
	zhrf_basis.h
#	zhrf_files.h  
#	zhrf_lib.h  
#	zhrf_strings.h  

#	zhrf_arg_parser.h
#	zhrf_conf_parser.h
#	zhrf_sockets.h  
) 

set(SOURCE_FILES
	zhrf_basis.cpp
#	zhrf_files.cpp  
#	zhrf_lib.cpp  
#	zhrf_strings.cpp  

#	zhrf_arg_parser.cpp
#	zhrf_conf_parser.cpp
#	zhrf_sockets.cpp  
)

#assign_source_group(${HEADER_FILES} ${SOURCE_FILES})

if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17" )
endif()

add_library ( ${PROJECT_NAME} STATIC 
	${HEADER_FILES}
	${SOURCE_FILES}
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_NAME lib_zhr )
else ()
	set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_NAME _zhr )
endif()
#set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${LIB_ZHR_DESTINATION}" )
