/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:40:43 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/21 19:48:24 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_atol(const char *s)
{
	long	res;
	int sign;

	res = 0;
	sign = 1;

	while (*s == '0' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

void	ft_stack_init(t_stack **a, const char *argv[])
{
	long	num;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (error_syntax(argv[i]))
			
	}
}
