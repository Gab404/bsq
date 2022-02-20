##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC =    ./src/array_1d_to_2d.c \
	 ./src/verif_len_line.c \
	 ./src/lib.c \
	 ./src/gest_error.c \
	 ./src/fs_understand_return_of_read.c \
	 ./src/fs_open_file.c \
	 ./src/load_file_in_mem.c \
	 ./src/mem_alloc_2d_array.c \
	 ./src/fs_get_number_from_first_line.c \
	 ./src/find_square.c \
	 ./src/bsq.c

CFLAGS	+= -Wall -Wextra

OBJ    =    $(SRC:.c=.o)

NAME   =    bsq

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
	fclean
	re
