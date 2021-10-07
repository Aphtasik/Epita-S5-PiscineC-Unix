#include "list.h"

#include <stdlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
    {
        return NULL;
    }
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
                return head;;
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
    if (l)
    {
        struct list *head = l;
        struct list *new = malloc(sizeof(struct list));
        if (!new)
        {
            return NULL;
        }
        new->data = e;

        if (e > l->data)
        {
            new->next = l;
            return new;
        }
        else
        {
            while (l->next && e < l->next->data)
            {
                l = l->next;
            }
            if (e >= l->next->data)
            {
                new->next = l->next->next;
                l->next = new;
                return head;
            }
            if (!l->next && e < l->data)
            {
                new->next = NULL;
                l->next = new;
                return head;
            }
        }
    }
    return NULL;
}

struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    if (l)
    {
        struct list *head = l;
        struct list *prev = l;
        struct list *tmp;
        while (predicate(head->data))
        {
            head = list_remove(head, head->data);
        }
        if (!head)
        {
            return NULL;
        }

        l = head;
        while (l)
        {
            if (predicate(l->data))
            {
                tmp = l;
                prev->next = l->next;
                l = l->next;
                free(tmp);
            }
            else
            {
                prev = l;
                l = l->next;
            }
        }
        return head;
    }
    return NULL;
}
