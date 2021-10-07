#include "variant.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;
    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;
    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;
    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
        break;
    }
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    enum type lt = left->type;
    enum type rt = right->type;

    if (lt == rt)
    {
        switch (lt)
        {
        case TYPE_INT:
            return left->value.int_v == right->value.int_v;
        case TYPE_FLOAT:
            return left->value.float_v == right->value.float_v;
        case TYPE_CHAR:
            return left->value.char_v == right->value.char_v;
        default:
            return strcmp(left->value.str_v, right->value.str_v) == 0;
        }
        return true;
    }
    return false;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    if (array)
    {
        for (size_t i = 0; i < len; i++)
        {
            if (array[i].type == type)
            {
                switch (array[i].type)
                {
                case TYPE_INT:
                    if (array[i].value.int_v == value.int_v)
                    {
                        return i;
                    }
                    break;
                case TYPE_FLOAT:
                    if (array[i].value.float_v == value.float_v)
                    {
                        return i;
                    }
                    break;
                case TYPE_CHAR:
                    if (array[i].value.char_v == value.char_v)
                    {
                        return i;
                    }
                    break;
                default:
                    if (!strcmp(array[i].value.str_v, value.str_v))
                    {
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float sum = 0;

    if (array && len > 0)
    {
        for (size_t i = 0; i < len; i++)
        {
            if (array[i].type == TYPE_INT)
            {
                sum += array[i].value.int_v;
            }
            else
            {
                sum += array[i].value.float_v;
            }
        }
    }
    return sum;
}
