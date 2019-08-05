#include "embed/cat.h"
#include <stdio.h>

int main() {
    printf("begin:%p end:%p size:%llu\n\n", embed_cat_begin, embed_cat_end, embed_cat_size);
    puts(embed_cat_begin);
}
