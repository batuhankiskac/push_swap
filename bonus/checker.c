/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:38:31 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/25 12:54:52 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	read_operations(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(stack_a, true);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stack_b, true);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b, true);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(stack_a, stack_b, true);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stack_b, stack_a, true);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(stack_a, true);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(stack_b, true);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b, true);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(stack_a, true);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(stack_b, true);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(stack_a, stack_b, true);
	else
		return (0);
	return (1);
}

static void	handle_error(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	init_stack(&stack_a, argv);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		if (!read_operations(&stack_a, &stack_b, line))
		{
			free(line);
			handle_error(&stack_a, &stack_b);
		}
		free(line);
	}
	if (stack_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	return (0);
}

