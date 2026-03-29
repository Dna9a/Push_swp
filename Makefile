NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	push_swap_main.c \
		stack_utils.c \
		parser/parser.c \
		parser/parser_uti.c \
		parser/parser_utils.c \
		parser/s_parser.c \
		libft/main_libft.c \
		libft/s_libft.c \
		sort_base.c \
		algo/algo.c \
		algo/algo_utils.c \
		algo/algo_insert.c \
		moves/swap.c \
		moves/push.c \
		moves/rotate.c \
		moves/reverse.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all