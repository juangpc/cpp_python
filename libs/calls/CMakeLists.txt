add_library(calls STATIC calls.cpp)
target_include_directories(calls BEFORE PUBLIC ..)
set_target_properties(calls PROPERTIES LINKER_LANGUAGE CXX)

add_library(calls_d SHARED calls.cpp)
target_include_directories(calls_d PUBLIC ..)
set_target_properties(calls_d PROPERTIES LINKER_LANGUAGE CXX)
