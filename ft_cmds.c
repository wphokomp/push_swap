/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 13:01:17 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/23 17:38:24 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void	ft_sa(char **a)
{
	char	*tmp;

	tmp = a[1];
	a[1] = a[0];
	a[0] = tmp;
}

void	ft_sb(char **b)
{
	char	*tmp;

	if (ft_strlen_point(b) == 1 || ft_strlen_point(b) == 0)
		return ;
	tmp = b[1];
	b[1] = b[0];
	b[0] = tmp;
}

void	ft_ss(char **a, char **b)
{
	if (!a || !b)
		return ;
	ft_sa(a);
	ft_sb(b);
}

char	**ft_pa_a(char **a, char *b)
{
	char	**new_a;
	size_t	len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (ft_strlen(b) < 1)
		return (a);
	len = ft_strlen_point(a);
	new_a = ft_strnew_point(ft_strlen_point(a) + 1);
	new_a[j] = b;
	while (a[++i])
	{
		new_a[++j] = ft_strnew(ft_strlen(a[i]));
		new_a[++j] = a[i];
	}
	return (new_a);
}

char	**ft_pa_b(char **b)
{
	char	**new_b;
	size_t	len_b;
	int		count;
	int		i;

	len_b = ft_strlen_point(b);
	if (len_b < 1)
		return (b);
	count = 0;
	i = 0;
	if (ft_strlen_point(b) == 0)
		return (b);
	new_b = ft_strnew_point(len_b - 1);
	while (++count < (len_b - 1))
	{
		new_b[i] = ft_strnew(ft_strlen(b[count]));
		new_b[i] = b[count];
		i++;
	}
	return (new_b);
}

//PB: Take 1st element of a and put it onto b

char	**ft_pb_b(char **a, char **b)
{
	char	**new_b;
	size_t	len_b;
	int		i;
	int		j;

	i = -1;
	j = 1;
	len_b = ft_strlen_point(b) + 1;
	if (ft_strlen_point(a) == 0)
		return (b);
	new_b = ft_strnew_point(len_b);
	ft_bzero_point((void **)new_b, len_b + 1);
	new_b[0] = a[0];
	if (!b)
		return (new_b);
	while (b[++i])
	{
		new_b[j] = b[i];
		j++;
	}
	return (new_b);
}

char	**ft_pb_a(char **a)
{
	char	**new_a;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = -1;
	len = ft_strlen_point(a) - 1;
	new_a = ft_strnew_point(len);
	ft_bzero_point((void **)new_a, ft_strlen_point(a));
	while (++i <= len)
		new_a[++j] = a[i];
	return (new_a);
}

//ra: Shift a UP

char	**ft_ra(char **a)
{
	char	**new_a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_a = ft_strnew_point(ft_strlen_point(a));
	ft_bzero(new_a, ft_strlen_point(a));
	while (a[++i])
	{
		new_a[j] = ft_strnew(ft_strlen(a[i]));
		new_a[j] = a[i];
		j++;
	}
	new_a[j] = a[0];
	return (new_a);
}

char	**ft_rb(char **b)
{
	char	**new_b;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_b = ft_strnew_point(ft_strlen_point(b));
	ft_bzero_point((void **)new_b, ft_strlen_point(b));
	while (b[++i])
	{
		new_b[j] = ft_strnew(ft_strlen(b[i]));
		new_b[j] = b[i];
		j++;
	}
	new_b[j] = b[0];
	return (new_b);
}

//Need to test
//Performs ra and rb at the same time

void	ft_rr(char **a, char **b)
{
	a = ft_ra(a);
	b = ft_rb(b);
}

char	**ft_rra(char **a)
{
	char	**new_a;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 1;
	len = ft_strlen_point(a);
	new_a = ft_strnew_point(len);
	ft_bzero_point((void **)new_a, len);
	new_a[0] = ft_strnew(ft_strlen(a[len - 1]));
	new_a[0] = a[len - 1];
	while (i < (len - 1))
	{
		new_a[j] = ft_strnew(ft_strlen(a[i]));
		ft_bzero(new_a[j], ft_strlen(a[i]));
		new_a[j] = a[i];
		i++;
		j++;
	}
	return (new_a);
}

char	**ft_rrb(char **b)
{
	char	**new_b;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 1;
	len = ft_strlen_point(b);
	new_b = ft_strnew_point(len);
	ft_bzero_point((void **)new_b, len);
	new_b[0] = ft_strnew(ft_strlen(b[len - 1]));
	new_b[0] = b[len - 1];
	while (i < (len - 1))
	{
		new_b[j] = ft_strnew(ft_strlen(b[i]));
		ft_bzero(new_b[j], ft_strlen(b[i]));
		new_b[j] = b[i];
		i++;
		j++;
	}
	return (new_b);
}

void	ft_rrr(char **a, char **b)
{
	a = ft_ra(a);
	b = ft_rb(b);
}

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
