/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedysort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:26:38 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 13:54:01 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = find_max(*a);
	if (max == *a)
		ra(a, 1);
	else if ((*a)->next == max)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

static void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	set_median_and_pos(*a);
	finish_rotation(a, min, 'a');
}

void	greedysort(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, 1);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a, 1);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		planner_a(*a, *b);
		execute_push(a, b);
	}
	sort_three(a);
	while (*b)
	{
		planner_b(*a, *b);
		finish_rotation(a, (*b)->target, 'a');
		pa(a, b, 1);
	}
	min_on_top(a);
}
