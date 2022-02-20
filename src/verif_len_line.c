/*
** EPITECH PROJECT, 2021
** verif_len_line.c
** File description:
** verif_len_line
*/

#include <unistd.h>
#include "../includes/my_bsq.h"

int after_first_line(int first_line_passed)
{
    if (first_line_passed == 0)
        first_line_passed = 1;
    return first_line_passed;
}

int increment_count_len(int first_line_passed, int len)
{
    if (first_line_passed == 0)
        len++;
    return len;
}

int increment_line_compare(int first_line_passed, int len_line_compare)
{
    if (first_line_passed == 1)
        len_line_compare++;
    return len_line_compare;
}

int verif_len_line(char *str)
{
    int len = 0;
    int len_line_compare = 0;
    int first_line_passed = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] != '\n') {
            len = increment_count_len(first_line_passed, len);
            len_line_compare = increment_line_compare(first_line_passed, \
            len_line_compare);
            i++;
        }
        if (len != len_line_compare && first_line_passed != 0) {
            write(2, "Lenght of lines are not equal\n", 30);
            return -1;
        }
        else
            len_line_compare = 0;
        first_line_passed = after_first_line(first_line_passed);
    }
    return 0;
}

int return_issue_line(int var_error, char *filepath)
{
    char *str;
    int count_len_line;

    if (var_error != 84) {
        str = load_file_in_mem(filepath);
        str = del_first_line(str);
        count_len_line = verif_len_line(str);
    }
    if (count_len_line == -1)
        var_error = 84;
    return var_error;
}
