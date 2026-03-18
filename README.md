## What you CAN reuse from libft:

``ft_atoi`` — converting string args to integers
``ft_putstr_fd`` — printing operations like "sa\n"
``ft_split`` — if args come as a single string
``ft_isdigit``, ``ft_isalpha`` — for parsing/validation

## What you still need to write yourself:

 - All stack operations (ft_push_stack, ft_pop_stack...)
 - All push swap moves (sa, pb, ra, rra...)
 - The algorithm itself


## So your file structure looks clean already:

 - stack.h — structs
 - stack_utils.c — node/stack functions
 - push_swap_main.c — entry point
 - parse.c — parsing args