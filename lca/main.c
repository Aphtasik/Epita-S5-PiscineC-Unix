#include <stdio.h>
#include <stdlib.h>

#include "lca.h"

int main(void)
{
    int values[5] = { 0, 1, 4, 2, 3 };
    int lc = lca(values, 5, 2, 3);
    printf("%d\n", lc);
    return 0;
}
