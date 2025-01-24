/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:23:14 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/24 20:25:29 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*command;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, argv + 1);
	while ((command = get_next_line(0)) != NULL)
	{
		execute_command(command, &stack_a, &stack_b);
		free(command);
	}
	if (stack_sorted(stack_a) && stack_len(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
