/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:48:08 by sayi              #+#    #+#             */
/*   Updated: 2020/05/18 17:33:59 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_pf
{
	char	*res;
	char	*form;
	char	*tmp_cp;
	int		strlen;

	char	pad;
	char	left;
	char	sign;
	char	hex_pre;
	char	ox[2];

	char	spec;
	int		width;
	int		prec;

	int		len_r;
	int		len_p;
	int		cnt;
}				t_pf;

int				ft_printf(const char *format, ...);
int				ft_vprintf(t_pf *pf_val, va_list ap);
void			ft_pf_pars(t_pf *pf_val, va_list va_ptr);
int				ft_pf_appflag(t_pf *pf_val);
void			ft_pf_speci(t_pf *pf_val, va_list va_ptr);
void			ft_pf_num_conv(t_pf *pf_val, va_list va_ptr, char speci);

#endif
