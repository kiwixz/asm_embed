#include <cstdio>

extern "C" {
    extern const char* cat_begin;
    extern const char* cat_end;
    extern const size_t cat_size;
}

int main() {
    printf("begin:%p end:%p size:%llu\n\n", cat_begin, cat_end, cat_size);
    for (const char* ptr = cat_begin; ptr < cat_end; ++ptr)
        putchar(*ptr);
}
