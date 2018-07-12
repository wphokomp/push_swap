/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:37:02 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/11 21:47:08 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

void ft_matchcommand(char *c, struct s_stack *stack_a, struct s_stack *stack_b)
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
	else if (ft_strcmp(c, "^C"))
	{
		ft_putendl("OK");
		exit(1);
	}
	else
	{
		ft_putendl("Error");
		exit(0);
	}
}

int ft_checkin(char **stack)
{
	int i;
	int boo;
	size_t arg;

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
				break;
			}
		if (!boo)
			break;
	}
	if (arg == ft_strlen_point(stack))
		return (1);
	return (0);
}

int check_duplicates(char **list)
{
	int i;
	int o;

	i = -1;
	while (list[++i])
	{
		o = i;
		if (ft_atol(list[i]) > 2147483647 || (ft_atoi(list[i]) * -1) == (int)-2147483648)
		{
			return (1);
		}
		while ((size_t)o < ft_strlen_point(list) - 1)
		{
			o++;
			if (ft_strcmp(list[i], list[o]) == 0)
				return (1);
		}
	}
	return (0);
}
//pb, ra, pb, ra, sa, ra, pa, pa

void ft_sorted(struct s_stack *stack_a, struct s_stack *stack_b)
{
	int i;
	int *stack_a_cpy;

	if (!is_sorted_asc(stack_a))
	{
		ft_matchcommand(ft_stdinput(), stack_a, stack_b);
	}
	else
	{
		i = -1;
		stack_a_cpy = (int *)malloc(sizeof(int) * stack_a->capacity);
		while (!ft_isempty(stack_a))
			stack_a_cpy[++i] = ft_pop(stack_a);
		ft_pushall(stack_a, stack_a_cpy, stack_a->capacity);
		ft_sortint_arr(stack_a_cpy, stack_a->capacity);
	}
}

int main(int ac, char **av)
{
	int				arg;
	char			**args;
	struct s_stack *stack_a;
	struct s_stack *stack_b;

	if (ac > 1)
	{
		args = ft_strsplit(av[1], ' ');
		arg = ft_strlen_point(args);
		stack_a = ft_create_stack(arg);
		stack_b = ft_create_stack(arg);
		if (ft_checkin(args) == 1 && !check_duplicates(args))
		{
			while (--arg >= 0)
				ft_push(stack_a, ft_atoi(args[arg]));
			ft_matchcommand(ft_stdinput(), stack_a, stack_b);
			arg = is_sorted_asc(stack_a);
			while (!arg){
				ft_matchcommand(ft_stdinput(), stack_a, stack_b);
				arg = is_sorted_asc(stack_a);
				if (arg && !ft_isempty(stack_b))
					arg = 0;
			}
			if (arg)
				ft_putendl("OK");
		}
		else
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
	return (0);
}
