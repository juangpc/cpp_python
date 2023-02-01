add_library(adder STATIC adder.cpp)
target_include_directories(adder PUBLIC ..)
set_target_properties(adder PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(adder PRIVATE -ftest-coverage -fprofile-arcs)
target_link_options(adder PRIVATE --coverage)

add_library(adder_d SHARED adder.cpp)
target_include_directories(adder_d BEFORE PUBLIC ..)
set_target_properties(adder_d PROPERTIES LINKER_LANGUAGE CXX)
