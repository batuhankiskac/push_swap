/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:50:43 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/23 21:19:30 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack **cheapest)
{

}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack **cheapest)
{

}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{

}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{

}

void	min_on_top(t_stack **stack)
{
	t_stack	*min;

	min = find_min(*stack);
	while ((*stack)->value != min->value)
	{
		if (min->above_median)
			ra(stack, true);
		else
			rra(stack, true);
	}
}
