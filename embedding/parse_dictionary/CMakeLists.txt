cmake_minimum_required(VERSION 3.2)

project(EXTENDED_EMBEDDED_PYTHON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Python COMPONENTS Interpreter Development)
cmake_path(GET Python_EXECUTABLE PARENT_PATH Python_BIN_DIR)

set(CONFIG_CMD_FLAGS "--cflags")
execute_process(COMMAND
  ${Python_BIN_DIR}/python${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}-config ${CONFIG_CMD_FLAGS}
  OUTPUT_VARIABLE Python_FLAGS
)

set(SOURCES
    main.cpp
)

set(HEADERS
)

set(CXX_STANDARD C++17)
add_executable(python_extension ${SOURCES})
target_link_libraries(python_extension
  PUBLIC python${Python_VERSION_MAJOR}.${Python_VERSION_MINOR})
target_link_directories(python_extension PUBLIC ${Python_LIBRARY_DIRS})
target_include_directories(python_extension PUBLIC ${Python_INCLUDE_DIRS})
set_target_properties(python_extension PROPERTIES
  OUTPUT_NAME "call"
  RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)
separate_arguments(Python_FLAGS_NORM UNIX_COMMAND "${Python_FLAGS}")
target_compile_options(python_extension PUBLIC ${Python_FLAGS_NORM} "-O3")

