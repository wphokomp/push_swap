/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 19:05:11 by william           #+#    #+#             */
/*   Updated: 2018/07/13 11:04:03 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

signed long	ft_atol(const char *str)
{
	long	i;
	long	n;
	long	nev;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	nev = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nev = -1;
		i++;
	}
	n = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		n = n * 10;
		n = n + ((long)str[i] - '0');
		i++;
	}
	return (n * nev);
}
