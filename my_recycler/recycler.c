#include "recylcler.h"

struct recycler *recycler_create(size_t block_size, size_t total_size)
{
    if (!block_size || block_size % sizeof(size_t) != 0
        || block_size % total_size != 0)
    {
        return NULL;
    }

    struct recycler *r = malloc(sizeof(struct recycler));
    if (!r)
    {
        return NULL;
    }

    struct free_list *f = malloc(sizeof(struct free_list));
    if (!f)
    {
        return NULL;
    }
    f->next = NULL;

    r->block_size = block_size;
    r->capacity = total
}
