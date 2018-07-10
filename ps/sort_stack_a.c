/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:44:48 by william           #+#    #+#             */
/*   Updated: 2018/07/10 16:10:01 by wphokomp         ###   ########.fr       */
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
		rev_rotate_a(stack_a);
		ft_putendl("rra");
	}
}

void	sort_multiple(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (stack_a->array[stack_a->top] < stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] < stack_a->array[0])
	{
		push_b(stack_a, stack_b);
		ft_putendl("pb");
		if (stack_b->top > 1)
		{
			if (stack_b->array[stack_b->top] < stack_b->array[stack_b->top - 1])
			{
				swap_b(stack_b);
				ft_putendl("sb");
			}
		}
	}
	else if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] > stack_a->array[0])
	{
		rotate_a(stack_a);
		ft_putendl("ra");
	}
	else if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1]
		&& stack_a->array[stack_a->top] < stack_a->array[0])
	{
		swap_a(stack_a);
		ft_putendl("sa");
	}
	else if (stack_a->array[0] < stack_a->array[stack_a->top]
		&& stack_a->array[0] < stack_a->array[stack_a->top - 1])
	{
		rev_rotate_a(stack_a);
		ft_putendl("rra");
	}
}

int     is_sorted_asc(struct s_stack *stack)
{
    int     i;
    int     j;

    if (!ft_isempty(stack))
    {
        i = -1;
        while (++i < stack->top)
        {
            j = -1;
            while (++j < stack->top)
            {
                if (stack->array[j] < stack->array[j + 1])
                    return (0);
            }
        }
    }
    else
    {
        return (-1);
    }
    return (1);
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