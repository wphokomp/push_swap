/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:01:17 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/13 11:33:47 by wphokomp         ###   ########.fr       */
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

void	ft_freestuff(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_a != NULL)
	{
		free(stack_a->array);
		free(stack_a);
	}
	if (stack_a != NULL)
	{
		free(stack_b->array);
		free(stack_b);
	}
}

void	rotate_stacks_2(char *c, struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (ft_strcmp(c, "rra") == 0)
		rev_rotate_a(stack_a);
	else if (ft_strcmp(c, "rrb") == 0)
	{
		if (stack_b->top > 1)
			rev_rotate_b(stack_b);
		else
		{
			ft_putendl("KO");
			ft_freestuff(stack_a, stack_b);
			exit(1);
		}
	}
	else if (ft_strcmp(c, "rrr") == 0)
	{
		if (stack_a->top > 1 && stack_b->top > 1)
		{
			rev_rotate_ab(stack_a, stack_b);
			if (stack_a->array[0] < stack_a->array[1] ||
				stack_b->array[0] < stack_b->array[1])
			{
				ft_putendl("KO");
				exit(1);
			}
		}
		else
		{
			ft_putendl("KO");
			ft_freestuff(stack_a, stack_b);
			exit(1);
		}
	}
	else if (ft_strcmp(c, "rr") == 0)
		rotate_ab(stack_a, stack_b);
}