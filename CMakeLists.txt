# CMake
# -----
cmake_minimum_required (VERSION 3.0)
# find_package (PkgConfig REQUIRED)

# Compiler settings
# -----------------
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "\
    -O0 \
    -Wall \
    -Wextra \
    -Winit-self \
    -Winit-self \
    -Wmissing-declarations \
    -Wold-style-cast \
    -Woverloaded-virtual \
    -Wuninitialized \
    -g \
    ")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif ()

set (NAME "TemplateRays")
file(GLOB_RECURSE SOURCES "src/*.cpp")
set (INCLUDE_DIRS "dependencies/include")

# Project
# -------
project (${NAME})
include_directories (${INCLUDE_DIRS})
add_executable (${NAME} ${SOURCES})

# C++ features
# ------------
target_compile_features (${NAME} PRIVATE cxx_auto_type)
target_compile_features (${NAME} PRIVATE cxx_lambdas)
target_compile_features (${NAME} PRIVATE cxx_nullptr)
target_compile_features (${NAME} PRIVATE cxx_override)
