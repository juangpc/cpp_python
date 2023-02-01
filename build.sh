#!/bin/bash

SCRIPT_PATH="$0"
ROOT_FOLDER=""
ROOT_FOLDER="$(cd -- "$(dirname $SCRIPT_PATH)/.." && pwd)"

BUILD_FOLDER=$ROOT_FOLDER/build
SRC_FOLDER=$ROOT_FOLDER/src
OUT_FOLDER=$ROOT_FOLDER/out

echo SCRIPT_PATH=$SCRIPT_PATH
echo ROOT_FOLDER=$ROOT_FOLDER
echo BUILD_FOLDER=$BUILD_FOLDER
echo SRC_FOLDER=$SRC_FOLDER
echo OUT_FOLDER=$OUT_FOLDER


export PATH="/usr/local/Cellar/llvm/15.0.6/bin/:/usr/local/Cellar/llvm/15.0.6/lib/:$PATH"


function deleteBuildFolder() {
    rm -fr $BUILD_FOLDER
    rm -fr $OUT_FOLDER
}

function runTestAdder() {
    $OUT_FOLDER/test_adder
    /usr/local/Cellar/llvm/15.0.6/bin/llvm-cov report -instr-profile=$BUILD_FOLDER/libs/adder/CMakeFiles/adder.dir/adder.cpp.gcno

    #gcov -f --demangled-names $BUILD_FOLDER/libs/adder/CMakeFiles/adder.dir/adder.cpp.gcno
}




if [[ $1 == "clean"  ]]; then
    deleteBuildFolder
fi

#delete folders

cmake -S $SRC_FOLDER -B $BUILD_FOLDER

cmake --build $BUILD_FOLDER
cp $BUILD_FOLDER/compile_commands.json $SRC_FOLDER

runTestAdder


# cp $BUILD_FOLDER/main_app/main_app $SRC_FOLDER

#call application
# ./main_app

# python src/python/callbacks.py
#
#once you have the binary you can check the libraries it is linked to by saying
#otool -L binFile
#otool -l binFile also shows the rpath at the end...
#
#
