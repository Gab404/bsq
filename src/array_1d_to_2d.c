/*
** EPITECH PROJECT, 2021
** array_1d_to_2d.c
** File description:
** array_1d_to_2d
*/

#include <unistd.h>
#include "../includes/my_bsq.h"

char *del_first_line(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    i++;
    str += i;
    return str;
}

char **array_1d_to_2d_2(char *str, char **map, int col)
{
    long long compt_char = 0;
    int i = 0;
    int j = 0;

    while (str[compt_char] != '\0') {
        while (i != col) {
            map[j][i] = str[compt_char];
            compt_char++;
            i++;
        }
        j++;
        i = 0;
        compt_char++;
    }
    return map;
}

char **array_1d_to_2d_2_square(char *str, char **map, int col, int nb_line)
{
    long compt_char = 0;
    int i = 0;
    int j = 0;

    while (str[compt_char] != '\0' && j != nb_line) {
        while (i != col && j != nb_line) {
            map[j][i] = str[compt_char];
            compt_char++;
            i++;
        }
        map[j][i + 1] = '\0';
        j++;
        i = 0;
        compt_char++;
    }
    return map;
}

char **array_1d_to_2d(char *filepath, int nb_line)
{
    char *str;
    char **map;
    int col = 0;

    fs_open_file(filepath);
    str = load_file_in_mem(filepath);
    str = del_first_line(str);
    while (str[col] != '\n')
        col++;
    map = mem_alloc_2d_array(nb_line, col);
    if (nb_line != col)
        map = array_1d_to_2d_2(str, map, col);
    else
        map = array_1d_to_2d_2_square(str, map, col, nb_line);
    return map;
}

char **fill_map_one_line(char **map, int *tab_len_square)
{
    int fill_done = 0;

    if (tab_len_square[2] == 1) {
        fill_done = fill_map_one_line_2(map);
        if (fill_done == 1)
            return map;
    }
    return map;
}
