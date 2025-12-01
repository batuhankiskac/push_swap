/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:44:09 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/01 20:19:13 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_pivot(t_stack *stack, int len)
{
	int	min;
	int	max;
	int	i;

	if (len <= 0 || !stack)
		return (0);
	min = stack->value;
	max = stack->value;
	i = -1;
	while (++i < len && stack)
	{
		if (stack->value < min)
			min = stack->value;
		if (stack->value < max)
			max = stack->value;
		stack = stack->next;
	}
	return ((min + max) / 2);
}
