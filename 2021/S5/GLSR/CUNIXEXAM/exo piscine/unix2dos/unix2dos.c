#include "unix2dos.h"

#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>

unsigned unix2dos(const char *path_to_file)
{
    char buffer[4096] = "";
    int i = 0;
    if (!path_to_file)
        return 1;
    int fd_read = open(path_to_file, O_RDONLY, 0666);
    if (fd_read == -1)
        return 1;
    read(fd_read, buffer, 4096);
    close(fd_read);
    int fd_write = open(path_to_file, O_WRONLY | O_TRUNC);
    if (fd_write == -1)
        return -1;
    while (buffer[i] != '\0')
    {
        if (buffer[i] == '\n')
        {
            if (i == 0)
            {
                write(fd_write, "\r\n", 2);
            }
            else if (buffer[i - 1] == '\r')
            {
                write(fd_write, &buffer[i], 1);
            }
            else
            {
                write(fd_write, "\r\n", 2);
            }
        }
        else
        {
            write(fd_write, &buffer[i], 1);
        }
        i += 1;
    }
    close(fd_write);
    return 0;
}