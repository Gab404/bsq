/*
** EPITECH PROJECT, 2021
** fs_get_number_from_first_line.c
** File description:
** fs_get_number_from_first_line
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int fs_print_2(char *buffer, int i)
{
    while (buffer[i] != '\n') {
        i++;
    }
    return i;
}

int my_getnbr(char const *str)
{
    int neg = 1;
    int value_0 = 48;
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' || str[i] == '+') {
            neg = neg * -1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10;
            result += (str[i] - value_0);
        }
    }
    return neg * result;
}

int fs_get_2(char *buffer, int i, int size_bytes)
{
    if (size_bytes > 0) {
        i = fs_print_2(buffer, i);
        buffer[i + 1] = '\0';
        i = my_getnbr(buffer);
        return i;
    }
    return -1;
}

int fs_get_number_from_first_line(char const *filepath)
{
    struct stat buf;
    int size_bytes;
    int fd;
    char *buffer;
    int i = 0;

    stat(filepath, &buf);
    size_bytes = buf.st_size;
    buffer = malloc(sizeof(char) * (size_bytes + 1));
    fd = open(filepath, O_RDONLY);
    if (fd >= 0 && size_bytes > 1) {
        read(fd, buffer, size_bytes);
        i = fs_get_2(buffer, i, size_bytes);
        if (i > 0)
            return i;
        else {
            return -1;
        }
    }
    return -1;
}
