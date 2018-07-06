/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:37:02 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/07 00:22:58 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "limits.h"

void	ft_matchcommand(char *c, struct Stack* stack_a, struct Stack* stack_b)
{
	if (ft_strcmp(c, "sa") == 0)
		swap_a(stack_a);
	else if (ft_strcmp(c, "sb") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(c, "ss") == 0)
		swap_ab(stack_a, stack_b);
	else if (ft_strcmp(c, "pa") == 0)
		push_a(stack_a, stack_b);
	else if (ft_strcmp(c, "pb") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(c, "ra") == 0)
		rotate_a(stack_a);
	else if (ft_strcmp(c, "rb") == 0)
		rotate_b(stack_a);
	else if (ft_strcmp(c, "rra") == 0)
		rev_rotate_a(stack_a);
	else if (ft_strcmp(c, "rrb") == 0)
		rev_rotate_b(stack_b);
	else if (ft_strcmp(c, "rrr") == 0)
		rev_rotate_ab(stack_a, stack_b);
	else if (ft_strcmp(c, "rr") == 0)
		rotate_ab(stack_a, stack_b);
	else
	{
		ft_putendl("Error");
		exit(0);
	}
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

int		ft_sorted(struct Stack* stack_a, struct Stack* stack_b)
{
	int		i;
	int		order;
	int		*stack_a_cpy;

	if (!isEmpty(stack_b))
		return (0);
	else
	{
		i = -1;
		stack_a_cpy = (int *)malloc(sizeof(stack_a_cpy) * stack_a->capacity);
		while (!isEmpty(stack_a))
			stack_a_cpy[++i] = pop(stack_a);
		order = -1;
		while (++order <= i && (order + 1) <= i)
			if (stack_a_cpy[order] > stack_a_cpy[order + 1])
				return (0);
	}
	pushall(stack_a, stack_a_cpy, i);
	free(stack_a_cpy);
    stack_a_cpy = NULL;
	return (1);
}

int		main(int ac, char **av)
{
	int		arg;
	struct	Stack	*stack_a;
	struct	Stack	*stack_b;

	arg = ac;
	stack_a = ft_createStack(ac - 1);
	stack_b = ft_createStack(ac - 1);
	if (ac > 1)
	{
		if (ft_checkin(av + 1) == 1 && !check_duplicates(av + 1))
		{
			while (--arg >= 0)
				push(stack_a, ft_atoi(av[arg]));
			if (ft_sorted(stack_a, stack_b) == 1)
			{
				ft_putendl("OK");
				exit(1);
			}
			else
			{
				// ft_putnbr(ft_sorted(stack_a, stack_b));
				while (ft_sorted(stack_a, stack_b) == 0){
					ft_matchcommand(ft_stdinput(), stack_a, stack_b);
					ft_putendl("WAT");
				}
			}
		}
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	return (0);
}
