/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:32:53 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/23 15:23:15 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "./lib/libft.h"

void	ft_sa(char **stack_a);
void	ft_sb(char **stack_b);
void	ft_ss(char **stack_a, char **stack_b);
void	ft_rr(char **stack_a, char **stack_b);
void	ft_rrr(char **stack_a, char **stack_b);

char	**ft_pa_a(char **stack_a, char *b);
char	**ft_pa_b(char **stack_b);
char	**ft_pb_b(char **stack_a, char **stack_b);
char	**ft_pb_a(char **stack_a);
char	**ft_ra(char **stack_a);
char	**ft_rb(char **stack_b);
char	**ft_rra(char **stack_a);
char	**ft_rrb(char **stack_b);

#endif
