/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 07:59:44 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 11:28:30 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target_b(t_stack *a, t_stack *b)
{
	t_stack	*i_a;
	t_stack	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		i_a = a;
		while (i_a)
		{
			if (i_a->value > b->value
				&& i_a->value < best_match)
			{
				best_match = i_a->value;
				target = i_a;
			}
			i_a = i_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	planner_b(t_stack *a, t_stack *b)
{
	set_median_and_pos(a);
	set_median_and_pos(b);
	find_target_b(a, b);
}
