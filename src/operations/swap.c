/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:33:18 by bkiskac           #+#    #+#             */
/*   Updated: 2025/11/30 12:49:00 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **head)
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

void	sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss", 1);
}