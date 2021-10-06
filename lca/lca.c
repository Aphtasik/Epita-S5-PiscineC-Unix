#include "lca.h"

#include <stddef.h>
#include <stdlib.h>

static int find_elt(int *values, int length, int x)
{
    for (int i = 0; i < length; i++)
    {
        if (values[i] == x)
        {
            return i;
        }
    }
    return -1;
}

static void build_list(int *values, int *arr,  int x_index)
{
    int arr_i = 1;
    arr[0] = values[x_index];

    while (x_index != 0)
    {
        if (x_index % 2 == 0)
        {
            arr[arr_i] = values[x_index / 2 - 1];
            x_index = x_index / 2 - 1;
        }
        else
        {
            arr[arr_i] = values[x_index / 2];
            x_index = x_index / 2;
        }
        arr_i++;
    }
}

int lca(int *values, int length, int p, int q)
{
    if (p == q)
    {
        return p;
    }

    int *plist = malloc(sizeof(int) * length);
    int *qlist = malloc(sizeof(int) * length);

    int pindex = find_elt(values, length, p);
    int qindex = find_elt(values, length, q);

    build_list(values, plist, pindex);
    build_list(values, qlist, qindex);
    
    int i = 0;
    while (plist[i] != qlist[i])
    {
        i++;
    }
    return plist[i];
}

