#include <stddef.h>
#include <stdio.h>

#include "list.h"

void list_print_rec(struct list *l)
{
    if (!l->next)
    {
        printf("%d\n", l->data);
        return;
    }
    printf("%d ", l->data);
    list_print_rec(l->next);
}

void list_print(struct list *l)
{
    if (!l)
    {
        printf("\n");
    }
    list_print_rec(l);
}
