/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:33:14 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 13:52:24 by bkiskac          ###   ########.fr       */
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
	if (!(*dest))
	{
		*dest = push;
		push->next = NULL;
		return ;
	}
	push->next = *dest;
	(*dest)->prev = push;
	*dest = push;
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a, int print)
{
	push(b, a);
	if (print)
		ft_putstr_fd("pb\n", 1);
}
