
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9")

add_library(adder STATIC adder.cpp)
target_include_directories(adder 
  PUBLIC .. 
  PUBLIC /opt/anaconda3/include/python3.9/
  )
set_target_properties(adder PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(adder PRIVATE -ftest-coverage -fprofile-arcs)
target_link_options(adder PRIVATE --coverage)

add_library(adder_release STATIC adder.cpp)
target_include_directories(adder_release
  PUBLIC .. 
  PUBLIC /opt/anaconda3/include/python3.9/
  )
set_target_properties(adder_release PROPERTIES LINKER_LANGUAGE CXX)

add_library(adder_d SHARED adder.cpp)
target_include_directories(adder_d BEFORE PUBLIC ..)
set_target_properties(adder_d PROPERTIES LINKER_LANGUAGE CXX)

# add_custom_command()

