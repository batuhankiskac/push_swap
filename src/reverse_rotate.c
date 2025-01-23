/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:44:18 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/23 16:27:53 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **stack_a, bool print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, bool print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
