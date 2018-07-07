/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:33:59 by william           #+#    #+#             */
/*   Updated: 2018/07/07 10:31:18 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(struct s_stack* stack_a)
{
    int     *stack_a_cpy;
    int     first;
    int     i;

    stack_a_cpy = (int *)malloc(sizeof(stack_a_cpy) * (stack_a->capacity - 1));
    first = ft_pop(stack_a);
    i = -1;
    while (!ft_isempty(stack_a))
        stack_a_cpy[++i] = ft_pop(stack_a);
    ft_push(stack_a, first);
    while (i >= 0)
        ft_push(stack_a, stack_a_cpy[i--]);
    free(stack_a_cpy);
    stack_a_cpy = NULL;
}

void    rotate_b(struct s_stack* stack_b)
{
    int     *stack_b_cpy;
    int     first;
    int     i;

    stack_b_cpy = (int *)malloc(sizeof(stack_b_cpy) * (stack_b->capacity - 1));
    first = ft_pop(stack_b);
    i = -1;
    while (!ft_isempty(stack_b))
        stack_b_cpy[++i] = ft_pop(stack_b);
    ft_push(stack_b, first);
    while (i >= 0)
        ft_push(stack_b, stack_b_cpy[i--]);
    free(stack_b_cpy);
    stack_b_cpy = NULL;
}

void    rotate_ab(struct s_stack* stack_a, struct s_stack* stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}

void    rev_rotate_a(struct s_stack* stack_a)
{
    int     *stack_a_cpy;
    int     last;
    int     i;

    i = -1;
    stack_a_cpy = (int *)malloc(sizeof(stack_a_cpy) * (stack_a->capacity - 1));
    while (++i < (int)stack_a->capacity - 1)
        stack_a_cpy[i] = ft_pop(stack_a);
    last = ft_pop(stack_a);
    while (i > 0)
        ft_push(stack_a, stack_a_cpy[--i]);
    ft_push(stack_a, last);
    free(stack_a_cpy);
    stack_a_cpy = NULL;
}

void    rev_rotate_b(struct s_stack* stack_b)
{
    int     *stack_b_cpy;
    int     last;
    int     i;

    i = -1;
    stack_b_cpy = (int *)malloc(sizeof(stack_b_cpy) * (stack_b->capacity - 1));
    while (++i < (int)stack_b->capacity - 1)
        stack_b_cpy[i] = ft_pop(stack_b);
    last = ft_pop(stack_b);
    while (i > 0)
        ft_push(stack_b, stack_b_cpy[--i]);
    ft_push(stack_b, last);
    free(stack_b_cpy);
    stack_b_cpy = NULL;
}
