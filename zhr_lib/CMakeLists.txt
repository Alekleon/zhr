cmake_minimum_required(VERSION 3.5)

set(ZHR_LIB_PROJECT zhr_lib)
project (${ZHR_LIB_PROJECT})

include (vs-group.cmake)

# set(CMAKE_CONFIGURATION_TYPES Debug Release)

if (NOT OUTPUT_DIR)
	set(OS_PLATFORM "${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")
	set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/Distrib/${OS_PLATFORM}/${CMAKE_BUILD_TYPE}")
endif()

# MESSAGE ("LIB_OUTPUT_DIR: " ${OUTPUT_DIR}\n)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/bin")

set(ZHR_LIB_HEADER_FILES
	Includes/zhrf_basis.h
	Includes/zhrf_system.h
	Includes/zhrf_lib.h
) 

set(ZHR_LIB_SOURCE_FILES
	Sources/zhrf_basis.cpp
	Sources/zhrf_system.cpp
	Sources/zhrf_lib.cpp	
)

Add_VS_Groups (${ZHR_LIB_HEADER_FILES} ${ZHR_LIB_SOURCE_FILES})

if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17" )
#else()
#	assign_source_group(${ZHR_LIB_HEADER_FILES} ${ZHR_LIB_SOURCE_FILES})
endif()

add_library ( ${PROJECT_NAME} STATIC 
	${ZHR_LIB_HEADER_FILES}
	${ZHR_LIB_SOURCE_FILES}
)

target_include_directories( ${PROJECT_NAME} PUBLIC
	./Includes
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_NAME lib_zhr )
else ()
	set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_NAME _zhr )
endif()
#set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${LIB_ZHR_DESTINATION}" )
