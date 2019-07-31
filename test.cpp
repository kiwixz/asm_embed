#include "embed/cat.h"
#include <cstdio>

int main() {
    printf("begin:%p end:%p size:%llu\n\n", embed::cat().begin(), embed::cat().end(), embed::details::embed_cat_size);
    for (auto it = embed::cat().begin(); it != embed::cat().end(); ++it)
        putchar(*it);
}
