#!/bin/bash

SCRIPTS_DIR="$(dirname "${BASH_SOURCE[0]}")"
BASE_DIR="$(dirname "$SCRIPTS_DIR")"
HEADER="$BASE_DIR"/src/precompiled.hpp

if [ -z $CXX ] ; then
    CXX=g++
fi

set -o verbose
rm -f "$HEADER".gch
rm -f "$HEADER".pch
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
     -o "$HEADER".gch                               \
     "$HEADER"
cp "$HEADER".gch "$HEADER".pch
