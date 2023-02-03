#!/bin/bash

PYTHON_VER_OUTPUT=$(python --version)
[[ $PYTHON_VER_OUTPUT =~ ^Python\ ([0-9]).([0-9]+).[0-9]* ]] &&
PYTHON_VERSION_MAJOR=${BASH_REMATCH[1]}
PYTHON_VERSION_MINOR=${BASH_REMATCH[2]}

echo PYTHON_VER_OUTPUT=$PYTHON_VER_OUTPUT
echo PYTHON_VERSION_MAJOR=$PYTHON_VERSION_MAJOR
echo PYTHON_VERSION_MINOR=$PYTHON_VERSION_MINOR


PYTHON_BIN_DIR=$(dirname $(which python))
PYTHON_INCLUDE_DIR=$(readlink -f $PYTHON_BIN_DIR/../include/.)
PYTHON_HEADER_DIR=$PYTHON_INCLUDE_DIR/python$PYTHON_VERSION_MAJOR.$PYTHON_VERSION_MINOR
PYTHON_LIB_DIR
echo PYTHON_BIN_DIR=$PYTHON_BIN_DIR
echo PYTHON_INCLUDE_DIR=$PYTHON_INCLUDE_DIR
echo PYTHON_HEADER_DIR=$PYTHON_HEADER_DIR

PYTHON_INCLUDES=$($PYTHON_BIN_DIR/python$PYTHON_VERSION_MAJOR.$PYTHON_VERSION_MINOR-config --includes)
PYTHON_FLAGS=$($PYTHON_BIN_DIR/python$PYTHON_VERSION_MAJOR.$PYTHON_VERSION_MINOR-config --cflags)
PYTHON_LIBS=$($PYTHON_BIN_DIR/python$PYTHON_VERSION_MAJOR.$PYTHON_VERSION_MINOR-config --ldflags)

echo PYTHON_FLAGS=$PYTHON_FLAGS
echo PYTHON_INCLUDES=$PYTHON_INCLUDES
echo PYTHON_LIBS=$PYTHON_LIBS


# build 
clang -c main.c -o out $PYTHON_FLAGS $PYTHON_INCLUDES $PYTHON_LIBS -Wl,-rpath,/opt/anaconda3/lib 
chmod +x out



# clang
# -Wno-unused-result
# -Wsign-compare
# -Wunreachable-code
# -DNDEBUG
# -fwrapv
# -O2
# -Wall
# -fPIC
# -O2
# -isystem
# /opt/anacona3/include
# -arch
# x86_64
# -I/opt/anaconda3/include
# -fPIC
# -O2
# -isystem
# /opt/anaconda3/include
# -arch
# x86_64
# -I../..
# -I/opt/anaconda3/include/python3.9
# -c
# randomy_python_bindings.cpp
# -o
# build/temp.macosx-10.9-x86_64-cpython-39/randomy_python_bindings.o



# clang++
# -bundle
# -undefined
# dynamic_lookup
# -Wl,-rpath,/opt/anaconda3/lib
# -L/opt/anaconda3/lib
# -L/opt/anaconda3/lib
# -Wl,-rpath,/opt/anaconda3/lib
# -L/opt/anaconda3/lib
# build/temp.macosx-10.9-x86_64-cpython-39/randomy_python_bindings.o
# librandomy_release.a
# -L.
# -o
# build/lib.macosx-10.9-x86_64-cpython-39/randomy.cpython-39-darwin.so
# -static

