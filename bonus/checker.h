/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:05:26 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/24 20:05:58 by bkiskac          ###   ########.fr       */
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
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
bool	stack_sorted(t_stack *stack);
int		error_duplicate(t_stack *a, int n);
int		error_syntax(char *str_n);
int		stack_len(t_stack *stack);
void	free_errors(t_stack **a);
void	free_stack(t_stack **stack);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	init_stack(t_stack **a, char **argv);
void	current_index(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);

#endif
