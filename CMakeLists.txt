cmake_minimum_required(VERSION 3.12)

project("embed" CXX ASM)

set(CMAKE_ASM_COMPILER "yasm")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -f win64 -X vc")

add_library(embed STATIC embed.s)
set_target_properties(embed PROPERTIES LINKER_LANGUAGE CXX)
target_compile_definitions(embed PRIVATE "NAME=cat" "FILE='CMakeLists.txt'")

add_executable(embed_test test.cpp)
target_link_libraries(embed_test embed)
