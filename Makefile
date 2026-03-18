NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	push_swp_main.c \
		stack_utils.c \
		parcer.c \
		base.c \
		algo/algo.c \
		algo/algo_utils.c \
		algo/algo_utils2.c \
		Moves/swap.c \
		Moves/push.c \
		Moves/rotate.c \
		Moves/reverse.c \
		libft/ft_atoi.c \
		libft/ft_isdigit.c

OBJ = $(SRC:.c=.o)

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

# 	@echo "$(CYAN)Cleaning object files...$(RESET)"
# 	@echo "$(CYAN)Clean complete! 🧹$(RESET)"


# fclean: clean
# 	@echo "$(CYAN)Removing $(NAME)...$(RESET)"
# 	@$(RM) $(NAME)
# 	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
# 	@echo "$(CYAN)Clean complete! 🧹$(RESET)"
