NAME = ft_cat
SRC = main.c utils.c ft_file_read.c
OBJ = $(SRC:.c=.o)
CC = cc -Wall -Werror -Wextra

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: all clean fclean re

