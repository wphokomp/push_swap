/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:36:24 by william           #+#    #+#             */
/*   Updated: 2018/07/08 18:29:00 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//

int     is_sorted_asc(struct s_stack *stack)
{
    int     i;
    int     j;

    // if (!ft_isempty(stack))
    // {
        i = stack->top + 1;
        while (--i < stack->top)
        {
            j = stack->top + 1;
            while (--j < stack->top)
            {
                if (stack->array[j] > stack->array[j - 1])
                    return (0);
            }
        }
    // }
    // else
    // {
    //     return (-1);
    // }
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

int     main(int ac, char **arg)
{
    struct s_stack     *stack_a;
    struct s_stack     *stack_b;
    int                 i;

    if (ac > 1)
    {
        i = ac;
        stack_a = ft_create_stack(ac - 1);
        stack_b = ft_create_stack(ac - 1);
        while (--i >= 0)
            ft_push(stack_a, ft_atoi(arg[i]));
        // ft_putnbrendl(is_sorted_desc(stack_a));

        i = stack_a->top + 1;
        while (--i >= 0)
            ft_putnbrendl(stack_a->array[i]);
        ft_putchar('\n');
        run_commands(stack_a, stack_b);
        i = stack_a->top + 1;
        while (--i >= 0)
            ft_putnbrendl(stack_a->array[i]);
        // while (!is_sorted_desc(stack_a))
            // run_commands(stack_a, stack_b);
    }
    return (0);
}