cmake_minimum_required(VERSION 2.8)
project(CH9)
include_directories(include)
add_executable(ch9 
                src/ch9.cpp
                src/custom_ch9.cpp
                src/do_custom_ch9.cpp)
# set(CMAKE_BUILD_TYPE Debug)
# set_target_properties(your_target PROPERTIES COMPILE_FLAGS "-g")
