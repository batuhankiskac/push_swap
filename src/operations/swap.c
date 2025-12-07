/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:33:18 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 13:50:50 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*temp;

	if (!*head || !(*head)->next)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	if (temp->next)
		temp->next->prev = temp;
	(*head)->next = temp;
	(*head)->prev = NULL;
	temp->prev = *head;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
