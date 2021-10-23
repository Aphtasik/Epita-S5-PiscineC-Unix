#include "list.h"

#include <err.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
    {
        return NULL;
    }
    new->data = malloc(data_size);
    new->next = list;
    memcpy(new->data, value, data_size);

    return new;
}

size_t list_length(struct list *list)
{
    size_t i = 0;
    struct list *cpy = list;
    while (cpy)
    {
        i++;
        cpy = cpy->next;
    }
    return i;
}

void list_destroy(struct list *list)
{
    struct list *tmp = NULL;
    while (list)
    {
        tmp = list;
        list = list->next;
        free(tmp->data);
        free(tmp);
    }
}
