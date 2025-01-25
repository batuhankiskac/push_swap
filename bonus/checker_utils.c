/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:39:07 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/25 11:53:16 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	show_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	execute_help(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		rra(a, false);
	else if (line[2] == 'b')
		rrb(b, false);
	else if (line[2] == 'r')
		rrr(a, b, false);
}

char	*execute_command(t_stack **a, t_stack **b, char *line)
{
	ft_printf("Executing command: %s\n", line);
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a, false);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b, false);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b, false);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(a, b, false);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a, false);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b, false);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		execute_help(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b, false);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b, false);
	else
		show_error();
	return (get_next_line(0));
}
