/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:15:25 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/01 19:53:34 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_max(t_stack *stack)
{
	long	max;
	t_stack	*biggest_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

static void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*stack);
	if (*stack == biggest_node)
		ra(stack);
	else if ((*stack)->next == biggest_node)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	base_sort(t_stack **stack, int len)
{
	if (len == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if (len == 3)
	{
		if (stack_len(*stack) == 3)
			sort_three(stack);
		else
		{
			if ((*stack)->value > (*stack)->next->value)
				sa(stack);
			if ((*stack)->next->value > (*stack)->next->next->value)
			{
				ra(stack);
				sa(stack);
				rra(stack);
			}
			if ((*stack)->value > (*stack)->next->value)
				sa(stack);
		}
	}
}
