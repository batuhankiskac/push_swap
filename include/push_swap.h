/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:15:03 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/08 18:53:29 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# define ERROR -1

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				current_pos;
	int				cheapest;
	int				above_median;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack	*get_last_node(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
char	**parse_args(int argc, char *argv[]);
int		stack_init(t_stack **stack, char *argv[]);
int		stack_len(t_stack *stack);
int		is_sorted(t_stack *stack);
int		print_error(int error_code);
void	set_median_and_pos(t_stack *stack);
void	planner_a(t_stack *a, t_stack *b);
void	planner_b(t_stack *a, t_stack *b);
void	execute_push(t_stack **a, t_stack **b);
void	greedysort(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **stack, t_stack *top, char stack_name);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **b, t_stack **a, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	free_stack(t_stack **stack);
void	free_all(char **str);

#endif
