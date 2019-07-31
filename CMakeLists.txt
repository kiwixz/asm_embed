cmake_minimum_required(VERSION 3.12)

project("embed" C CXX ASM_NASM)


function (embed_file name file)
    get_property(languages GLOBAL PROPERTY ENABLED_LANGUAGES)
    if (NOT "ASM_NASM" IN_LIST languages
        OR NOT "C" IN_LIST languages)  # also required by ASM_NASM to determine word size
        message(FATAL_ERROR "ASM_NASM or C not enabled")
    endif ()

    set(target embed_${name})

    add_library(${target} STATIC embed.asm)
    set_target_properties(${target} PROPERTIES LINKER_LANGUAGE C)
    target_compile_options(${target} PRIVATE "-DNAME=${name}" "-DFILE='${file}'")

    if (WIN32)
        target_compile_options(${target} PRIVATE "-Xvc")
    endif ()

    configure_file(embed.h "${CMAKE_BINARY_DIR}/${target}/include/embed/${name}.h" @ONLY)
    target_include_directories(${target} BEFORE INTERFACE "${CMAKE_BINARY_DIR}/${target}/include")
endfunction ()


add_executable(test_c test.c)
embed_file(cat test.c)
embed_file(dog test.cpp)
target_link_libraries(test_c embed_cat)

add_executable(test_cpp test.cpp)
target_link_libraries(test_cpp embed_cat embed_dog)
