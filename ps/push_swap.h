/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:47:08 by william           #+#    #+#             */
/*   Updated: 2018/07/08 00:52:42 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../checker.h"

void	run_commands(struct s_stack *stack_a, struct s_stack *stack_b);
int     is_sorted_asc(struct s_stack *stack);

#endif