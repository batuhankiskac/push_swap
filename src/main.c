/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:07:55 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 13:03:30 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ERROR);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (stack_init(&a, argv) == ERROR)
	{
		if (argc == 2)
			free_all(argv);
		free_stack(&a);
		ft_putstr_fd("Error\n", 2);
		return (ERROR);
	}
	if (!is_sorted(a))
		greedysort(&a, &b);
	free_stack(&a);
	if (argc == 2)
		free_all(argv);
	return (0);
}
