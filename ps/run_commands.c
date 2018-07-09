/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:44:48 by william           #+#    #+#             */
/*   Updated: 2018/07/09 17:15:02 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(struct s_stack *stack_a)
{
	if (stack_a->array[2] > stack_a->array[1]
		&& stack_a->array[2] > stack_a->array[0])
	{

		rotate_a(stack_a);
		ft_putendl("ra");
	}
	else if (stack_a->array[2] > stack_a->array[1]
		&& stack_a->array[2] < stack_a->array[0])
	{
		swap_a(stack_a);
		ft_putendl("sa");
	}
	else if (stack_a->array[2] < stack_a->array[1]
		&& stack_a->array[2] < stack_a->array[0])
	{
		rotate_a(stack_a);
		ft_putendl("ra");
		swap_a(stack_a);
		ft_putendl("sa");
	}
	else if (stack_a->array[2] > stack_a->array[0]
		&& stack_a->array[2] < stack_a->array[1])
	{
		swap_a(stack_a);
		ft_putendl("sa");
		rotate_a(stack_a);
		ft_putendl("ra");
	}
}

void	sort_multiple(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] > stack_a->array[0])
	{
		rev_rotate_a(stack_a);
		ft_putendl("rra");
	}
	else if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] < stack_a->array[0])
	{
		swap_a(stack_a);
		ft_putendl("sa");
	}
	else if (stack_a->array[stack_a->top] < stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] < stack_a->array[0])
	{
		push_b(stack_a, stack_b);
		ft_putendl("pb");
	}
	else if (stack_a->array[stack_a->top] > stack_a->array[0]
		&& stack_a->array[stack_a->top] < stack_a->array[stack_a->top - 1])
	{
		swap_a(stack_a);
		ft_putendl("sa");
		rotate_a(stack_a);
		ft_putendl("ra");
	}
}

void	run_commands(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_a->top == 2)
	{
		sort_three(stack_a);
	}
	else
	{
		sort_multiple(stack_a, stack_b);
	}
}