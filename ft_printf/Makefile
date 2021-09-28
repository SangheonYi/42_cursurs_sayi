# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayi <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 23:28:01 by sayi              #+#    #+#              #
#    Updated: 2020/06/29 19:24:46 by sayi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = ./srcs/
SRC_FILES = ft_printf.c ft_pf_par.c ft_pf_spec.c\
ft_vprintf.c ft_pf_appflag.c ft_pf_num_conv.c
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

all: libft mk_obj_dir $(NAME)

test_mk:
	gcc srcs/test2.c libftprintf.a -I./includes
	./a.out
$(NAME): $(OFILES)
	cp $(LIBFT_PATH)libft.a $(NAME)
	$(AR_COMMAND) $(NAME) $(OFILES)

$(O_PATH)%.o: $(SRC_PATH)%.c
	gcc $(FLAGS) $(INC_LINK) -o $@ -c $<

mk_obj_dir:
	@mkdir -p $(O_PATH)

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
