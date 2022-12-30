cmake_minimum_required(VERSION 3.21)
project(Cpp_Python)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_GENERATOR "Ninja")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../out/ )

set(CMAKE_BUILD_RPATH "lib/")

add_subdirectory(cpp_bindings)
add_subdirectory(lib)

# add_executable(main_app main.cpp)
# target_link_libraries(main_app PUBLIC liba)
#
# add_executable(main_app_shared main.cpp)
# target_link_libraries(main_app_shared PUBLIC liba_dyn)

