/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:23:14 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/24 18:16:01 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

void	print_error(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	execute_command(char *command, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(command, "sa\n") == 0)
		sa(stack_a, false);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(stack_b, false);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(stack_a, stack_b, false);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(stack_b, stack_a, false);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(stack_a, false);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(stack_b, false);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(stack_a, false);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(stack_b, false);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(stack_a, stack_b, false);
	else
		print_error(stack_a, stack_b);
}

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	init_stack(&stack_a, (char **)argv);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		execute_command(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	if (stack_sorted(stack_a) && stack_len(stack_b) == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
