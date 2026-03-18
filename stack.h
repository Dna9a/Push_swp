#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*top;
	int				size;
}					t_stack;

#endif
