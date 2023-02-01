add_executable(test_adder main.cpp)
target_link_libraries(test_adder adder)
target_compile_options(test_adder PRIVATE -ftest-coverage -fprofile-arcs)
target_link_options(test_adder PRIVATE --coverage)





