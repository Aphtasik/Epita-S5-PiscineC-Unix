#include "bst_static.h"

#include <assert.h>
#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *new = malloc(sizeof(struct bst));
    return new;
}

void add(struct bst *tree, int value)
{
    assert(0 && tree && value);
}

int search(struct bst *tree, int value)
{
    assert(0 && tree && value);
    return value;
}

void bst_free(struct bst *tree)
{
    assert(0 && tree);
}
