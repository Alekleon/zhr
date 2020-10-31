project (zhr)

cmake_minimum_required(VERSION 3.18)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# Enable running of test scripts using ctest
enable_testing()

# Setting output directories.
get_filename_component(ZHR_PRODUCT ${CMAKE_CURRENT_SOURCE_DIR}/../../ ABSOLUTE)
# MESSAGE ("\nCMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR}\n)
# MESSAGE ("\nZHR_PRODUCT: " ${ZHR_PRODUCT}\n)
set(ZHR_DESTINATION ${ZHR_PRODUCT}/distr)
set(OS_IDENT "${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ZHR_DESTINATION}/lib/${OS_IDENT}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ZHR_DESTINATION}/bin/${OS_IDENT}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ZHR_DESTINATION}/bin/${OS_IDENT}")

#if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
#	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )
#endif()

add_subdirectory(zhr_lib)

# Module tests
add_subdirectory(../../tests/module module_tests)
