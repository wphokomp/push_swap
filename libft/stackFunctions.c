/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackFunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 20:56:07 by william           #+#    #+#             */
/*   Updated: 2018/07/06 21:07:53 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct  Stack   *ft_createStack(unsigned int cap)
{
    struct	Stack* stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->capacity = cap;
	stack->top = -1;
	stack->array = (int *) malloc(stack->capacity * sizeof(int));
	return stack;
}

int		isFull(struct Stack* stack)
{
	return (unsigned)stack->top == stack->capacity - 1;
}

int     isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int		lastItem(struct Stack *stack)
{
	if (isEmpty(stack))
		return (-2147483648);
	return (stack->array[stack->top]);
}

void	push(struct Stack *stack, char item)
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