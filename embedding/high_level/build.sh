#!/bin/bash

PYTHON_VER_OUTPUT=$(python --version)
[[ $PYTHON_VER_OUTPUT =~ ^Python\ ([0-9]).([0-9]+).[0-9]* ]] &&
PYTHON_VERSION_MAYOR=${BASH_REMATCH[1]}
PYTHON_VERSION_MINOR=${BASH_REMATCH[2]}

echo PYTHON_VER_OUTPUT=$PYTHON_VER_OUTPUT
echo PYTHON_VERSION_MAYOR=$PYTHON_VERSION_MAYOR
echo PYTHON_VERSION_MINOR=$PYTHON_VERSION_MINOR


PYTHON_BIN_DIR=$(dirname $(which python))
PYTHON_INCLUDE_DIR=$(readlink -f $PYTHON_BIN_DIR/../include/.)
PYTHON_HEADER_DIR=$PYTHON_INCLUDE_DIR/python$PYTHON_VERSION_MAYOR.$PYTHON_VERSION_MINOR
echo PYTHON_BIN_DIR=$PYTHON_BIN_DIR
echo PYTHON_INCLUDE_DIR=$PYTHON_INCLUDE_DIR
echo PYTHON_HEADER_DIR=$PYTHON_HEADER_DIR








# clang main.c -o py_highlevel -I/usr/local/


