/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:38:31 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/24 21:29:21 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init_and_validate(int argc, char *argv[])
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
		return (NULL);
	init_stack(&a, argv + 1);
	return (a);
}

void	process_commands(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_command(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (stack_sorted(*a) && stack_len(*b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = init_and_validate(argc, argv);
	if (!a)
		show_error();
	process_commands(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
