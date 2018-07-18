/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 11:14:02 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/18 14:29:48 by wphokomp         ###   ########.fr       */
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

void	error_handle(char *c, struct s_stack *stack_a
		, struct s_stack *stack_b, int i)
{
	if (i == 0)
	{
		if (is_sorted_asc(stack_a) && ft_isempty(stack_b))
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	else
	{
		ft_putendl("Error");
		ft_freestuff(stack_a, stack_b);
	}
	exit(1);
}

void	rotate_stacks(struct s_stack *stack_a
		, struct s_stack *stack_b, char *c, int i)
{
	if (ft_strcmp(c, "ra") == 0)
	{
		rotate_a(stack_a);
		if (stack_a->top < 1)
		{
			ft_putendl("KO");
			ft_freestuff(stack_a, stack_b);
			exit(1);
		}
	}
	else if (ft_strcmp(c, "rb") == 0)
	{
		rotate_b(stack_b);
		if (stack_b->top < 1)
		{
			ft_putendl("KO");
			ft_freestuff(stack_a, stack_b);
			exit(1);
		}
	}
	else if (ft_strncmp(c, "rr", 2) == 0)
		rotate_stacks_2(c, stack_a, stack_b);
	else
		error_handle(c, stack_a, stack_b, i);
}

void	ft_matchcommand(char *c, struct s_stack *stack_a
		, struct s_stack *stack_b, int i)
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
	else if (ft_strncmp(c, "r", 1) == 0)
		rotate_stacks(stack_a, stack_b, c, i);
	else
		error_handle(c, stack_a, stack_b, i);
}

void	ft_sort(struct s_stack *stack_a, struct s_stack *stack_b)
{
	int		sorted;
	int		i;

	sorted = is_sorted_asc(stack_a);
	while (!sorted)
	{
		ft_matchcommand(ft_stdinput(&i), stack_a, stack_b, i);
		sorted = is_sorted_asc(stack_a);
		if (sorted && !ft_isempty(stack_b))
			sorted = 0;
	}
	if (sorted)
	{
		ft_putendl("OK");
		ft_freestuff(stack_a, stack_b);
	}
}
