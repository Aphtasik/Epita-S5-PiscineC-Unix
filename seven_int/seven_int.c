#include "seven_int.h"

#include <fcntl.h>
#include <unistd.h>

int dump_ints(int *arr, const char *path)
{
    int fd = open(path, 'w');
    for (int i = 0; i < 7; i++)
    {
        int size = sizeof(arr[i]);

        write(fd, arr, size);
    }
    close(fd);
    return 1;
}

int read_ints(int *arr, const char *path)
{
    int fd = open(path, 'w');
    for (int i = 0; i < 7; i++)
    {
        int size = sizeof(arr[i]);

        write(fd, arr, size);
    }
    close(fd);
    return 1;
}
