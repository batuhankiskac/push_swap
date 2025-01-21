/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:53:44 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/21 20:59:09 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(&a);
	if (biggest_node == *a)
		ra(a, false);
	else if (biggest_node == (*a)->next)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}
