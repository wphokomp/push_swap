/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 11:14:02 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/12 13:30:42 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_b->top > 1)
	{
		if (stack_b->array[stack_a->top] < stack_b->array[stack_b->top - 1])
		{
			if (stack_a->array[stack_a->top] >
					stack_a->array[stack_a->top - 1] &&
				stack_a->array[stack_a->top] < stack_a->array[0])
			{
				swap_ab(stack_a, stack_b);
				ft_putendl("ss");
			}
			else
			{
				swap_b(stack_b);
				ft_putendl("sb");
			}
		}
	}
}

void	error_handle(char *c)
{
	ft_putendl("Error");
	exit(0);
}

void	ft_matchcommand(char *c, struct s_stack *stack_a
		, struct s_stack *stack_b)
{
	if (ft_strcmp(c, "sa") == 0)
		swap_a(stack_a);
	else if (ft_strcmp(c, "sb") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(c, "ss") == 0)
		swap_ab(stack_a, stack_b);
	else if (ft_strcmp(c, "pa") == 0)
		push_a(stack_a, stack_b);
	else if (ft_strcmp(c, "pb") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(c, "ra") == 0)
		rotate_a(stack_a);
	else if (ft_strcmp(c, "rb") == 0)
		rotate_b(stack_a);
	else if (ft_strcmp(c, "rra") == 0)
		rev_rotate_a(stack_a);
	else if (ft_strcmp(c, "rrb") == 0)
		rev_rotate_b(stack_b);
	else if (ft_strcmp(c, "rrr") == 0)
		rev_rotate_ab(stack_a, stack_b);
	else if (ft_strcmp(c, "rr") == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strcmp(c, "^D") == 0)
	{
	}
	else
		error_handle(c);
}

void	ft_sort(struct s_stack *stack_a, struct s_stack *stack_b)
{
	int		sorted;

	sorted = is_sorted_asc(stack_a);
	while (!sorted)
	{
		ft_matchcommand(ft_stdinput(), stack_a, stack_b);
		sorted = is_sorted_asc(stack_a);
		if (sorted && !ft_isempty(stack_b))
			sorted = 0;
	}
	ft_putendl("OK");
}
