/*
** EPITECH PROJECT, 2021
** fs_understand_return_of_read.c
** File description:
** fs_understand_return_of_read
*/

#include <unistd.h>

ssize_t fct_1(ssize_t res_read, int size)
{
    if (res_read < size) {
        write(2, "read didn't complete the entire buffer\n", 39);
        res_read = -1;
    }
    return res_read;
}

ssize_t fs_understand_return_of_read(int fd , char *buffer , int size)
{
    ssize_t res_read;
    int res_read_2;

    res_read = read(fd, buffer, size);
    if (res_read < 0) {
        write(2, "read failed\n", 12);
        res_read = -1;
    }
    else if (res_read == 0) {
        write(2, "read has nothing more to read\n", 30);
        res_read = 0;
    }
    else {
        res_read = fct_1(res_read, size);
    }
    res_read_2 = res_read;
    return res_read_2;
}
