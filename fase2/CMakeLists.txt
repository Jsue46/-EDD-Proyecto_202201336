cmake_minimum_required(VERSION 3.15)
project(MyProject)

# Include Conan
include(${CMAKE_BINARY_DIR}/conan.cmake)

# Create Conan target
conan_basic_setup()

# Add your executable
add_executable(my_executable main.cpp)

# Link libraries
target_link_libraries(my_executable ${CONAN_LIBS})
