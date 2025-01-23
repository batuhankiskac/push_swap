/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:55:52 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/23 16:22:10 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;

	if (!(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!(*dest))
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool print)
{
	push(stack_b, stack_a);
	if (print)
		ft_printf("pb\n");
}
