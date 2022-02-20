/*
** EPITECH PROJECT, 2021
** find_square.c
** File description:
** find_square
*/

#include "../includes/my_bsq.h"

int verif_all_line_square(char **map, int *tab_len_square, int j, int i)
{
    int zero_found = 0;

    for (int y = 0; y < tab_len_square[1] && zero_found == 0 && \
    j + y < tab_len_square[2]; y++) {
        if (map[j + y][i] == 'o') {
            zero_found = 1;
        }
    }
    for (int x = 0; x <= tab_len_square[1] && zero_found == 0 && \
    j + tab_len_square[1] < tab_len_square[2]; x++) {
        if (map[j + tab_len_square[1]][tab_len_square[3] + x] == 'o') {
            zero_found = 1;
        }
        if (x == tab_len_square[3] && \
        map[j + tab_len_square[1]][tab_len_square[3] + x + 1] == 'o') {
            zero_found = 1;
        }
    }
    return zero_found;
}

int *fill_tab_2(int *tab_len_square, int j, int i)
{
    tab_len_square = fill_max_score(tab_len_square, j);
    tab_len_square[1] = 0;
    tab_len_square[3] = i;
    return tab_len_square;
}

int *refresh_i_j(int *tab_len_square, int j, int i)
{
    tab_len_square[6] = j;
    tab_len_square[7] = i;

    return tab_len_square;
}

int *find_square_2(char **map, int j, int i, int *tab_len_square)
{
    if (map[j][i] == '\0') {
        j++;
        i = 0;
        tab_len_square = fill_tab_2(tab_len_square, j, i);
    } else if (map[j][i] == 'o') {
        i++;
        tab_len_square = fill_tab_2(tab_len_square, j, i);
    } else {
        tab_len_square[8] = verif_all_line_square(map, tab_len_square, j, i);
        if (tab_len_square[8] == 0) {
            i++;
            tab_len_square[1]++;
        } else {
            tab_len_square[8] = 0;
            i++;
            tab_len_square = fill_tab_2(tab_len_square, j, i);
        }
    }
    tab_len_square = refresh_i_j(tab_len_square, j, i);
    return tab_len_square;
}

int *find_square(char **map, int j, int i, int *tab_len_square)
{
    tab_len_square[6] = j;

    while (tab_len_square[6] < tab_len_square[2] - 1) {
        tab_len_square = find_square_2(map, tab_len_square[6], \
        tab_len_square[7], tab_len_square);
    }
    return tab_len_square;
}
