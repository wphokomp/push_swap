/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:36:24 by william           #+#    #+#             */
/*   Updated: 2018/07/09 21:55:23 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int     main(int ac, char **arg)
{
    struct s_stack     *stack_a;
    struct s_stack     *stack_b;
    int                 i;
    char    **numbers;
    
    if (ac > 1)
    {
        numbers = ft_strsplit(arg[1], ' ');
        stack_a = ft_create_stack(ft_strlen_point(numbers));
        i = ft_strlen_point(numbers);
        while (--i >= 0)
            ft_push(stack_a, ft_atoi(numbers[i]));
        // while (--i >= 0)
        //         ft_push(stack_a, ft_atoi(arg[i]));
        // while (!is_sorted_asc(stack_a))
        //         run_commands(stack_a, stack_b);
        // while (!ft_isempty(stack_b))
        // {
        //     if (!is_sorted_desc(stack_b))
        //     {
        //         rotate_b(stack_b);
        //     }
        //     else{
        //         while (!ft_isempty(stack_b))
        //         {
        //             push_a(stack_a, stack_b);
        //             ft_putendl("pa");
        //         }
        //     }
        // }
    }
    return (0);
}