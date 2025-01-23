/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:28:21 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/23 16:34:56 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_errors(t_stack **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
