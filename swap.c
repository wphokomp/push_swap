/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:01:17 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/06 23:19:41 by william          ###   ########.fr       */
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

void	swap_b(struct Stack *stack_b)
{
	int		first;
	int		second;

	if (!isEmpty(stack_b) && stack_b->capacity > 1)
	{
		first = pop(stack_b);
		second = pop(stack_b);
		push(stack_b, first);
		push(stack_b, second);
	}
}

void	swap_ab(struct Stack* stack_a, struct Stack* stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void    rev_rotate_ab(struct Stack* stack_a, struct Stack* stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
}
