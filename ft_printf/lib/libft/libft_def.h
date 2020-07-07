/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 22:20:59 by sayi              #+#    #+#             */
/*   Updated: 2020/04/24 14:36:15 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DEF_H
# define LIBFT_DEF_H
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# define DECI				"0123456789"
# define HEX_L				"0123456789abcdef"
# define HEX_U				"0123456789ABCDEF"

typedef struct				s_list
{
	void			*content;
	struct s_list	*next;
}							t_list;

#endif
