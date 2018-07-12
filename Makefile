# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: william <william@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 15:38:36 by wphokomp          #+#    #+#              #
#    Updated: 2018/07/11 21:54:41 by william          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = checker.c swap.c push.c rotate.c check.c ps/sort_stack_a.c try_sort.c

OBJ = ./*.o

LIB = ./libft/

PS = ./ps/

FLAGS = -Wall -Werror -Wextra -Wno-unused-parameter

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@make -C $(PS)
	@gcc -c $(SRC) $(FLAGS)
	@gcc -g -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@rm -fr $(OBJ)

clean:
	@rm -fr ./.*.swp
	@rm -fr ./*.o
	@cd $(LIB) && $(MAKE) clean
	@cd $(PS) && $(MAKE) clean

fclean: clean
	@rm -fr $(NAME)
	@cd $(LIB) && $(MAKE) fclean
	@cd $(PS) && $(MAKE) fclean

re: fclean all
