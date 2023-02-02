add_library(calls STATIC calls.cpp)
target_include_directories(calls BEFORE PUBLIC ..)
set_target_properties(calls PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(calls PRIVATE -ftest-coverage -fprofile-arcs)
target_link_options(calls PRIVATE --coverage)

add_library(calls_release STATIC calls.cpp)
target_include_directories(calls_release BEFORE PUBLIC ..)
set_target_properties(calls_release PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(calls_release PRIVATE -mmacosx-version-min=10.9)

add_library(calls_d SHARED calls.cpp)
target_include_directories(calls_d PUBLIC ..)
set_target_properties(calls_d PROPERTIES LINKER_LANGUAGE CXX)
