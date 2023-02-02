cmake_minimum_required(VERSION 3.21)

project(Cpp_Python)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_GENERATOR "Ninja")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../out/ )

# set(CMAKE_C_COMPILER /usr/local/Cellar/llvm/15.0.7_1/bin/clang)
# set(CMAKE_CXX_COMPILER /usr/local/Cellar/llvm/15.0.7_1/bin/clang++)
 
add_subdirectory(libs)
# add_subdirectory(embedding)
# add_subdirectory(binding)

add_subdirectory(test)



