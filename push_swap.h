/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:32:53 by wphokomp          #+#    #+#             */
/*   Updated: 2018/07/06 23:20:17 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

void	swap_a(struct Stack *stack_a);
void	swap_b(struct Stack *stack_b);
void	swap_ab(struct Stack* stack_a, struct Stack* stack_b);

void    rotate_a(struct Stack* stack_a);
void    rotate_b(struct Stack* stack);
void    rotate_ab(struct Stack* stack_a, struct Stack* stack_b);
void    rev_rotate_a(struct Stack* stack);
void    rev_rotate_b(struct Stack* stack);
void    rev_rotate_ab(struct Stack* stack_a, struct Stack* stack_b);

void    push_a(struct Stack* stack_a, struct Stack* stack_b);
void    push_b(struct Stack* stack_a, struct Stack* stack_b);


#endif
