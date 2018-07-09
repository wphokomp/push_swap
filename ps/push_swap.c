/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:36:24 by william           #+#    #+#             */
/*   Updated: 2018/07/09 17:09:13 by wphokomp         ###   ########.fr       */
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
    char               **args;
    char               **_something;
    int                 i;
    
    if (ac > 1)
    {
        i = ac;
        stack_a = ft_create_stack(ac - 1);
        stack_b = ft_create_stack(ac - 1);
        if (ft_strlen_point(arg) == 2 && ft_strlen(arg[1]) > 0)
        {
            i = -1;
            args = ft_strnew_point(ft_strlen(arg[1]));
            while (arg[1][++i]){
                args[i] = ft_strdup(&arg[1][i]);
            }
            _something = ft_strsplit(args[0], ' ');
            stack_a = ft_create_stack(ft_strlen_point(_something));
            stack_b = ft_create_stack(ft_strlen_point(_something));
            i = -1;
            while (_something[++i])
                ft_push(stack_a, ft_atoi(_something[i]));
        }
        while (--i >= 0)
                ft_push(stack_a, ft_atoi(arg[i]));
        while (!is_sorted_asc(stack_a))
                run_commands(stack_a, stack_b);
        while (!ft_isempty(stack_b))
        {
            if (!is_sorted_desc(stack_b))
            {
                rotate_b(stack_b);
            }
            else{
                while (!ft_isempty(stack_b))
                {
                    push_a(stack_a, stack_b);
                    ft_putendl("pa");
                }
            }
        }
    }
    return (0);
}