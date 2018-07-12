/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:36:24 by william           #+#    #+#             */
/*   Updated: 2018/07/11 21:35:41 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        stack_b = ft_create_stack(ft_strlen_point(numbers));
        i = ft_strlen_point(numbers);
        while (--i >= 0)
            ft_push(stack_a, ft_atoi(numbers[i]));
        while (!is_sorted_asc(stack_a)) {
            run_commands(stack_a, stack_b);
        }
        //int n = stack_b->top;
        // ft_putchar('\n');
        // while (n >= 0)
        //     ft_putnbr(stack_b->array[n--]);
        while (!ft_isempty(stack_b))
        {
            if (!is_sorted_desc(stack_b))
            {
                rotate_b(stack_b);
            }
            else
            {
                while (!ft_isempty(stack_b))
                {
                    push_a(stack_a, stack_b);
                    ft_putendl("pa");
                }
            }
        }
        // int a = stack_a->top;
        // while (a >= 0)
        //     ft_putnbr(stack_a->array[a--]);
    }
    return (0);
}