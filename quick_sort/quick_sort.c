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

    for (int j = left; j < right; j++)
    {
        if (tab[j] < pivot)
        {
            i++;
            swap(&tab[i], &tab[j]);
        }
    }

    swap(&tab[i + 1], &tab[right]);
    return (i + 1);
}

void quicksortBorned(int *tab, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(tab, left, right);
        quicksortBorned(tab, left, pivot - 1);
        quicksortBorned(tab, left + 1, right);
    }
}

void quicksort(int *tab, int len)
{
    if (len > 1 && tab)
    {
        int left = 0;
        int right = len - 1;

        quicksortBorned(tab, left, right);
    }
}
