/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:28:21 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/23 17:01:02 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	error_syntax(char *str)
{
	if (*str == '-' || *str == '+')
		*str++;
	if (!(*str) || !(*str >= '0' && *str <= '9'))
		return (true);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (true);
		*str++;
	}
	return (false);
}

bool	error_duplicate(t_stack *stack, int n)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->value == n)
			count++;
		if (count > 1)
			return (true);
		stack = stack->next;
	}
	return (false);
}

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
