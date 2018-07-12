/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 23:29:42 by william           #+#    #+#             */
/*   Updated: 2018/07/12 14:34:55 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_stdinput(int *i)
{
	char	c;
	char	*ret;
	char	*tmp;
	char	*tmp2;

	ret = ft_strnew(1);
	while ((*i = read(0, &c, 1)))
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
