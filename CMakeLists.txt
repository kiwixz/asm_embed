cmake_minimum_required(VERSION 3.12)

project("embed")


#
enable_language(ASM)
set(CMAKE_ASM_COMPILER "yasm")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -f win64 -X vc")

set(NAME "cat")
set(FILE "CMakeLists.txt")

add_library(embed STATIC embed.s)
set_target_properties(embed PROPERTIES LINKER_LANGUAGE CXX)
target_compile_definitions(embed PRIVATE "NAME=${NAME}" "FILE='${FILE}'")

configure_file(embed.h "${CMAKE_CURRENT_BINARY_DIR}/include/embed/${NAME}.h" @ONLY)
target_include_directories(embed BEFORE INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include")
#


add_executable(embed_test test.cpp)
target_link_libraries(embed_test embed)
