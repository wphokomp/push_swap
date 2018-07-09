/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 20:56:07 by william           #+#    #+#             */
/*   Updated: 2018/07/09 11:31:52 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct	s_stack	*ft_create_stack(unsigned int cap)
{
	struct s_stack		*stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->capacity = cap;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	return (stack);
}

int				ft_isfull(struct s_stack *stack)
{
	return (unsigned)stack->top == stack->capacity - 1;
}

int				ft_isempty(struct s_stack *stack)
{
	return (stack->top == -1);
}

int				ft_lastitem(struct s_stack *stack)
{
	if (ft_isempty(stack))
		return (-2147483648);
	return (stack->array[stack->top]);
}
