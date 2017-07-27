/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:37:02 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/22 13:01:04 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int		ft_checkin(char **stack)
{
	int		i;
	int		boo;
	size_t	arg;

	i = -1;
	arg = 0;
	boo = 1;
	while (stack[++arg])
	{
		i = -1;
		while(stack[arg][++i])
			if (!ft_isdigit(stack[arg][i]))
			{
				boo = 0;
				break ;
			}
		if (!boo)
			break ;
	}
	if (arg == ft_strlen_point(stack))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		arg;
	int		i;
	char	**stack_a;

	arg = 0;
	i = -1;
	stack_a = (char **)malloc(sizeof(char *) * (ac - 1));
	if (ac > 0)
	{
		if (ft_checkin(av) == 1)
		{
			while (av[++arg])
				stack_a[++i] = av[arg];
			//Do Stuff
		}
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	return (0);
}
