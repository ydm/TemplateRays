# CMake
# -----
cmake_minimum_required (VERSION 3.0)
# find_package (PkgConfig REQUIRED)


# Compiler settings
# -----------------

# Precompiled header
set (TR_PRECOMPILED_HEADER "src/precompiled.hpp")

# Flags
set (TR_COMPILER_FLAGS "")

# Detect clang
execute_process (COMMAND ${CMAKE_CXX_COMPILER} -v
                 ERROR_VARIABLE TR_COMPILER_VERBOSE_OUTPUT
		 OUTPUT_QUIET)

if ((TR_COMPILER_VERBOSE_OUTPUT MATCHES "clang"))
  set (TR_COMPILER_FLAGS "${TR_COMPILER_FLAGS} -include ${TR_PRECOMPILED_HEADER}")
  set (TR_COMPILER_IS_CLANG 1)
endif ()

# g++ and clang flags
if (CMAKE_COMPILER_IS_GNUCXX OR TR_COMPILER_IS_CLANG)
  set (TR_COMPILER_FLAGS "${TR_COMPILER_FLAGS} \
    -O0                                        \
    -Wall                                      \
    -Wextra                                    \
    -Winit-self                                \
    -Winit-self                                \
    -Wmissing-declarations                     \
    -Wno-long-long                             \
    -Wold-style-cast                           \
    -Woverloaded-virtual                       \
    -Wuninitialized                            \
    -g                                         \
    -pedantic                                  \
    ")
endif ()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TR_COMPILER_FLAGS}")


# Project files
# -------------
file (GLOB_RECURSE SOURCES "src/*.cpp")
set (INCLUDE_DIRS "dependencies/include")


# Project
# -------
set (NAME "TemplateRays")
project (${NAME})
include_directories (${INCLUDE_DIRS})
add_executable (${NAME} ${SOURCES})


# Libraries
# ---------
# target_link_libraries (${NAME} m)


# C++ features
# ------------
target_compile_features (${NAME} PRIVATE cxx_auto_type)
target_compile_features (${NAME} PRIVATE cxx_lambdas)
target_compile_features (${NAME} PRIVATE cxx_nullptr)
target_compile_features (${NAME} PRIVATE cxx_override)
