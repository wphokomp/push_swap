/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 23:48:32 by william           #+#    #+#             */
/*   Updated: 2018/07/06 23:52:33 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push(struct Stack *stack, int item)
{
	if (isFull(stack)) return ;
	stack->array[++stack->top] = item;
}

int 	pop(struct Stack *stack)
{
	if (isEmpty(stack))
		return (-2147483648);
	return (stack->array[stack->top--]);
}

void    pushall(struct Stack* stack, int *items, int len)
{
    int     i;

    i = -1;
    while (++i < len)
        push(stack, items[i]);
}
