#include "dlist.h"

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

struct dlist *dlist_init(void)
{
    struct dlist *dl = malloc(sizeof(struct dlist));
    if (!dl)
        return NULL;

    dl->size = 0;
    dl->tail = NULL;
    dl->head = NULL;

    return dl;
}

int dlist_push_front(struct dlist *list, int element)
{
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return 0;

    list->size += 1;
    new->data = element;
    new->prev = NULL;
    new->next = list->head;

    if (list->head)
        list->head->prev = new;
    else
        list->tail = new;

    list->head = new;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    if (list->head)
    {
        struct dlist_item *item = list->head;
        for (; item; item = item->next)
        {
            printf("%d\n", item->data);
        }
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return 0;

    list->size += 1;
    new->data = element;
    new->next = NULL;

    if (!list->head)
    {
        new->prev = NULL;
        list->head = new;
        list->tail = new;
        return 1;
    }

    list->tail->next = new;
    new->prev = list->tail;
    list->tail = new;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    size_t size = 0;
    if (list->head)
    {
        struct dlist_item *item = list->head;
        for (; item; item = item->next)
        {
            size++;
        }
    }
    return size;
}

int dlist_get(struct dlist *list, size_t index)
{
    size_t i = 0;
    if (list->head)
    {
        struct dlist_item *item = list->head;
        for (; item && index != i; item = item->next)
        {
            i++;
        }
        return (i == index && item) ? item->data : -1;
    }
    return -1;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    size_t i = 0;
    if (list->head)
    {
        struct dlist_item *new = malloc(sizeof(struct dlist_item));
        if (!new)
        {
            return -1;
        }
        new->data = element;
        new->next = NULL;
        new->prev = NULL;

        struct dlist_item *item = list->head;
        for (; item && index != i; item = item->next)
        {
            i++;
        }
        if (!item || i != index)
        {
            return -1;
        }

        list->size += 1;
        if (item->prev)
        {
            new->prev = item->prev;
            item->prev->next = new;
        }
        else
        {
            new->prev = NULL;
            list->head = new;
        }

        new->next = item;
        item->prev = new;
        // TODO: gerer si dernier elt
    }
    else
    {
        dlist_push_front(list, element);
    }
    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    int is_found = 0;
    int index = 0;
    if (list->head)
    {
        struct dlist_item *item = list->head;
        for (; item && !is_found; item = item->next)
        {
            if (item->data == element)
            {
                return index;
            }
            index++;
        }
    }
    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    size_t i = 0;
    if (list->head)
    {
        list->size -= 1;
        int elt;
        struct dlist_item *item = list->head;
        for (; item && index != i; item = item->next)
        {
            i++;
        }
        if (!item || i != index)
        {
            return -1;
        }

        if (item->prev && item->next)
        {
            item->prev->next = item->next;
            item->next->prev = item->prev;
        }
        else if (item->prev && !item->next)
        {
            list->tail = item->prev;
            item->prev->next = NULL;
        }
        else if (!item->prev && item->next)
        {
            list->head = item->next;
            item->next->prev = NULL;
        }
        else
        {
            list->head = NULL;
            list->tail = NULL;
        }
        elt = item->data;
        free(item);
        return elt;
    }
    return -1;
}

void dlist_map_square(struct dlist *list)
{
    if (list->head)
    {
        struct dlist_item *item = list->head;
        for (; item; item = item->next)
        {
            item->data *= item->data;
        }
    }
}

void dlist_reverse(struct dlist *list)
{
    if (list->head)
    {
        struct dlist_item *item = list->head;
        struct dlist_item *tmp;
        while (item)
        {
            tmp = item->prev;
            item->prev = item->next;
            item->next = tmp;
            item = item->prev;
        }

        if (tmp)
        {
            list->head = tmp->prev;
        }
    }
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (list->head && index != 0)
    {
        struct dlist_item *item = list->head;
        for (; item && index != 0; item = item->next)
        {
            index--;
        }
        if (!index)
        {
            struct dlist *dl_sec = dlist_init();
            struct dlist_item *tmp;
            list->tail = item->prev;
            while (item)
            {
                if (dlist_push_front(dl_sec, item->data) == 0)
                {
                    return NULL;
                }

                if (item->next)
                {
                    item->prev->next = item->next;
                    item->next->prev = item->prev;
                }
                else
                {
                    item->prev->next = NULL;
                }
                tmp = item;
                item = item->next;
                free(tmp);
                list->size -= 1;
            }
            return dl_sec;
        }
    }
    return NULL;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list2->head)
    {
        struct dlist_item *item = list2->head;
        while (1)
        {
            if (!dlist_push_back(list1, item->data))
                errx(1, "dlsit_concat: Failed Push back");

            if (item->next)
            {
                item = item->next;
                free(item->prev);
            }
            else
            {
                free(item);
                break;
            }
        }
        list1->size = list1->size + list2->size;
    }
}
