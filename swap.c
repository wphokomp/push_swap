/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:01:17 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/12 11:32:36 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

void	swap_a(struct s_stack *stack_a)
{
	int		first;
	int		second;

	if (!ft_isempty(stack_a))
	{
		first = ft_pop(stack_a);
		second = ft_pop(stack_a);
		ft_push(stack_a, first);
		ft_push(stack_a, second);
	}
}

void	swap_b(struct s_stack *stack_b)
{
	int		first;
	int		second;

	if (!ft_isempty(stack_b) && stack_b->capacity > 1)
	{
		first = ft_pop(stack_b);
		second = ft_pop(stack_b);
		ft_push(stack_b, first);
		ft_push(stack_b, second);
	}
}

void	swap_ab(struct s_stack *stack_a, struct s_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rev_rotate_ab(struct s_stack *stack_a, struct s_stack *stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
}
