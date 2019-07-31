#include "embed/cat.h"
#include <stdio.h>

int main() {
    printf("begin:%p end:%p size:%llu\n\n", embed_cat_begin, embed_cat_end, embed_cat_size);
    for (const unsigned char* it = embed_cat_begin; it != embed_cat_end; ++it)
        putchar(*it);
}
