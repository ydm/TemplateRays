# CMake
# -----
cmake_minimum_required (VERSION 3.0)
# find_package (PkgConfig REQUIRED)


# Compiler settings
# -----------------

# Flags
set (TR_COMPILER_FLAGS "")

# Detect clang
execute_process (COMMAND ${CMAKE_CXX_COMPILER} -v
                 ERROR_VARIABLE TR_COMPILER_VERBOSE_OUTPUT
		 OUTPUT_QUIET)
if ((TR_COMPILER_VERBOSE_OUTPUT MATCHES "clang"))
  set (TR_COMPILER_IS_CLANG 1)
endif ()

# Extra flags for g++ and clang
if (CMAKE_COMPILER_IS_GNUCXX OR TR_COMPILER_IS_CLANG)
  # Precompile header
  set (ENV{CXX} ${CMAKE_CXX_COMPILER})
  execute_process (COMMAND "${CMAKE_SOURCE_DIR}/scripts/precompile-header.sh")
  add_definitions (-DTR_PRECOMPILED_HEADER)

  # TODO: -Wstrict-aliasing

  # -Werror                                           \
  # Set compiler flags (Sorry, I'm obsessed)
  set (TR_COMPILER_FLAGS "${TR_COMPILER_FLAGS}        \
    -include ${CMAKE_SOURCE_DIR}/src/precompiled.hpp  \
    -O0                                               \
    -g                                                \
    -Wall                                             \
    -Wextra                                           \
    -Wpedantic                                        \
    -Wno-unknown-warning-option                       \
    -Wdouble-promotion                                \
    -Wmissing-include-dirs                            \
    -Wswitch-default                                  \
    -Wswitch-enum                                     \
    -Wswitch-bool                                     \
    -Wsync-nand                                       \
    -Wunused-but-set-parameter                        \
    -Wunused-const-variable                           \
    -Wuninitialized                                   \
    -Wstrict-aliasing=3                               \
    -Wstrict-overflow=5                               \
    -Wsuggest-attribute=pure                          \
    -Wsuggest-attribute=const                         \
    -Wsuggest-attribute=noreturn                      \
    -Wsuggest-final-types                             \
    -Wsuggest-final-methods                           \
    -Wsuggest-override                                \
    -Wduplicated-cond                                 \
    -Wtrampolines                                     \
    -Wfloat-equal                                     \
    -Wundef                                           \
    -Wshadow                                          \
    -Wunsafe-loop-optimizations                       \
    -Wplacement-new=2                                 \
    -Wcast-qual                                       \
    -Wcast-align                                      \
    -Wconditionally-supported                         \
    -Wconversion                                      \
    -Wzero-as-null-pointer-constant                   \
    -Wdate-time                                       \
    -Wuseless-cast                                    \
    -Wsign-conversion                                 \
    -Wfloat-conversion                                \
    -Wsizeof-pointer-memaccess                        \
    -Wlogical-op                                      \
    -Waggregate-return                                \
    -Wmissing-declarations                            \
    -Wmissing-field-initializers                      \
    -Wopenmp-simd                                     \
    -Wpacked                                          \
    -Wpadded                                          \
    -Wredundant-decls                                 \
    -Winline                                          \
    -Winvalid-pch                                     \
    -Wlong-long                                       \
    -Wvariadic-macros                                 \
    -Wvarargs                                         \
    -Wvector-operation-performance                    \
    -Wdisabled-optimization                           \
    -Whsa                                             \
    -Wabi                                             \
    -Wabi-tag                                         \
    -Wctor-dtor-privacy                               \
    -Wnoexcept                                        \
    -Wstrict-null-sentinel                            \
    -Wold-style-cast                                  \
    -Woverloaded-virtual                              \
    -Wsign-promo                                      \
    -Wtemplates                                       \
    -Wmultiple-inheritance                            \
    -Wvirtual-inheritance                             \
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
