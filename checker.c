/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:37:02 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/12 15:30:46 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		while (stack[arg][++i])
			if (!ft_isdigit(stack[arg][i]) && stack[arg][0] != '-')
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

int		check_duplicates(char **list)
{
	int		i;
	int		o;

	i = -1;
	while (list[++i])
	{
		o = i;
		if (ft_atol(list[i]) > 2147483647
				|| (ft_atoi(list[i]) * -1) == (int)-2147483648)
			return (1);
		while ((size_t)o < ft_strlen_point(list) - 1)
		{
			o++;
			if (ft_strcmp(list[i], list[o]) == 0)
				return (1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	int				i;
	char			**args;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	if (ac > 1)
	{
		args = ft_strsplit(av[1], ' ');
		ac = ft_strlen_point(args);
		stack_a = ft_create_stack(ac);
		stack_b = ft_create_stack(ac);
		if (ft_checkin(args) == 1 && !check_duplicates(args))
		{
			while (--ac >= 0)
				ft_push(stack_a, ft_atoi(args[ac]));
			ft_matchcommand(ft_stdinput(&i), stack_a, stack_b, i);
			ft_sort(stack_a, stack_b);
		}
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	return (0);
}
