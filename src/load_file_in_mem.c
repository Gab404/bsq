/*
** EPITECH PROJECT, 2021
** load_file_in_mem.c
** File description:
** load_file_in_mem
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../includes/my_bsq.h"

char *load_file_in_mem(char const *filepath)
{
    char *buffer;
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    ssize_t rd;
    int size_bytes = 0;

    stat(filepath, &sb);
    size_bytes = sb.st_size;
    if (size_bytes != 0) {
        buffer = malloc(sizeof(char) * (sb.st_size + 1));
        rd = read(fd, buffer, sb.st_size);
        if (rd < 0) {
            return NULL;
        } else {
            buffer[rd] = '\0';
        }
    }
    close(fd);
    return buffer;
}

void fill_map_2(char **map, int j, int i, int len)
{
    int x = 0;

    for (int compt = len; compt != 0 && map[j] != NULL; compt--) {
        for (int compt2 = len; compt2 != 0; compt2--) {
            map[j][i + x] = 'x';
            x++;
        }
        x = 0;
        j++;
    }
}

int fill_map_one_line_2(char **map)
{
    int fill_done = 0;

    for (int i = 0; map[0][i] != '\n' && fill_done == 0; i++) {
        if (map[0][i] == '.') {
            map[0][i] = 'x';
            fill_done = 1;
        }
    }
    return fill_done;
}

void manage_tab(int *tab_len_square, char **map, int nb_line)
{
    tab_len_square = fill_int_tab(tab_len_square, nb_line);
    tab_len_square = find_square(map, 0, 0, tab_len_square);
    tab_len_square = manage_result(map, tab_len_square);
}
