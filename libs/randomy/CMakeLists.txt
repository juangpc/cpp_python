add_library(randomy STATIC randomy.cpp)
target_include_directories(randomy PUBLIC ..)
set_target_properties(randomy PROPERTIES LINKER_LANGUAGE CXX)

add_library(randomy_d SHARED randomy.cpp)
target_include_directories(randomy_d BEFORE PUBLIC ..)
set_target_properties(randomy_d PROPERTIES LINKER_LANGUAGE CXX)

