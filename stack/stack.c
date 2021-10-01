#include "stack.h"

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *new = malloc(sizeof(struct stack));
    new->data = e;
    new->next = NULL;

    if (s == NULL)
    {
        return new;
    }

    while (s->next != NULL)
    {
        s = s->next;
    }
    s->next = new;
}
