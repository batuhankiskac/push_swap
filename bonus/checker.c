/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:23:14 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/24 20:06:14 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack(&stack_a, argv + 1);
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
