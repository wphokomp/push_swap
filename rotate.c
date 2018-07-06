/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:33:59 by william           #+#    #+#             */
/*   Updated: 2018/07/06 23:42:35 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(struct Stack* stack_a)
{
    int     *stack_a_cpy;
    int     first;
    int     i;

    stack_a_cpy = (int *)malloc(sizeof(stack_a_cpy) * (stack_a->capacity - 1));
    first = pop(stack_a);
    i = -1;
    while (!isEmpty(stack_a))
        stack_a_cpy[++i] = pop(stack_a);
    push(stack_a, first);
    while (i >= 0)
        push(stack_a, stack_a_cpy[i--]);
    free(stack_a_cpy);
    stack_a_cpy = NULL;
}

void    rotate_b(struct Stack* stack_b)
{
    int     *stack_b_cpy;
    int     first;
    int     i;

    stack_b_cpy = (int *)malloc(sizeof(stack_b_cpy) * (stack_b->capacity - 1));
    first = pop(stack_b);
    i = -1;
    while (!isEmpty(stack_b))
        stack_b_cpy[++i] = pop(stack_b);
    push(stack_b, first);
    while (i >= 0)
        push(stack_b, stack_b_cpy[i--]);
    free(stack_b_cpy);
    stack_b_cpy = NULL;
}

void    rotate_ab(struct Stack* stack_a, struct Stack* stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
}

void    rev_rotate_a(struct Stack* stack_a)
{
    int     *stack_a_cpy;
    int     last;
    int     i;

    i = -1;
    stack_a_cpy = (int *)malloc(sizeof(stack_a_cpy) * (stack_a->capacity - 1));
    while (++i < (int)stack_a->capacity - 1)
        stack_a_cpy[i] = pop(stack_a);
    last = pop(stack_a);
    while (i > 0)
        push(stack_a, stack_a_cpy[--i]);
    push(stack_a, last);
    free(stack_a_cpy);
    stack_a_cpy = NULL;
}

void    rev_rotate_b(struct Stack* stack_b)
{
    int     *stack_b_cpy;
    int     last;
    int     i;

    i = -1;
    stack_b_cpy = (int *)malloc(sizeof(stack_b_cpy) * (stack_b->capacity - 1));
    while (++i < (int)stack_b->capacity - 1)
        stack_b_cpy[i] = pop(stack_b);
    last = pop(stack_b);
    while (i > 0)
        push(stack_b, stack_b_cpy[--i]);
    push(stack_b, last);
    free(stack_b_cpy);
    stack_b_cpy = NULL;
}
