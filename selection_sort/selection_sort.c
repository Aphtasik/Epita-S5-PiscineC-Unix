#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int min = arr[start];
    unsigned min_i = start;
    for(int i = start; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_i = i;
        }
    }
    return min_i;
}

void selection_sort(int arr[], unsigned size)
{
    int i;
    int min;

    for(i = 0; i < size - 1; i++)
    {
        min = array_min(arr, i + 1, size);
        printf("%d\n", min);
        swap(&arr[i], &arr[min]);
    }
}

int main(void)
{
    const unsigned size = 6;
    int arr[] = { 3, 4, 1, 2, 6, 5 };
    unsigned expected[] = { 1, 2, 3, 4, 5, 6};
    selection_sort(arr, size);
    for (unsigned i = 0; i < size; ++i)
        printf("%u: %d = %d\n", i, arr[i], expected[i]);
}
