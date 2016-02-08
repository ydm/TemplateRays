# CMake
# -----
cmake_minimum_required (VERSION 3.0)
# find_package (PkgConfig REQUIRED)


# Compiler settings
# -----------------

# Precompiled header
set (TR_PRECOMPILED_HEADER "${CMAKE_SOURCE_DIR}/src/precompiled.hpp")

# Flags
set (TR_COMPILER_FLAGS "")

# Detect clang
execute_process (COMMAND ${CMAKE_CXX_COMPILER} -v
                 ERROR_VARIABLE TR_COMPILER_VERBOSE_OUTPUT
		 OUTPUT_QUIET)

if ((TR_COMPILER_VERBOSE_OUTPUT MATCHES "clang"))
  # For clang we use a special switch that includes the precompiled
  # header.  There's no other way for clang to use pch afaik.
  set (TR_COMPILER_FLAGS "${TR_COMPILER_FLAGS} -include ${TR_PRECOMPILED_HEADER}")
  set (TR_COMPILER_IS_CLANG 1)
endif ()

# Check if g++ or clang
if (CMAKE_COMPILER_IS_GNUCXX OR TR_COMPILER_IS_CLANG)
  # Precompile header
  set (ENV{CXX} ${CMAKE_CXX_COMPILER})
  execute_process (COMMAND "${CMAKE_SOURCE_DIR}/scripts/precompile-header.sh")

  # Set compiler flags
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
file (GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
set (INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/dependencies/include")


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
