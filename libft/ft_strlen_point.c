/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:06:00 by wphokomp          #+#    #+#             */
/*   Updated: 2017/12/11 15:06:01 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_point(char **list)
{
	int i;

	if (list == NULL)
		return (0);
	i = 0;
	while (list[i])
		i++;
	return (i);
}
