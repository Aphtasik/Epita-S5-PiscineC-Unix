#include <stdlib.h>

typedef int (*f_cmp)(const void *, const void *);

void insertion_sort(void **array, f_cmp comp)
{
    if (!array || !array[0] || !array[1])
        return;

    int i;
    int j;
    void *key;

    for (i = 1; array[i]; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && (comp(array[j], key) == 1))
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
