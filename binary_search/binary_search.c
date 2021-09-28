#include <stddef.h>

int binary_search(const int vec[], size_t size, int elt) 
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) 
    {
        mid = left + (right - left) / 2;

        if (vec[mid] == elt) 
        {
            return mid;
        } else if (vec[mid] < elt) 
        {
            left = mid + 1;
        } else 
        {
            right = mid - 1;
        }
    }
    return -1;
}


