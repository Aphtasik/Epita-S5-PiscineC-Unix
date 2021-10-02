#include "bsearch.h"

#include <stddef.h>

int *binary_search(int *begin, int *end, int elt)
{
    int *mid = NULL;
    while (begin <= end)
    {
        mid = begin + (end - begin) / 2;

        if (*mid == elt)
        {
            return mid;
        }
        else if (*mid < elt)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return mid;
}
