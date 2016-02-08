#!/bin/bash

SCRIPTS_DIR=$(dirname "${BASH_SOURCE[0]}")
BASE_DIR=$(dirname "$SCRIPTS_DIR")

if [ -e $CXX ] ; then
    CXX=g++
fi

for suffix in gch pch ; do
    $CXX -I"$BASE_DIR"/dependencies/include             \
	 -O0                                            \
	 -Wall                                          \
	 -Wextra                                        \
	 -Winit-self                                    \
	 -Winit-self                                    \
	 -Wmissing-declarations                         \
	 -Wno-long-long                                 \
	 -Wold-style-cast                               \
	 -Woverloaded-virtual                           \
	 -Wuninitialized                                \
	 -g                                             \
	 -pedantic                                      \
	 -std=gnu++11                                   \
	 -o "$BASE_DIR"/src/precompiled.hpp.$suffix     \
	 "$BASE_DIR"/src/precompiled.hpp
done
