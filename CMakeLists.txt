# CMake
# -----
cmake_minimum_required (VERSION 3.0)
# find_package (PkgConfig REQUIRED)


# Compiler settings
# -----------------
# Detect clang
execute_process (COMMAND ${CMAKE_CXX_COMPILER} -v
  ERROR_VARIABLE TR_COMPILER_VERBOSE
  OUTPUT_QUIET)
if ((TR_COMPILER_VERBOSE MATCHES "clang"))
  set (TR_COMPILER_IS_CLANG 1)
endif ()
# Extra flags for g++ and clang
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR TR_COMPILER_IS_CLANG)
  set (CMAKE_CXX_FLAGS "\
    -O0 \
    -Wall \
    -Wextra \
    -Winit-self \
    -Winit-self \
    -Wmissing-declarations \
    -Wno-long-long \
    -Wold-style-cast \
    -Woverloaded-virtual \
    -Wuninitialized \
    -g \
    -pedantic \
    ")
endif ()

set (NAME "TemplateRays")
file (GLOB_RECURSE SOURCES "src/*.cpp")
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
