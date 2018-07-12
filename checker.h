/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:32:53 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/12 14:36:28 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/libft.h"
# include "ps/push_swap.h"

void	swap_a(struct s_stack *stack_a);
void	swap_b(struct s_stack *stack_b);
void	swap_ab(struct s_stack *stack_a, struct s_stack *stack_b);

void	rotate_a(struct s_stack *stack_a);
void	rotate_b(struct s_stack *stack);
void	rotate_ab(struct s_stack *stack_a, struct s_stack *stack_b);
void	rev_rotate_a(struct s_stack *stack);
void	rev_rotate_b(struct s_stack *stack);
void	rev_rotate_ab(struct s_stack *stack_a, struct s_stack *stack_b);

void	push_a(struct s_stack *stack_a, struct s_stack *stack_b);
void	push_b(struct s_stack *stack_a, struct s_stack *stack_b);

void	ft_sortint_arr(int *arr, int len);

void	sort_order(struct s_stack *stack, char *command);

void	ft_matchcommand(char *c, struct s_stack *stack_a
			, struct s_stack *stack_b, int i);
void	ft_sort(struct s_stack *stack_a, struct s_stack *stack_b);
void	check_b(struct s_stack *stack_a, struct s_stack *stack_b);

#endif
