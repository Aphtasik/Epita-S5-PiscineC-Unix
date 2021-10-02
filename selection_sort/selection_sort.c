void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned min_i = start;
    for (unsigned i = start; i < size; i++)
    {
        if (arr[i] < arr[min_i])
        {
            min_i = i;
        }
    }
    return min_i;
}

void selection_sort(int arr[], unsigned size)
{
    if (size > 1)
    {
        unsigned i;
        unsigned min;

        for (i = 0; i < size - 1; i++)
        {
            min = array_min(arr, i, size);
            swap(&arr[i], &arr[min]);
        }
    }
}
