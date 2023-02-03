#!/bin/bash

PYTHON_VER_OUTPUT=$(python --version)
[[ $PYTHON_VER_OUTPUT =~ ^Python\ ([0-9]).([0-9]+).[0-9]* ]] &&
PYTHON_VERSION_MAJOR=${BASH_REMATCH[1]}
PYTHON_VERSION_MINOR=${BASH_REMATCH[2]}

echo PYTHON_VER_OUTPUT=$PYTHON_VER_OUTPUT
echo PYTHON_VERSION_MAJOR=$PYTHON_VERSION_MAJOR
echo PYTHON_VERSION_MINOR=$PYTHON_VERSION_MINOR


PYTHON_BASE_DIR=$(readlink -f $(dirname $(which python))/..)
PYTHON_BIN_DIR=$(readlink -f $PYTHON_BASE_DIR/bin)
PYTHON_INCLUDE_DIR=$(readlink -f $PYTHON_BASE_DIR/include/python$PYTHON_VERSION_MAJOR.$PYTHON_VERSION_MINOR)
PYTHON_LIB_DIR=$(readlink -f $PYTHON_BASE_DIR/lib)

echo PYTHON_BASE_DIR=$PYTHON_BASE_DIR
echo PYTHON_BIN_DIR=$PYTHON_BIN_DIR
echo PYTHON_INCLUDE_DIR=$PYTHON_INCLUDE_DIR
echo PYTHON_LIB_DIR=$PYTHON_LIB_DIR

PYTHON_INCLUDES=$($PYTHON_BIN_DIR/python$PYTHON_VERSION_MAJOR.$PYTHON_VERSION_MINOR-config --includes)
PYTHON_FLAGS=$($PYTHON_BIN_DIR/python$PYTHON_VERSION_MAJOR.$PYTHON_VERSION_MINOR-config --cflags)
PYTHON_LIBS=$($PYTHON_BIN_DIR/python$PYTHON_VERSION_MAJOR.$PYTHON_VERSION_MINOR-config --ldflags)

echo PYTHON_FLAGS=$PYTHON_FLAGS
echo PYTHON_INCLUDES=$PYTHON_INCLUDES
echo PYTHON_LIBS=$PYTHON_LIBS


# build 
# clang -c main.c -o out $PYTHON_FLAGS $PYTHON_INCLUDES $PYTHON_LIBS -lpython3.9 -Wl,-rpath,/opt/anaconda3/lib 
# /usr/local/Cellar/llvm/15.0.7_1/bin/clang -c main.c -o out $PYTHON_FLAGS $PYTHON_INCLUDES $PYTHON_LIBS -lpython3.9 -Wl,-rpath,/opt/anaconda3/lib 

# /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc \
# -I/usr/local/opt/python@3.11/Frameworks/Python.framework/Versions/3.11/include/python3.11  \
# -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk \
# -I/usr/local/opt/python@3.11/Frameworks/Python.framework/Versions/3.11/include/python3.11 \
# -Wsign-compare \
# -Wunreachable-code \
# -fno-common \
# -dynamic \
# -DNDEBUG \
# -g \
# -fwrapv \
# -O3 \
# -Wall \
# -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk \
# -o out2 \
# -c main.c
#
# chmod +x out2

rm -f call
rm -fr build
mkdir -p build/CMakeFiles/python_extension.dir
cd build

A WORKING EXAMPLE
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc \
-I/opt/anaconda3/include/python3.9/ \
-Wunreachable-code \
-fno-common \
-dynamic \
-DNDEBUG \
-g \
-fwrapv \
-O3 \
-Wall \
-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk \
-o CMakeFiles/python_extension.dir/main.c.o \
-c ../main.c

/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc \
-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk \
-Wl,-search_paths_first \
-Wl,-headerpad_max_install_names \
-L/opt/anaconda3/lib \
-Wl,-rpath,/opt/anaconda3/lib \
-lpython3.9 \
CMakeFiles/python_extension.dir/main.c.o \
-o /Users/j/projects/cpp_python/src/embedding/high_level/call 

../call


# #working example
# /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc \
# -I/usr/local/opt/python@3.11/Frameworks/Python.framework/Versions/3.11/include/python3.11 \
# -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk \
# -I/usr/local/opt/python@3.11/Frameworks/Python.framework/Versions/3.11/include/python3.11 \
# -Wsign-compare \
# -Wunreachable-code \
# -fno-common \
# -dynamic \
# -DNDEBUG \
# -g \
# -fwrapv \
# -O3 \
# -Wall \
# -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX12.sdk \
# -MD \
# -MT CMakeFiles/python_extension.dir/main.c.o \
# -MF CMakeFiles/python_extension.dir/main.c.o.d \
# -o CMakeFiles/python_extension.dir/main.c.o \
# -c /Users/j/projects/cpp_python/src/embedding/high_level/main.c
#
# /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc \
# -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk \
# -Wl,-search_paths_first \
# -Wl,-headerpad_max_install_names \
# CMakeFiles/python_extension.dir/main.c.o \
# -o /Users/j/projects/cpp_python/src/embedding/high_level/call \
# -L/usr/local/opt/python@3.11/Frameworks/Python.framework/Versions/3.11/lib \
# -Wl,-rpath,/usr/local/opt/python@3.11/Frameworks/Python.framework/Versions/3.11/lib \
# -lpython3.11


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

