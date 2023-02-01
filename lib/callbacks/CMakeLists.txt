
add_library(calls STATIC calls.cpp)
target_include_directories(calls PUBLIC .)
set_target_properties(calls PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(callsd PROPERTIES LINKER_LANGUAGE CXX)
add_library(callsd SHARED calls.cpp)
target_include_directories(callsd PUBLIC .)

