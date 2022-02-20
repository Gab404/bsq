/*
** EPITECH PROJECT, 2021
** fs_open_file.c
** File description:
** fs_open_file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int fs_open_file(char const *filepath)
{
    int res_open;

    res_open = open(filepath, O_RDONLY);
    if (res_open < 0) {
        write(2, "FAILURE\n", 8);
    }
    return res_open;
}
