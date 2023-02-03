#!/bin/sh
#

rm -fr build
rm call
cmake -B build -S .
cmake --build build

./call hello say_hello1
echo " "
./call hello say_hello2
