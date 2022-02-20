/*
** EPITECH PROJECT, 2021
** gest_error.c
** File description:
** gest_error
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../includes/my_bsq.h"

int *manage_result(char **map, int *tab_len_square)
{
    if (tab_len_square[2] != 1) {
        if (tab_len_square[0] > tab_len_square[2]) {
            tab_len_square[0] = tab_len_square[2];
            tab_len_square[4]--;
        } else if (tab_len_square[0] >= my_strlen(map[1])) {
            tab_len_square[4]--;
        }
    }
    return tab_len_square;
}

int gest_error_3(char *buffer, int compt_line)
{
    for (int compt = 0; buffer[compt] != '\0'; compt++) {
        if (buffer[compt] == '\n')
            compt_line++;
    }
    return compt_line;
}

int gest_error_2(char *buffer, int error, char *filepath)
{
    int nb_line;
    int compt_line = 0;

    if (error >= 0) {
        nb_line = fs_get_number_from_first_line(filepath);
        compt_line = gest_error_3(buffer, compt_line);
        compt_line--;
        if (compt_line != nb_line) {
            write(2, "Number of lines is false\n", 25);
            error = -1;
        }
    }
    return error;
}

int return_read_and_open(char *filepath, struct stat sb, int error)
{
    int fd;
    char *buffer;
    long long size_bytes;

    stat(filepath, &sb);
    size_bytes = sb.st_size;
    fd = fs_open_file(filepath);
    if (fd >= 0 && size_bytes > 1) {
        buffer = malloc(sizeof(char) * (size_bytes + 1));
        error = fs_understand_return_of_read(fd, buffer, size_bytes);
        error = return_read(error, buffer);
    } else if (fd >= 0) {
        write(2, "File empty\n", 11);
        error = -1;
    } else
        error = -1;
    error = gest_error_2(buffer, error, filepath);
    if (fd >= 0)
        close(fd);
    return error;
}

int gest_error(int argc, char *filepath)
{
    int error = 0;
    struct stat sb;

    if (argc == 1) {
        write(2, "Too few arguments\n", 18);
        error = -1;
    } else if (argc > 2) {
        write(2, "Too more arguments\n", 19);
        error = -1;
    } else {
        error = return_read_and_open(filepath, sb, error);
    }
    if (error == -1 || error == 0)
        error = 84;
    else
        error = 0;
    return error;
}
