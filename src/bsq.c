/*
** EPITECH PROJECT, 2021
** bsq.c
** File description:
** bsq
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/my_bsq.h"

int my_show_word_array(char * const *tab, int nb_line)
{
    int i = 0;

    while (i < nb_line) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}

int *fill_max_score(int *tab_len_square, int j)
{
    if (tab_len_square[0] < tab_len_square[1]) {
        tab_len_square[0] = tab_len_square[1];
        tab_len_square[4] = j;
        tab_len_square[5] = tab_len_square[3];
        tab_len_square[6] = 0;
    }
    return tab_len_square;
}

char **fill_map(char **map, int *tab_len_square)
{
    int i = tab_len_square[5];
    int j = tab_len_square[4];
    int len = tab_len_square[0];

    map = fill_map_one_line(map, tab_len_square);
    if (tab_len_square[2] != 1) {
        fill_map_2(map, j, i, len);
    }
    return map;
}

int *fill_int_tab(int *tab_len_square, int nb_line)
{
    tab_len_square[0] = 0;
    tab_len_square[1] = 0;
    tab_len_square[2] = nb_line;
    tab_len_square[3] = 0;
    tab_len_square[4] = 0;
    tab_len_square[5] = 0;
    tab_len_square[6] = 0;
    tab_len_square[7] = 0;
    tab_len_square[8] = 0;
    return tab_len_square;
}

int main(int argc, char **argv)
{
    char *filepath = argv[1];
    int nb_line = fs_get_number_from_first_line(filepath);
    char **map = malloc(sizeof(char*) * nb_line);
    int *tab_len_square = malloc(sizeof(int) * 9);
    int var_error = 0;

    var_error = return_issue_line(gest_error(argc, filepath), filepath);
    if (var_error == 84)
        return var_error;
    map = array_1d_to_2d(filepath, nb_line);
    manage_tab(tab_len_square, map, nb_line);
    if (nb_line == 1 && my_strlen(map[0]) == 1 && map[0][0] == 'o') {
        my_show_word_array(map, nb_line);
        return var_error;
    }
    map = fill_map(map, tab_len_square);
    my_show_word_array(map, nb_line);
    free_map(map, nb_line);
    free(tab_len_square);
    return var_error;
}
