/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:39:36 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 13:02:23 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest
	, void (*f)(t_stack **, t_stack **))
{
	while (*b != cheapest->target && *a != cheapest)
		f(a, b);
	set_median_and_pos(*a);
	set_median_and_pos(*b);
}

void	execute_push(t_stack **a, t_stack **b)
{
	t_stack	*push_node;

	push_node = *a;
	while (push_node && !push_node->cheapest)
		push_node = push_node->next;
	if (!push_node)
		return ;
	if (push_node->above_median && push_node->target->above_median)
		rotate_both(a, b, push_node, rr);
	else if (!(push_node->above_median)
		&& !(push_node->target->above_median))
		rotate_both(a, b, push_node, rrr);
	finish_rotation(a, push_node, 'a');
	finish_rotation(b, push_node->target, 'b');
	pb(b, a);
}
