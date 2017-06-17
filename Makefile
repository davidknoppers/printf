all:output
CC=gcc
SRC=main.c _printf.c _printhelp_1.c _printhelp_2.c _printhelp_3.c basic_helpers.c buffer_helpers.c percent_helper.c
NAME=basicprintf
CFLAGS=-Wall -Werror -Wextra -pedantic

output: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
