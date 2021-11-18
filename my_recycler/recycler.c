#include "recycler.h"

#include <stdlib.h>

struct recycler *recycler_create(size_t block_size, size_t total_size)
{
    if (!block_size || block_size % sizeof(size_t) != 0
        || block_size % total_size != 0)
        return NULL;

    struct recycler *r = malloc(sizeof(struct recycler));
    if (!r)
        return NULL;

    struct free_list *f = malloc(sizeof(struct free_list));
    if (!f)
        return NULL;

    f->next = NULL;

    r->block_size = block_size;
    r->chunk = malloc(sizeof(size_t) * total_size);
    if (!r->chunk)
        return NULL;
    r->free = free;
    r->capacity = total_size;

    return r;
}

void recycler_destroy(struct recycler *r)
{
    if (!r)
        return;

    struct free_list *f = r->free;
    struct free_list *tmp;

    while (r)
    {
        tmp = f;
        f = f->next;
        free(tmp);
    }

    r->capacity = 0;
    r->free = NULL;
}

void *recycler_allocate(struct recycler *r)
{
    if (!r || !r->free)
        return NULL;

    struct free_list *f = r->free;
    struct free_list *tmp = f;
    f = f->next;

    return tmp;
}

void recycler_free(struct recycler *r, void *block)
{
    if (!r | !block)
        return;

    struct free_list *f = r->free;

    struct free_list *new = block;
    new->next = f;
    r->free = new;
}
