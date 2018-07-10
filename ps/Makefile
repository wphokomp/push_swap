# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <wphokomp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 11:38:55 by wphokomp          #+#    #+#              #
#    Updated: 2018/07/10 16:04:57 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c sort_stack_a.c sort_stack_b.c ../push.c ../rotate.c ../swap.c

OBJ = ./*.o

LIB = ../libft/

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@gcc -c $(SRC)
	@gcc -g -o $(NAME) $(OBJ) $(LIB)libft.a
	@rm -fr $(OBJ)

clean:
	@rm -fr ./.*.swp
	@cd $(LIB) && $(MAKE) clean

fclean: clean
	@rm -fr $(NAME)
	@cd $(LIB) && $(MAKE) fclean

re: fclean all