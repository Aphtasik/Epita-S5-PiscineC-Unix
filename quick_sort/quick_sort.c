void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sort(int *tab, int left, int right)
{
    int i;
    int j;
    int pivot;

    if (left < right)
    {
        pivot = left;
        i = left;
        j = right;

        while (i < j)
        {
            while (tab[i] <= tab[pivot] && i < right)
            {
                i++;
            }
            while (tab[j] > tab[pivot])
            {
                j--;
            }
            if (i < j)
            {
                swap(&tab[i], &tab[j]);
            }
        }

        swap(&tab[pivot], &tab[j]);
        sort(tab, left, j - 1);
        sort(tab, j + 1, right);
    }
}

void quicksort(int *tab, int len)
{
    if (len > 1 && tab)
    {
        int left = 0;
        int right = len - 1;

        sort(tab, left, right);
    }
}
