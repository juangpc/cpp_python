add_executable(test_adder main.cpp)
target_link_libraries(test_adder adder calls randomy)
target_link_options(test_adder PRIVATE --coverage)





