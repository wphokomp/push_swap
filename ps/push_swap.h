/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:47:08 by william           #+#    #+#             */
/*   Updated: 2018/07/09 14:28:38 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../checker.h"

void	run_commands(struct s_stack *stack_a, struct s_stack *stack_b);
int     is_sorted_asc(struct s_stack *stack);
int     is_sorted_desc(struct s_stack *stack);

#endif