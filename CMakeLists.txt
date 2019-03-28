cmake_minimum_required(VERSION 3.5.1)
project(simpleconststring)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic-errors")

set(APP_NAME "simple_const_string")

###Sources
set(SRC_DIRS
    "."
    )

set(SRC "")
foreach(_src_dir ${SRC_DIRS})
    file(GLOB
        _files
        "${_src_dir}/*.h"
        "${_src_dir}/*.hpp"
        "${_src_dir}/*.cpp"
    )
    list(APPEND SRC ${_files})
endforeach()

add_executable(${APP_NAME} ${SRC})
