#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *tab, int left, int right)
{
    int i = left - 1;
    int pivot = tab[right];

    for(int j = left; j < right; j++)
    {
        if (tab[j] <= pivot)
        {
            i++;
            swap(&tab[i], &tab[j]);
        }
    }

    swap(&tab[i + 1], &tab[right]);
    return (i + 1);
}

void quicksort(int *tab, int len)
{
    int partition;
    int i;
    int j;
    int r_len;
    int l_len;
    int *r_array, *l_array;

    if (len != 1 && len != 0)
    {
        int left = tab;
        int right = tab + len;

        quicksortBorned(tab, left, right);
    }
}

int main()
{
    int tab[] = { 1, 3, 2, 4 };
    quicksort(tab, 4);
}
