/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:23:14 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/24 17:27:08 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	read_operations(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(&a, false);
	else if (!ft_strcmp(line, "sb"))
		sb(&b, false);
	else if (!ft_strcmp(line, "ss"))
		ss(&a, &b, false);
	else if (!ft_strcmp(line, "pa"))
		pa(&a, &b, false);
	else if (!ft_strcmp(line, "pb"))
		pb(&b, &a, false);
	else if (!ft_strcmp(line, "ra"))
		ra(&a, false);
	else if (!ft_strcmp(line, "rb"))
		rb(&b, false);
	else if (!ft_strcmp(line, "rr"))
		rr(&a, &b, false);
	else if (!ft_strcmp(line, "rra"))
		rra(&a, false);
	else if (!ft_strcmp(line, "rrb"))
		rrb(&b, false);
	else if (!ft_strcmp(line, "rrr"))
		rrr(&a, &b, false);
	else
		return (1);
	return (0);
}
