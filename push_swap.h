/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:32:53 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/07 11:22:55 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void	swap_a(struct s_stack *stack_a);
void	swap_b(struct s_stack *stack_b);
void	swap_ab(struct s_stack* stack_a, struct s_stack* stack_b);

void    rotate_a(struct s_stack* stack_a);
void    rotate_b(struct s_stack* stack);
void    rotate_ab(struct s_stack* stack_a, struct s_stack* stack_b);
void    rev_rotate_a(struct s_stack* stack);
void    rev_rotate_b(struct s_stack* stack);
void    rev_rotate_ab(struct s_stack* stack_a, struct s_stack* stack_b);

void    push_a(struct s_stack* stack_a, struct s_stack* stack_b);
void    push_b(struct s_stack* stack_a, struct s_stack* stack_b);

void	ft_sortint_arr(int *arr, int len);

int		ft_intcmp(int *cpy, int *actual, int len);

#endif
