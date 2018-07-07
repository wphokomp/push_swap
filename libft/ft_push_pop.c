/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 23:48:32 by william           #+#    #+#             */
/*   Updated: 2018/07/07 10:31:08 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push(struct s_stack *stack, int item)
{
	if (ft_isfull(stack)) return ;
	stack->array[++stack->top] = item;
}

int 	ft_pop(struct s_stack *stack)
{
	if (ft_isempty(stack))
		return (-2147483648);
	return (stack->array[stack->top--]);
}

void    ft_pushall(struct s_stack* stack, int *items, int len)
{
    int     i;

    i = -1;
    while (++i < len)
        ft_push(stack, items[i]);
}
