/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:44:48 by william           #+#    #+#             */
/*   Updated: 2018/07/08 18:58:12 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
if (a > b && a > c)
	ra
else if (a > b && a < c)
	sa
else if (a < b && a < c)
	pb
*/
void	run_commands(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_a->top == 2)
	{
		if (stack_a->array[2] > stack_a->array[1] && stack_a->array[2] > stack_a->array[0])
		{

		}
	}
	// else
	// {
	// 	if (stack_a->array[0] > stack_a->array[1] && stack_a->array[0] > stack_a->array[stack_a->top])
	// 	{
	// 		rotate_a(stack_a);
	// 		ft_putendl("ra");
	// 	}
	// 	else if (stack_a->array[0] > stack_a->array[1] && stack_a->array[0] < stack_a->array[stack_a->top])
	// 	{
	// 		swap_a(stack_a);
	// 		ft_putendl("sa");
	// 	}
	// 	else if (stack_a->array[0] < stack_a->array[1] && stack_a->array[0] < stack_a->array[stack_a->top])
	// 	{
	// 		push_b(stack_a, stack_b);
	// 		ft_putendl("pb");
	// 	}
	// }
}