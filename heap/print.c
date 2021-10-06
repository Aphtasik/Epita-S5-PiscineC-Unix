#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static char *my_itoa(int value, char *s)
{
    int s_i = 0;
    int reversedInt = 0;
    int remainder;


    if (value < 0)
    {
        value = - value;
        s[s_i] = '-';
        s_i++;
    }

    while (value != 0)
    {
        remainder = value % 10;
        reversedInt = reversedInt * 10 + remainder;
        value = value / 10;
    }

    while(reversedInt != 0)
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

static void print_int(const struct heap *heap, size_t i, int is_space)
{
    int nb_char = get_nb_char(heap->array[i]);
    char *s = malloc(sizeof(char) * nb_char);
    s = my_itoa(heap->array[i], s);

    for (int j = 0; j < nb_char; j++)
    {
        putchar(s[j]);
    }
    if (is_space == 1)
    {
        putchar(' ');
    }
    free(s);
}

static void print_heap_rec(const struct heap *heap, size_t i)
{
    if (i >= heap->size)
    {
        return;
    }
    else if (i == heap->size - 1)
    {
        print_int(heap, i, 0);
    }
    else
    {
        print_int(heap, i, 1); 
        print_heap_rec(heap, 2 * i + 1);
        print_heap_rec(heap, 2 * i + 2);
    }
}

void print_heap(const struct heap *heap)
{
    if (heap && heap->array[0])
    {
        print_heap_rec(heap, 0);
        putchar('\n');
    }
}
