#include "list.h"

#include <stddlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *new = malloc(sizeof(struct list));
    new->data = e;

    if (!l) 
    {
        new->next = NULL;
        return new;
    }
    else
    {
        new->next = l;
        return new;
    }
}

struct list *list_find(struct list *l, int e)
{
    while (l && l->data != e)
    {
        l = l->next;
    }

    if (l && l->data == e)
    {
        return l;
    }

    return NULL;
}

struct list *list_remove(struct list *l, int e)
{
    for (; l->next; l = l->next)
    {
        if (l->data)
        {
            struct list tmp = l->next;
            l->next = l->next->next;
            free(tmp);
        }
    }
    return NULL;
}


