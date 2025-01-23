/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:15:03 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/23 16:52:13 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	long			value;
	long			index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

t_stack	*find_last(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
bool	ft_check_sorted(t_stack *stack);
bool	error_duplicate(t_stack *stack, int n);
bool	error_syntax(char *str);
void	ft_stack_init(t_stack **a, const char *argv[]);
void	ft_sort_three(t_stack **a);
void	sa(t_stack **stack_a, bool print);
void	sb(t_stack **stack_b, bool print);
void	ss(t_stack **stack_a, t_stack **stack_b, bool print);
void	ra(t_stack **stack_a, bool print);
void	rb(t_stack **stack_b, bool print);
void	rr(t_stack **stack_a, t_stack **stack_b, bool print);
void	rra(t_stack **stack_a, bool print);
void	rrb(t_stack **stack_b, bool print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	pb(t_stack **stack_b, t_stack **stack_a, bool print);
void	free_errors(t_stack **stack);
void	free_stack(t_stack **stack);
int		stack_len(t_stack *stack);

#endif
