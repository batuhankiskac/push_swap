/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:14:39 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/11 11:47:37 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**splitted_argv;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		splitted_argv = ft_split(argv[1], ' ');
		init_stack(&a, splitted_argv, argc - 1);
	}
	else
		init_stack(&a, argv + 1, argc - 1);
	if (!stack_sorted(a))
		handle_sort(&a, &b);
	if (argc == 2)
		ft_free_split(splitted_argv);
	free_stack(&a);
	return (0);
}
