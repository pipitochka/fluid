cmake_minimum_required(VERSION 3.29)
project(Fluid2_0)

set(CMAKE_CXX_STANDARD 20)

set(types "FLOAT, FAST_FIXED(31, 10), FIXED(32,16),DOUBLE")

set(sizes "S(36,84)")

set(fast "1")

add_compile_definitions(
        TYPES="${types}"
        SIZES="${sizes}"
        FAST="${fast}"
)
add_executable(generator generator.cpp)

add_custom_command(
        TARGET generator POST_BUILD  # Построить после того, как generator был собран
        COMMAND ./generator         # Запускаем исполняемый файл 1
        COMMENT "Running generator"
)

add_executable(Fluid2_0 main.cpp)

add_dependencies(Fluid2_0 generator)
