#include <criterion/criterion.h>

#include "lca.h"

Test(list, short_tree)
{
    int *list = malloc(sizeof(int) * 4);
    cr_assert_eq(lca(list))
}
