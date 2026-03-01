NAME = push_swap

HDER = 

SRC =

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(HDER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all