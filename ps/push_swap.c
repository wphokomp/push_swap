/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:36:24 by william           #+#    #+#             */
/*   Updated: 2018/07/13 10:55:59 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(struct s_stack *stack_a, struct s_stack *stack_b)
{
	if (!ft_isempty(stack_b))
	{
		while (!ft_isempty(stack_b))
		{
			push_a(stack_a, stack_b);
			ft_putendl("pa");
			if (!is_sorted_asc(stack_a))
				run_commands(stack_a, stack_b);
		}
	}
}

int		main(int ac, char **arg)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				i;
	char			**numbers;

	if (ac > 1)
	{
		numbers = ft_strsplit(arg[1], ' ');
		stack_a = ft_create_stack(ft_strlen_point(numbers));
		stack_b = ft_create_stack(ft_strlen_point(numbers));
		i = ft_strlen_point(numbers);
		while (--i >= 0)
			ft_push(stack_a, ft_atoi(numbers[i]));
		while (!is_sorted_asc(stack_a))
			run_commands(stack_a, stack_b);
		push_back(stack_a, stack_b);
		free(stack_a);
		free(stack_a->array);
		free(stack_b);
		free(stack_b->array);
		ft_free2d((void **)numbers);
	}
	return (0);
}
