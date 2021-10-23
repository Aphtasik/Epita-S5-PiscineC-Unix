#include "fifo.h"

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *f = malloc(sizeof(struct fifo));
    if (!f)
    {
        err(1, "Error on malloc");
    }
    f->head = NULL;
    f->tail = NULL;
    f->size = 0;

    return f;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
    {
        err(1, "Error on malloc");
    }
    new->data = elt;
    new->next = NULL;

    if (fifo->size == 0)
    {
        fifo->head = new;
        fifo->tail = new;
    }
    else
    {
        fifo->tail->next = new;
        fifo->tail = new;
    }
    fifo->size += 1;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo->size)
    {
        struct list *tmp = fifo->head;

        if (fifo->size > 1)
        {
            fifo->head = fifo->head->next;
        }
        else
        {
            fifo->head = NULL;
            fifo->tail = NULL;
        }

        fifo->size -= 1;
        free(tmp);
    }
}

void fifo_clear(struct fifo *fifo)
{
    struct list *tmp = NULL;

    while (fifo->size)
    {
        tmp = fifo->head;
        fifo->head = tmp->next;
        free(tmp);
        fifo->size -= 1;
    }
    fifo->tail = NULL;
    fifo->head = NULL;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    if (!fifo)
    {
        err(1, "fifo doesn't exist");
    }

    struct list *l = fifo->head;
    while (l)
    {
        printf("%d\n", l->data);
        l = l->next;
    }
}
