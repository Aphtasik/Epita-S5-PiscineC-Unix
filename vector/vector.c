#include "vector.h"

#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *new = malloc(sizeof(struct vector));
    if (!new)
    {
        errx(1, "malloc err");
    }

    new->size = 0;
    new->capacity = n;
    new->data = NULL;
    return new;
}

void vector_destroy(struct vector *v)
{
    free(v->data);
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (!v)
        return NULL;

    if (n == v->capacity || n < 1)
    {
        return v;
    }
    else if (n < v->size) //TODO: faire un bail en plus
    {
        v->data = realloc(v, sizeof(int) * n);
        if (!v->data)
            return NULL;
    }
    else
    {
        v->data = realloc(v, sizeof(int) * n);
        if (!v->data)
            return NULL;
    }
    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;

    if (v->size + 1 >= v->capacity)
    {
        v->data = realloc(v, sizeof(int) * v->capacity * 2);
        if (!v->data)
            return NULL;

        v->capacity *= 2;
    }
    v->data[v->size] = elt;
    v->size += 1;
    return v;
}

void vector_print(const struct vector *v)
{
    if (!v)
    {
        putchar('\n');
    }
    else
    {
        for (int i = 0; i < v->size - 1; i++)
        {
            printf("%d,", v->data[i]);
        }
        printf("%d\n", v->data[v->size - 1]);
    }
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    assert(0 && "not implemented");
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    assert(0 && "not implemented");
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    assert(0 && "not implemented");
}
