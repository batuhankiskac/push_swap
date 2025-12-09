/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:07:55 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/08 20:14:28 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	argv = parse_args(argc, argv);
	if (!argv)
		return (print_error(ERROR));
	if (stack_init(&a, argv) == ERROR)
	{
		if (argc == 2)
			free_all(argv);
		free_stack(&a);
		return (print_error(ERROR));
	}
	if (!is_sorted(a))
		greedysort(&a, &b);
	free_stack(&a);
	if (argc == 2)
		free_all(argv);
	return (0);
}
