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
		libft/ft_isdigit.c \
		libft/ft_itoa.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strjoin.c

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

re: fclean all# re: fclean all


# 	@echo "$(CYAN)Cleaning object files...$(RESET)"
# 	@echo "$(CYAN)Clean complete! 🧹$(RESET)"


# fclean: clean
# 	@echo "$(CYAN)Removing $(NAME)...$(RESET)"
# 	@$(RM) $(NAME)
# 	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
# 	@echo "$(CYAN)Clean complete! 🧹$(RESET)"
