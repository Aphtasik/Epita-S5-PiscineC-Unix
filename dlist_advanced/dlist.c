#include "dlist.h"

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(A, B) ((A) < (B) ? (A) : (B))

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
    if (element < 0 || index > list->size)
        return -1;

    if (!list->head || index == 0)
        return dlist_push_front(list, element);

    else if (index == list->size)
        return dlist_push_back(list, element);

    size_t i = 0;
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (!new)
        return -1;

    new->data = element;
    new->next = NULL;
    new->prev = NULL;
    struct dlist_item *item = list->head;
    for (; item && index != i; i++, item = item->next)
        ;

    list->size += 1;
    new->prev = item->prev;
    new->next = item;
    item->prev->next = new;
    item->prev = new;

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
        list->tail = item;

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
    if (index == 0)
    {
        return dlist_init();
    }
    else if (!list->head || index > list->size)
    {
        return NULL;
    }
    else
    {
        struct dlist *d2 = malloc(sizeof(struct dlist));
        struct dlist_item *item = list->head;

        for (int i = index; item && i > 0; i--, item = item->next)
            ;

        d2->head = item;
        d2->tail = list->tail;
        list->tail = item->prev;
        d2->size = list->size - index;
        list->size = index;
        item->prev->next = NULL;
        item->prev = NULL;

        return d2;
    }
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
            list2->size -= 1;

            if (item->next)
            {
                item = item->next;
            }
            else
            {
                break;
            }
        }
    }
}

void dlist_clear(struct dlist *list)
{
    if (list->head)
    {
        list->size = 0;
        if (list->tail == list->head)
        {
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            return;
        }
        else
        {
            struct dlist_item *item = list->head;
            struct dlist_item *tmp = NULL;
            while (1)
            {
                if (item->next)
                {
                    tmp = item;
                    item = item->next;
                    free(tmp);
                }
                else
                {
                    free(item);
                    break;
                }
            }
        }
        list->head = NULL;
        list->tail = NULL;
    }
}

void dlist_shift(struct dlist *list, int offset)
{
    if (list->size > 1 && offset != 0)
    {
        if (offset > 0)
        {
            offset %= list->size;
            struct dlist_item *item;
            for (int i = 0; i < offset; i++)
            {
                item = list->tail;
                if (!dlist_push_front(list, item->data))
                    err(1, "shift: failed push front");

                item->prev->next = NULL;
                list->tail = item->prev;
                free(item);
                list->size -= 1;
            }
        }
        else
        {
            offset = -offset;
            offset %= list->size;
            struct dlist_item *item;
            for (int i = 0; i < offset; i++)
            {
                item = list->head;
                if (!dlist_push_back(list, item->data))
                    err(1, "shift: failed push back");

                item->next->prev = NULL;
                free(item);
                list->size -= 1;
            }
        }
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (list->head)
    {
        int i = 0;
        struct dlist_item *item = list->head;
        while (item && item->data > element)
        {
            i++;
        }
        if (dlist_insert_at(list, element, i) == -1)
        {
            return -1;
        }
    }
    else
    {
        if (dlist_push_front(list, element))
        {
            return -1;
        }
    }
    return 0;
}

int dlist_remove_eq(struct dlist *list, int element)
{
    int pos = dlist_find(list, element);
    if (dlist_remove_at(list, pos) == -1)
        return 0;

    return 1;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    struct dlist *dl_new = dlist_init();
    if (list->head)
    {
        struct dlist_item *item = list->head;
        for (; item; item = item->next)
        {
            if (!dlist_push_back(dl_new, item->data))
            {
                return NULL;
            }
        }
    }
    return dl_new;
}

void dlist_sort(struct dlist *list)
{
    int is_swap = 1;
    int tmp;
    struct dlist_item *item1 = NULL;
    struct dlist_item *item2 = NULL;

    if (!list)
    {
        return;
    }

    while (is_swap == 1)
    {
        is_swap = 0;
        item1 = list->head;

        while (item1->next != item2)
        {
            if (item1->data > item1->next->data)
            {
                tmp = item1->data;
                item1->data = item1->next->data;
                item1->next->data = tmp;
                is_swap = 1;
            }
            item1 = item1->next;
        }
        item2 = item1;
    }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    if (list2 && list2->head)
    {
        struct dlist_item *item = list2->head;
        for (; item; item = item->next)
        {
            if (!dlist_push_front(list1, item->data))
            {
                err(1, "merge: failed push front");
            }
        }
        dlist_sort(list1);
        dlist_clear(list2);
    }
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    size_t ld;
    size_t od;
    size_t len_s1 = list1->size;
    size_t len_s2 = list2->size;
    size_t i = 0;
    size_t j = 0;

    size_t *distance = malloc((len_s1 + 1) * sizeof(size_t));
    for (i = 0; i < len_s1 + 1; i++)
    {
        distance[i] = 0;
    }

    for (i = 1; i <= len_s1; i++)
    {
        distance[i] = i;
    }

    for (j = 1; j <= len_s2; j++)
    {
        distance[0] = j;
        ld = j - 1;
        for (i = 1, ld = j - 1; i <= len_s1; i++)
        {
            od = distance[i];
            size_t temp = MIN(distance[i] + 1, distance[i - 1] + 1);
            size_t is_eq =
                (dlist_get(list1, i - 1) == dlist_get(list2, j - 1)) ? 0 : 1;
            distance[i] = MIN(temp, ld + is_eq);
            ld = od;
        }
    }
    size_t res = distance[len_s1];
    free(distance);
    return res;
}

/** int main(void) */
/** { */
/**     int val; */
/**  */
/**     struct dlist *dl = dlist_init(); */
/**     struct dlist *dl_sec; */
/**  */
/**     val = dlist_push_front(dl, 2); */
/**     val = dlist_push_front(dl, 4); */
/**     val = dlist_push_front(dl, 5); */
/**  */
/**     val = dlist_insert_at(dl, 3, 2); */
/**  */
/**     printf("PRINT: (size: %ld)\n", dl->size); */
/**     dlist_print(dl); */
/**  */
/**     printf("GET: %d\n", dlist_get(dl, 1)); */
/**     printf("FIND: %d\n", dlist_get(dl, 3)); */
/**     printf("SIZE: %ld\n", dlist_size(dl)); */
/**  */
/**     val = dlist_remove_at(dl, 2); */
/**     printf("PRINT: (size: %ld)\n", dl->size); */
/**     dlist_print(dl); */
/**  */
/**     dlist_reverse(dl); */
/**     dlist_reverse(dl); */
/**     printf("PRINT: (size: %ld)\n", dl->size); */
/**     dlist_print(dl); */
/**  */
/**     dl_sec = dlist_split_at(dl, 2); */
/**     puts("PRINT DL1:"); */
/**     dlist_print(dl); */
/**     puts("PRINT DL2:"); */
/**     dlist_print(dl_sec); */
/**  */
/**     dlist_merge(dl, dl_sec); */
/**     printf("PRINT: (size: %ld)\n", dl->size); */
/**     dlist_print(dl); */
/**  */
/**     dlist_clear(dl_sec); */
/**     free(dl_sec); */
/**  */
/**     printf("PRINT: (size: %ld)\n", dl->size); */
/**     dlist_print(dl); */
/**  */
/**     val = dlist_remove_eq(dl, 5); */
/**  */
/**     printf("PRINT: (size: %ld)\n", dl->size); */
/**     dlist_print(dl); */
/**  */
/**  */
/**  */
/**     dlist_clear(dl); */
/**     free(dl); */
/**     val++; */
/**     return 0; */
/** } */
