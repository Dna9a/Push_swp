/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:58:48 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/29 23:54:33 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*top;
	int				size;
}					t_stack;

t_list				*ft_lstnew(int data);
void				ft_push_stack(t_stack *stack, int value);
int					ft_pop_stack(t_stack *stack);
void				push_split_args(t_stack *a, char **split);
int					has_space(char *str);
void				push_arg(t_stack *a, char *arg);
void				fill_stack_from_args(int ac, char **av, t_stack *a);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_count_word(const char *s, char c);
int					overflow_guard(long s, unsigned long r);
int					fill_word(char **slot, const char *str, int len);
int					ft_fillres(char **res, int res_len, const char *str,
						char sp);
char				**ft_split(char const *s, char c);
void				ft_validate_split(char *str);
void				ft_free_split(char **split);
char				**safe_split(char *arg);
void				ft_check_split(char **split, int i);
int					ft_cmp_split_args(char **si, char *argj);
char				**split_arg(char *arg);
size_t				skip_blanks(const char *str);
long				get_overflow(long s, unsigned long r);
long				ft_atol(const char *str);
void				validate_arg(char *arg);
void				error_msg(void);
void				exit_msg(char **split);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				ft_swap(t_stack *stack);
void				ft_rotate(t_stack *stack);
void				ft_reverse_rotate(t_stack *stack);
void				ft_assign_index(t_stack *a);
void				ft_free_stack(t_stack *stack);

int					ft_number(char *str);
int					ft_double(char **argv, int argc);
int					ft_is_overflow(char *str);
void				ft_jma3_o_twi(int argc, char **argv);

void				init_stack(t_stack *stack);
int					is_sorted(t_stack *stack);
void				sort_three(t_stack *a);
void				push_swap(t_stack *a, t_stack *b);
void				sort_large(t_stack *a, t_stack *b);
void				rotate_to_min(t_stack *a);
int					min_is_in_top_half(t_stack *a, int min);
int					get_target(t_stack *a, int b_val);
int					get_position(t_stack *stack, int val);
int					get_cost(t_stack *a, t_stack *b, int b_val);
int					find_best(t_stack *a, t_stack *b);
void				bring_to_top_b(t_stack *b, int val);
void				bring_to_top_a(t_stack *a, int val);
void				insert_best(t_stack *a, t_stack *b);
void				push_to_b_smart(t_stack *a, t_stack *b);
void				do_combined_rotations(t_stack *a, t_stack *b, int best_val,
						int target);

#endif
