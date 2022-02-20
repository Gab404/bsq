/*
** EPITECH PROJECT, 2021
**  mem_alloc_2d_array.c
** File description:
**  mem_alloc_2d_array
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows , int nb_cols)
{
    char **tab = malloc(sizeof(char*) * (nb_rows + 1));

    for (int i = 0; i < nb_rows; i++) {
        tab[i] = malloc(sizeof(char) * (nb_cols + 1));
        tab[i][nb_cols] = '\0';
    }
    tab[nb_rows] = NULL;
    return tab;
}
