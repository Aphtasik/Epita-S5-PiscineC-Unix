#include "list.h"

#include <stddef.h>
#include <stdio.h>

static void list_print_rec(struct list *l)
{
    if (!l)
    {
        return;
    }
    list_print(l);
}

void list_print(struct list *l)
{
    if (!l->next)
    {
       printf("%d\n", l->data);
       return;
    }
    printf("%d ", l->data);
    list_print(l->next);
}
