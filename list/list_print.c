#include "list.h"

#include <stddef.h>
#include <stdio.h>

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
        return;
    }
    list_print_rec(l);
}

