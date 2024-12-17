cmake_minimum_required(VERSION 3.29)
project(Fluid2_0)

set(CMAKE_CXX_STANDARD 20)

set(types "\"FLOAT,FAST_FIXED(32,16),FIXED,DOUBLE\"")

add_compile_definitions(
        -DTYPES=${types}
)

add_executable(Fluid2_0 main.cpp)
