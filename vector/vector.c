#include "vector.h"

#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *new = malloc(sizeof(struct vector));
    if (!new)
        return NULL;

    new->size = 0;
    new->capacity = n;
    new->data = malloc(sizeof(int));
    if (!new->data)
    {
        free(new);
        return NULL;
    }
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
        return v;
    else if (n < v->size)
    {
        v->capacity = n; 
        v->data = realloc(v, sizeof(int) * n);
        if (!v->data)
            return NULL;
        v->size = n;
    }
    else
    {
        v->capacity = n; 
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
        printf("\n");
    else
    {
        for (size_t i = 0; i < v->size - 1; i++)
            printf("%d,", v->data[i]);

        printf("%d\n", v->data[v->size - 1]);
    }
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    v->size = 0;
    vector_resize(v, n);
    return v;
}

static void insertion(int **data_original, size_t len, size_t i, int elt)
{
    int *data = *data_original;
    int tmp = elt;
    for (; i < len; i++)
    {
        elt = tmp;
        tmp = data[i];
        data[i] = elt;
    }
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v || (v->size < i))
        return NULL;

    if (v->size + 1 >= v->capacity)
    {
        v->data = realloc(v, sizeof(int) * v->capacity * 2);
        if (!v->data)
            return NULL;

        v->capacity *= 2;
    }

    if (i == v->size)
        vector_append(v, elt);
    else
    {
        v->size += 1;
        insertion(&v->data, v->size, i, elt);
    }
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    v->size++;
    i++;
    return v;
}

int main(void)
{
    struct vector *v = vector_init(2);
    v = vector_append(v, 1);
    v = vector_append(v, 2);
    vector_print(v);

    return 0;
}
