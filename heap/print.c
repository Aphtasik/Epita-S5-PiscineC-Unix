#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

static char *my_itoa(int value, char *s)
{
    int s_i = 0;
    int reversedInt = 0;
    int remainder;

    if (value < 0)
    {
        value = -value;
        s[s_i] = '-';
        s_i++;
    }
    if (value == 0)
    {
        s[s_i++] = '0';
        s[s_i] = '\0';
        return s;
    }

    while (value != 0)
    {
        remainder = value % 10;
        reversedInt = reversedInt * 10 + remainder;
        value = value / 10;
    }

    while (reversedInt != 0)
    {
        remainder = reversedInt % 10;
        s[s_i] = remainder + '0';
        reversedInt = reversedInt / 10;
        s_i++;
    }
    s[s_i] = '\0';

    return s;
}

static int get_nb_char(int nb)
{
    int tt = 0;
    while (nb != 0)
    {
        tt += 1;
        nb /= 10;
    }
    return tt;
}

struct queue
{
    int data;
    struct queue *next;
};

struct queue *queue_push(struct queue *l, int elt)
{
    struct queue *new = malloc(sizeof(struct queue));
    if (!new)
    {
        return NULL;
    }
    new->data = elt;

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

struct queue *queue_pop(struct queue *l, int *elt)
{
    if (l)
    {
        struct queue *head = l;
        struct queue *prev = l;
        if (!l->next)
        {
            *elt = l->data;
            free(l);
            return NULL;
        }
        while (l->next)
        {
            prev = l;
            l = l->next;
        }
        prev->next = NULL;
        *elt = l->data;
        free(l);
        return head;
    }
    return NULL;
}

static void print_heap_rec(const struct heap *heap, size_t i, struct queue *q)
{
    if (i >= heap->size)
    {
        return;
    }
    else
    {
        q = queue_push(q, heap->array[i]);
        print_heap_rec(heap, 2 * i + 1, q);
        print_heap_rec(heap, 2 * i + 2, q);
    }
}

void print_heap(const struct heap *heap)
{
    if (heap && heap->array[0])
    {
        struct queue *q = NULL;
        int *elt = NULL;
        print_heap_rec(heap, 0, q);

        for (size_t i = 0; i < heap->size; i++)
        {
            q = queue_pop(q, elt);
            int nb_char = get_nb_char(*elt);
            char *s = malloc(sizeof(char) * nb_char);
            s = my_itoa(*elt, s);

            for (int j = 0; j < nb_char; j++)
            {
                putchar(s[j]);
                putchar(' ');
            }
            free(s);
        }
        free(q);
        putchar('\n');
    }
}
