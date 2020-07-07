# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayi <sayi@student.kr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 23:28:01 by sayi              #+#    #+#              #
#    Updated: 2020/06/24 17:53:37 by sayi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = twc

SRC_PATH = ./srcs/
SRC_FILES = get_next_line.c twcomp.c check_syntax.c nights_watch.c samwell_tarly.c
SRC =  $(addprefix $(SRC_PATH), $(SRC_FILES))

O_PATH = ./obj/
O_NAME = $(SRC:.c=.o)
OFILES = $(subst $(SRC_PATH), $(O_PATH), $(O_NAME))

INC_LINK = -I./includes/
LIBFT_PATH = ./lib/libft/
LIBFT = -L$(LIBFT_PATH) -lft
LIBFTPRINTF = -L. -lftprintf
FLAGS =-Wall -Werror -Wextra
AR_COMMAND = ar rcs

all:mk_obj_dir $(NAME)

$(NAME): $(OFILES)
	gcc $(OFILES) -o $(NAME) -L ./lib -lft
	./$(NAME) winter_oath

$(O_PATH)%.o: $(SRC_PATH)%.c
	gcc $(FLAGS) $(INC_LINK) -o $@ -c $<

mk_obj_dir:
	@mkdir -p $(O_PATH)

clean:
	rm -rf $(O_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re
