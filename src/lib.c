/*
** EPITECH PROJECT, 2021
** lib.c
** File description:
** lib
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen (char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

void free_map(char **map, int nb_line)
{
    for (int j = nb_line - 1; j >= 0; j--) {
        free(map[j]);
    }
}

int return_read(int error, char *buffer)
{
    if (error < 0) {
        error = -1;
    } else {
        buffer[error] = '\0';
    }
    return error;
}
