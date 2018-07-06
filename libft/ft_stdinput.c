/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 23:29:42 by william           #+#    #+#             */
/*   Updated: 2018/07/06 23:30:11 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stdinput(void)
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
