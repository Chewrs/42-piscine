NAME = ft_tail
SRC = main.c tail.c error.c print.c utils.c 
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

