NAME = libft.a
CMD = cc -Wall -Wextra -Werror -I includes -c
OBJ = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o


all: $(NAME)


srcs/ft_putchar.o: srcs/ft_putchar.c
	$(CMD) srcs/ft_putchar.c -o srcs/ft_putchar.o

srcs/ft_swap.o: srcs/ft_swap.c
	$(CMD) srcs/ft_swap.c -o srcs/ft_swap.o

srcs/ft_putstr.o: srcs/ft_putstr.c
	$(CMD) srcs/ft_putstr.c -o srcs/ft_putstr.o

srcs/ft_strlen.o: srcs/ft_strlen.c
	$(CMD) srcs/ft_strlen.c -o srcs/ft_strlen.o

srcs/ft_strcmp.o: srcs/ft_strcmp.c
	$(CMD) srcs/ft_strcmp.c -o srcs/ft_strcmp.o



$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	
