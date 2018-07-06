/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:01:17 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/06 21:28:40 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap_a(struct Stack *stack_a)
{
	int		first;
	int		second;

	if (!isEmpty(stack_a) && stack_a->capacity > 1)
	{
		first = pop(stack_a);
		second = pop(stack_a);
		push(stack_a, first);
		push(stack_a, second);
	}
}
