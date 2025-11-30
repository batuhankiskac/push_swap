/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:33:14 by bkiskac           #+#    #+#             */
/*   Updated: 2025/11/30 19:15:27 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push;

	if (!(*src))
		return ;
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push->prev = NULL;
	if (!(*dest))
	{
		*dest = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dest;
		(*dest)->prev = push;
		*dest = push;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
