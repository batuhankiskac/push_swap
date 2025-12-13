/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 07:19:46 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 13:17:18 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_median_and_pos(t_stack *stack)
{
	int	median;
	int	i;

	if (!stack)
		return ;
	i = -1;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_pos = ++i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
	}
}

static void	find_target_a(t_stack *a, t_stack *b)
{
	t_stack	*i_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		i_b = b;
		best_match = LONG_MIN;
		while (i_b)
		{
			if ((i_b->value < a->value) && (i_b->value > best_match))
			{
				best_match = i_b->value;
				target = i_b;
			}
			i_b = i_b->next;
			if (best_match == LONG_MIN)
				a->target = find_max(b);
			else
				a->target = target;
		}
		a = a->next;
	}
}

static void	calculate_push_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->current_pos;
		if (!(a->above_median))
			a->push_cost = len_a - (a->current_pos);
		if (a->target->above_median)
			a->target->push_cost = a->target->current_pos;
		else
			a->target->push_cost = len_b - (a->target->current_pos);
		if (a->above_median == a->target->above_median)
		{
			if (a->push_cost < a->target->push_cost)
				a->push_cost = a->target->push_cost;
		}
		else
			a->push_cost += a->target->push_cost;
		a = a->next;
	}
}

static void	mark_cheapest_node(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	planner_a(t_stack *a, t_stack *b)
{
	set_median_and_pos(a);
	set_median_and_pos(b);
	find_target_a(a, b);
	calculate_push_cost(a, b);
	mark_cheapest_node(a);
}
