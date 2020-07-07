# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayi <sayi@student.kr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 23:28:01 by sayi              #+#    #+#              #
#    Updated: 2020/05/04 23:17:54 by sayi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha\
ft_isascii ft_isdigit ft_isprint ft_itoa ft_memccpy ft_memchr ft_memcmp\
ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd\
ft_putstr_fd ft_split ft_strchr ft_strdup ft_strjoin\
ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr\
ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper\
ft_abs_bonus ft_asc_init_bonus ft_cont_total_len_bonus ft_ipow_bonus ft_nfigure_base_bonus\
ft_swap_bonus ft_uitoa_bonus ft_lstjoin_bonus ft_rev_bonus ft_ntobase_bonus ft_memrcpy\

BONUS_SRCS = ft_lstadd_back ft_lstadd_front\
ft_lstclear ft_lstdelone ft_lstiter\
ft_lstlast ft_lstmap ft_lstnew ft_lstsize\

OFILES = $(SRCS:%=%.o)
BONUS_OFILES = $(BONUS_SRCS:%=%.o)
FLAGS = -Wall -Werror -Wextra

AR_COMMAND = ar rsv

all: $(NAME)

$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	gcc -I./ -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OFILES) $(BONUS_OFILES)

fclean: clean
	rm -f $(NAME)
	rm -f libft.so

re: fclean all

bonus: $(OFILES) $(BONUS_OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES) $(BONUS_OFILES)

so: $(NAME) $(OFILES)
	gcc -shared -o libft.so *.o
.PHONY:		all clean fclean re
