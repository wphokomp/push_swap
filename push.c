/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 21:32:14 by william           #+#    #+#             */
/*   Updated: 2018/07/12 11:28:30 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_a(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (!ft_isempty(stack_b))
		ft_push(stack_a, ft_pop(stack_b));
}

void	push_b(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (!ft_isempty(stack_a))
		ft_push(stack_b, ft_pop(stack_a));
}
