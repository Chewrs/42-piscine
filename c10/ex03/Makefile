NAME = ft_hexdump
SRC = main.c utils.c error.c reader.c printer.c print_hex.c buffer.c
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

