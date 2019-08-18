#include "embed/cat.h"
#include <stdio.h>

int main() {
    printf("begin:%p end:%p size:%llu\n\n", test_embed_cat_begin, test_embed_cat_end, test_embed_cat_size);
    puts(test_embed_cat_begin);
}
