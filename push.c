/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:32:14 by william           #+#    #+#             */
/*   Updated: 2018/07/06 22:36:59 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(struct Stack* stack_a, struct Stack* stack_b)
{
    if (!isEmpty(stack_b))
        push(stack_a, pop(stack_b));
}

void    push_b(struct Stack* stack_a, struct Stack* stack_b)
{
    if (!isEmpty(stack_a))
        push(stack_b, pop(stack_a));
}
