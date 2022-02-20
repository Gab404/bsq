/*
** EPITECH PROJECT, 2021
** my_bsq.h
** File description:
** my_bsq
*/

#ifndef MY_BSQ_H_
    # define MY_BSQ_H_

int *fill_max_score(int *tab_len_square, int j);
char *del_first_line(char *str);
int return_issue_line(int var_error, char *filepath);
int *fill_int_tab(int *tab_len_square, int nb_line);
void manage_tab(int *tab_len_square, char **map, int nb_line);
int return_read(int error, char *buffer);
int fill_map_one_line_2(char **map);
void fill_map_2(char **map, int j, int i, int len);
void free_map(char **map, int nb_line);
int my_strlen(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
int *find_square(char **map, int j, int i, int *tab_len_square);
int *manage_result(char **map, int *tab_len_square);
int gest_error(int argc, char *filepath);
int fs_understand_return_of_read(int fd , char *buffer , int size);
char **fill_map_one_line(char **map, int *tab_len_square);
char **array_1d_to_2d(char *filepath, int nb_line);
int fs_open_file(char const *filepath);
int fs_get_number_from_first_line(char const *filepath);
char ** mem_alloc_2d_array(int nb_rows , int nb_cols);
char *load_file_in_mem(char const *filepath);

#endif /* MY_BSQ_H_ */
