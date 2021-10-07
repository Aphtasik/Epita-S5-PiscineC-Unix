#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int predicate(int e)
{
    return e % 2 == 0;
}

int main()
{
    struct list *test = NULL;
    test = list_add(test, 6);
    test = list_add(test, 5);
    test = list_add(test, 4);
    test = list_add(test, 2);


    test = list_remove_if(test, predicate);
    list_print(test);
    return 0;
}
