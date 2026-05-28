NAME = bsq
CC = cc -Wall -Wextra -Werror
SRC = main.c printer.c reader.c solver.c validator.c reader_helpers.c
OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
