# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayi <sayi@student.kr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 23:28:01 by sayi              #+#    #+#              #
#    Updated: 2021/09/30 16:11:44 by sayi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC_PATH = ./srcs/
SRC_FILES = main.c solution.c util.c
SRC =  $(addprefix $(SRC_PATH), $(SRC_FILES))

O_PATH = ./obj/
O_NAME = $(SRC:.c=.o)
OFILES = $(subst $(SRC_PATH), $(O_PATH), $(O_NAME))

INC_LINK = -I./includes/
FLAGS =-Wall -Werror -Wextra

all:
	gcc  $(SRC) -I./includes
	./$(NAME)

mk_obj_dir:
	@mkdir -p $(O_PATH)

clean:
	rm -rf $(O_PATH)

fclean: clean
	rm -rf $(O_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re
