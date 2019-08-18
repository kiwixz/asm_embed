cmake_minimum_required(VERSION 3.12)
include(${CMAKE_SOURCE_DIR}/cmake/asm_embed.cmake)

project(test C CXX ASM_NASM)

add_executable(test_c test.c)
asm_embed(test cat ${CMAKE_SOURCE_DIR}/test.c)
asm_embed(test dog ${CMAKE_SOURCE_DIR}/test.cpp)
target_link_libraries(test_c ${cat_EMBED})

add_executable(test_cpp test.cpp)
target_link_libraries(test_cpp ${cat_EMBED} ${dog_EMBED})
