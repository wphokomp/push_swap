# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: william <william@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 15:38:36 by wphokomp          #+#    #+#              #
#    Updated: 2018/07/13 07:01:25 by william          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = checker.c swap.c push.c rotate.c check.c ps/sort_stack_a.c

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
