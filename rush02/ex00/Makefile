NAME = rush-02

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILEC = main.c \
		main_helper.c \
		stdin_reader.c \
		dict_parser.c \
		dict_utils.c \
		dict_utils_2.c \
		file_reader.c \
		number_to_parts.c \
		part_big.c \
		parts_utils.c \
		parts_utils_2.c \
		str_utils.c

FILEO = $(FILEC:.c=.o)

all: $(NAME)

$(NAME): $(FILEO)
	$(CC) $(CFLAGS) $(FILEO) -o $(NAME)

clean:
	rm -f $(FILEO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
