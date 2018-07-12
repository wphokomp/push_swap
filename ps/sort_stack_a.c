/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:44:48 by william           #+#    #+#             */
/*   Updated: 2018/07/11 21:35:46 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//0 9 1 8 2 7 3 6 4 5
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
	else if (stack_a->array[2] > stack_a->array[0]
		&& stack_a->array[2] < stack_a->array[1])
	{
		rev_rotate_a(stack_a);
		ft_putendl("rra");
	}
	else if (stack_a->array[2] < stack_a->array[1]
		&& stack_a->array[2] < stack_a->array[0])
	{
		rotate_a(stack_a);
		ft_putendl("ra");
		swap_a(stack_a);
		ft_putendl("sa");
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
				if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top - 1]
					&& stack_a->array[stack_a->top] < stack_a->array[0])
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

int     is_sorted_desc(struct s_stack *stack)
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
                if (stack->array[j] > stack->array[j + 1])
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