/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:33:16 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 13:50:50 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*first_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = get_last_node(*stack);
	*stack = first_node->next;
	(*stack)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
}

void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
