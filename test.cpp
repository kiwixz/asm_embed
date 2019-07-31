#include "embed/cat.h"
#include "embed/dog.h"
#include <cstdio>

int main() {
    printf("begin:%p end:%p size:%llu\n\n", embed::cat().begin(), embed::cat().end(), embed::details::embed_cat_size);
    for (auto it = embed::cat().begin(); it != embed::cat().end(); ++it)
        putchar(*it);

    printf("\n\nbegin:%p end:%p size:%llu\n\n", embed::dog().begin(), embed::dog().end(), embed::details::embed_dog_size);
    for (auto it = embed::dog().begin(); it != embed::dog().end(); ++it)
        putchar(*it);
}
