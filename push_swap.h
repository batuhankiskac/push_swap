/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:15:03 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/21 18:42:25 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			value;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

t_stack	*ft_lstlast(t_stack *lst);
void	ft_add_back(t_stack **stack, t_stack *new_stack);
int		ft_lstsize(t_stack *lst);
int	ft_min(t_stack *lst);
int	ft_max(t_stack *lst);

#endif
