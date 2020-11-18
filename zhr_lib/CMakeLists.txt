cmake_minimum_required(VERSION 3.5)

project(zhr_lib)

# set(CMAKE_CONFIGURATION_TYPES Debug Release)

if (NOT OUTPUT_DIR)
	set(OS_PLATFORM "${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")
	set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/Distrib/${OS_PLATFORM}/${CMAKE_BUILD_TYPE}")
endif()

MESSAGE ("LIB_OUTPUT_DIR: " ${OUTPUT_DIR}\n)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}/bin")

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
