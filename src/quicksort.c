/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:04:33 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/05 21:01:35 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_b(t_stack **a, t_stack **b, int pivot, int *counts)
{
	if ((*b)->value >= pivot)
	{
		pa(a, b);
		counts[0]++;
	}
	else
	{
		rb(b);
		counts[1]++;
	}
}

static void	partition_a(t_stack **a, t_stack **b, int pivot, int *counts)
{
	if ((*a)->value < pivot)
	{
		pb(b, a);
		counts[0]++;
	}
	else
	{
		ra(a);
		counts[1]++;
	}
}

static int	base_case_b(t_stack **a, t_stack **b, int len)
{
	if (len <= 2)
	{
		while (len--)
		{
			pa(a, b);
			if (len == 1 && (*a)->next && (*a)->value > (*a)->next->value)
				sa(a);
		}
		return (1);
	}
	return (0);
}

void	quicksort_b(t_stack **a, t_stack **b, int len)
{
	int	pivot;
	int	counts[2];
	int	i;

	if (len <= 0 || base_case_b(a, b, len))
		return ;
	pivot = get_pivot(*b, len);
	counts[0] = 0;
	counts[1] = 0;
	i = -1;
	while (++i < len)
		partition_b(a, b, pivot, counts);
	if (counts[1] != stack_len(*b))
		while (counts[1]--)
			rrb(b);
	quicksort_a(a, b, counts[0]);
	quicksort_b(a, b, len - counts[0]);
}

void	quicksort_a(t_stack **a, t_stack **b, int len)
{
	int	pivot;
	int	counts[2];
	int	i;

	if (len <= 3)
	{
		base_sort(a, len);
		return ;
	}
	pivot = get_pivot(*a, len);
	counts[0] = 0;
	counts[1] = 0;
	i = -1;
	while (++i < len)
		partition_a(a, b, pivot, counts);
	if (counts[1] != stack_len(*a))
		while (counts[1]--)
			rra(a);
	quicksort_a(a, b, len - counts[0]);
	quicksort_b(a, b, counts[0]);
}
