/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 19:05:11 by william           #+#    #+#             */
/*   Updated: 2018/07/06 19:22:50 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

signed long  ft_atol(const char *str)
{
    long  i;
    long  n;
    long  nev;

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
	if (ft_strcmp(ft_strtrim(str), "9223372036854775807") == 0)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = n * 10;
		n = n + ((long)str[i] - '0');
		i++;
	}
	return (n * nev);
}