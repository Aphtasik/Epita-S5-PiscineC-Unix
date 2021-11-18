#include "seven_int.h"

#include <fcntl.h>
#include <unistd.h>

int dump_ints(int *arr, const char *path)
{
    int fd = open(path, O_APPEND | O_CREAT | O_WRONLY);
    if (fd == -1)
        return 0;
    write(fd, arr, 7 * sizeof(int));
    close(fd);
    return 1;
}

int read_ints(int *arr, const char *path)
{
    int fd = open(path, 'r');
    if (fd == -1)
        return 0;
    read(fd, arr, 7 * sizeof(int));
    close(fd);
    return 1;
}
