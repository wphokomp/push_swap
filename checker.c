/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:37:02 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/06 21:28:48 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "limits.h"

char	*ft_cmp(char *c)
{
	if (ft_strncmp(c, "sa", 2) == 0)
		return ("Match sa");
	else if (ft_strncmp(c, "sb", 2) == 0)
		return ("Match sb");
	else if (ft_strncmp(c, "ss", 2) == 0)
		return ("Match ss");
	else if (ft_strncmp(c, "pa", 2) == 0)
		return ("Match pa");
	else if (ft_strncmp(c, "pb", 2) == 0)
		return ("Match pb");
	else if (ft_strncmp(c, "ra", 2) == 0)
		return ("Match ra");
	else if (ft_strncmp(c, "rb", 2) == 0)
		return ("Match rb");
	else if (ft_strncmp(c, "rra", 3) == 0)
		return ("Match rra");
	else if (ft_strncmp(c, "rrb", 3) == 0)
		return ("Match rrb");
	else if (ft_strncmp(c, "rrr", 3) == 0)
		return ("Match rrr");
	else if (ft_strncmp(c, "rr", 2) == 0)
		return ("Match rr");
	else
		return ("Error");
}

char	*ft_input(void)
{
	char	c;
	char	*ret;
	char	*tmp;
	char 	*tmp2;

	ret = ft_strnew(1);
	while (read(0, &c, 1))
	{
		if (c == '\n')
			break ;
		tmp2 = ft_strnew(1);
		ft_strncpy(tmp2, &c, 1);
		tmp = ft_strjoin(ret, tmp2);
		free(tmp2);
		free(ret);
		ret = tmp;
	}
	return (ret);
}

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
	if (ft_atol(list[0]) > 2147483647 || (ft_atoi(list[0]) * -1) == (int)-2147483648){
		return (1);
	}
	while (list[++i])
	{
		o = i;
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
	int		arg;
	struct	Stack	*stack_a;

	arg = ac;
	stack_a = ft_createStack(ac - 1);
	if (ac > 1)
	{
		if (ft_checkin(av + 1) == 1 && !check_duplicates(av + 1))
		{
			while (--arg >= 0)
				push(stack_a, ft_atoi(av[arg]));
			// int	number;
			// while ((number = pop(stack_a)) != INT_MIN)
			// 	ft_putnbrendl(number);
		}
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	return (0);
}
