/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 11:14:02 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/07 12:25:27 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_intcmp(int *cpy, int *actual, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if (cpy[i] != actual[i])
			return (0);
	}
	return (1);
}

void	ft_sortint_arr(int *arr, int len)
{
	int		i;
	int		j;
	int		counter = 0;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (arr[j] > arr[j + 1]){
				ft_swap(&arr[j], &arr[j + 1]);
				if (i == 0)
					counter++;
			}
		}
	}
	ft_putnbr(counter);
}
