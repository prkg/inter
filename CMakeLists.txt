cmake_minimum_required(VERSION 3.10)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(inter)
file(GLOB_RECURSE SRC_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/common/*.c"
    "${PROJECT_SOURCE_DIR}/common/*.h"
)
include_directories(${CMAKE_SOURCE_DIR}/common)
include_directories(${CMAKE_SOURCE_DIR}/src)
file(GLOB COMMON_SOURCES "${PROJECT_SOURCE_DIR}/common/*.c")
add_executable(inter ${SRC_SOURCES})

enable_testing()
file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/*.c")
add_executable(tests ${TEST_SOURCES})
add_test(NAME tests COMMAND tests)
set_target_properties(tests PROPERTIES LINKER_LANGUAGE C)
