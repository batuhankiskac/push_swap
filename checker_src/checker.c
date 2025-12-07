/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:56:36 by bkiskac           #+#    #+#             */
/*   Updated: 2025/12/07 17:01:42 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_error(t_stack **a, t_stack **b, int error)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	ft_putstr_fd("Error\n", 2);
	return (error);
}

static int	do_command(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		pa(a, b, false);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(b, a, false);
	else if (!ft_strcmp(cmd, "sa\n"))
		sa(a, false);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b, false);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b, false);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a, false);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, false);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, false);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, false);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, false);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, false);
	else
		return (1);
	return (0);
}

static int	read_and_execute(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (do_command(a, b, line))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

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
		return (handle_error(&a, NULL, ERROR));
	if (read_and_execute(&a, &b))
		return (handle_error(&a, NULL, ERROR));
	if (is_sorted(a) && stack_len(b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

