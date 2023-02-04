#!/bin/sh
#

SCRIPT_PATH="$0"
ROOT_FOLDER=""
ROOT_FOLDER="$(cd -- "$(dirname $SCRIPT_PATH)" && pwd)"

BUILD_FOLDER=$ROOT_FOLDER/build
SRC_FOLDER=$ROOT_FOLDER

echo ""
echo BUILD_FOLDER=$BUILD_FOLDER

function deleteBuildFolder() {
  rm -fr $BUILD_FOLDER
  rm call
}

if [[ $1 == "clean"  ]]; then
  deleteBuildFolder
  cmake -B build -S .
fi

cmake --build build

# call application
echo ""
echo "Executing:"
echo "----------"

./call hello say_hello1
./call hello say_hello2
