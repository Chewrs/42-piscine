CC = cc -Wall -Wextra -Werror
NAME = ft_display_file
OBJ = main.o
SRC = main.c

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) -c $(SRC) -o $(OBJ)

.PHONY:	all clean fclean re

