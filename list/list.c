#include "list.h"

#include <stdlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return l;

    new->data = e;
    new->next = l;
    return new;
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
    if (l)
    {
        struct list *head = l;
        struct list *prev = l;
        if (l->data == e)
        {
            head = l->next;
            free(l);
            return head;
        }
        else
        {
            while (l && l->data != e)
            {
                prev = l;
                l = l->next;
            }
            if (!l)
            {
                return head;
                ;
            }
            prev->next = l->next;
            free(l);
            return head;
        }
    }
    return NULL;
}

struct list *list_reverse_sorted_add(struct list *l, int e)
{
    struct list *head = l;
    struct list *new = malloc(sizeof(struct list));
    new->data = e;

    if (!l)
    {
        new->next = NULL;
        return new;
    }
    else
    {
        struct list *prev = l;
        if (e >= l->data)
        {
            new->next = l;
            return new;
        }
        l = l->next;

        while (l)
        {
            if (e >= l->data)
            {
                prev->next = new;
                new->next = l;
                return head;
            }
            prev = l;
            l = l->next;
        }
        prev->next = new;
        new->next = NULL;
        return head;
    }
}

struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    if (l)
    {
        struct list *cpy = l;
        while (cpy)
        {
            if (!cpy)
            {
                return NULL;
            }
            else if (predicate(cpy->data) == 1)
            {
                l = list_remove(l, cpy->data);
                cpy = l;
            }
            else
            {
                cpy = cpy->next;
            }
        }
    }
    return l;
}
