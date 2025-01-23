/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:51:29 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/23 21:02:07 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(stack_a);
	if (len_a-- > 3 && !(ft_check_sorted(*stack_a)))
		pb(stack_b, stack_a, true);
	if (len_a-- > 3 && !(ft_check_sorted(*stack_a)))
		pb(stack_b, stack_a, true);
	while (len_a-- > 3 && !(ft_check_sorted(*stack_a)))
	{
		ft_init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(*stack_a, *stack_b);
	}
	ft_sort_three(stack_a);
	while (*stack_a)
	{
		ft_init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(*stack_a, *stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
