# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 23:28:01 by sayi              #+#    #+#              #
#    Updated: 2020/08/10 19:16:46 by sayi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_PATH = ./srcs/
SRC_FILES = ft_printf.c ft_pf_par.c ft_pf_spec.c\
ft_vprintf.c ft_pf_appflag.c ft_pf_num_conv.c
SRC =  $(addprefix $(SRC_PATH), $(SRC_FILES))

O_PATH = ./obj/
O_NAME = $(SRC:.c=.o)
OFILES = $(subst $(SRC_PATH), $(O_PATH), $(O_NAME))

INC_LINK = -I./includes/
LIBFT_PATH = ./libft/
LIBFT = -L$(LIBFT_PATH) -lft
MLX		= libmlx.dylib

all: libft mk_obj_dir $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(O_PATH)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -rf $(O_PATH)
	rm -rf $(NAME)

re: fclean all

libft :
	$(MAKE) -C $(LIBFT_PATH) bonus

.PHONY:		all clean fclean re
