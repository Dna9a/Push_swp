#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

t_list	*ft_lstnew(int data);
void	ft_push_stack(t_stack *stack, int value);
int		ft_pop_stack(t_stack *stack);
void	ft_free_stack(t_stack *stack);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

int		ft_number(char *str);
int		ft_double(char **argv, int argc);
int		ft_is_overflow(char *str);
void	ft_jma3_o_twi(int argc, char **argv);


int		is_sorted(t_stack *stack);
void	sort_three(t_stack *a);
void	push_swap(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
void	rotate_to_min(t_stack *a);
int		min_is_in_top_half(t_stack *a, int min);
int		get_target(t_stack *a, int b_val);
int		get_position(t_stack *stack, int val);
int		get_cost(t_stack *a, t_stack *b, int b_val);
int		find_best(t_stack *a, t_stack *b);
void	bring_to_top_b(t_stack *b, int val);
void	bring_to_top_a(t_stack *a, int val);
void	insert_best(t_stack *a, t_stack *b);

#endif