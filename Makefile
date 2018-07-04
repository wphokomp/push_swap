# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/04 15:38:36 by wphokomp          #+#    #+#              #
#    Updated: 2018/07/04 15:51:46 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = checker.c ft_cmds.c

OBJ = $(patsubst %.c,%.o, $(SRC))

LIB = ./libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@gcc -c $(FLAGS) $(SRC)
	@gcc -g -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@rm -fr $(OBJ)

clean:
	@rm -fr ./.*.swp
	@cd $(LIB) && $(MAKE) clean

fclean: clean
	@rm -fr $(NAME)
	@cd $(LIB) && $(MAKE) fclean

re: fclean all
