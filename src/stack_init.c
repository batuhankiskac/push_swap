/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:27:06 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/01 18:39:22 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	new_node(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*last;

	if (!stack)
		return ;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = num;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = node;
		node->prev = last;
	}
}

static int	is_contain(t_stack *stack, int num)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	is_valid_num(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (0);
	if ((*str == '+' || *str == '-') && !ft_isdigit(str[1]))
		return (0);
	while (*(++str))
	{
		if (!ft_isdigit(*str))
			return (0);
	}
	return (1);
}

int	stack_init(t_stack **stack, char *argv[])
{
	long	num;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (!is_valid_num(argv[i]))
			return (ERROR);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		if (error_duplicate(*stack, (int)num))
			return (1);
		new_node(stack, (int)num);
	}
	return (0);
}
