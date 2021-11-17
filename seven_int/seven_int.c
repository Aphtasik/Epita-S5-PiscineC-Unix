#include "seven_int.h"

#include <fcntl.h>
#include <unistd.h>

int dump_ints(int *arr, const char *path)
{
    int fd = open(path, 'w');
    for (int i = 0; i < 7 * 4; arr += sizeof(char))
    {
        write(fd, arr, sizeof(char));
    }
    close(fd);
    return 1;
}

int read_ints(int *arr, const char *path)
{
    int fd = open(path, 'r');
    for (int i = 0; i < 7 * 4; arr += sizeof(char))
    {
        write(fd, arr, sizeof(char));
    }
    close(fd);
    return 1;
}
