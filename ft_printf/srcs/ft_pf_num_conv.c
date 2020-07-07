/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_num_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 14:42:05 by sayi              #+#    #+#             */
/*   Updated: 2020/05/19 21:09:31 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ah ha
*/

static char			*ft_pf_toa(unsigned long ul, int base_len, char *base)
{
	char	buf[20];
	int		i;

	if (!ul)
		return (ft_strdup("0"));
	ft_bzero(buf, 20);
	i = 19;
	if (base_len == 10)
	{
		while (ul && --i >= 0)
		{
			buf[i] = (ul % 10) + '0';
			ul /= 10;
		}
	}
	else if (base_len == 16)
	{
		while (ul && --i >= 0)
		{
			buf[i] = base[ul & 15];
			ul >>= 4;
		}
	}
	return (ft_strdup(buf + i));
}

static void			ft_pf_conv(unsigned long tmp, char speci, t_pf *pf_v)
{
	char		*base;

	base = 0;
	if (speci == 'u' || speci == 'd' || speci == 'i')
		base = DECI;
	else if (speci == 'x' || speci == 'p')
		base = HEX_L;
	else if (speci == 'X')
		base = HEX_U;
	if (tmp != 0 || pf_v->prec != 0)
		pf_v->res = ft_pf_toa(tmp, ft_strlen(base), base);
}

static long long	ft_pf_hex(char speci, t_pf *pf_v, va_list va_ptr)
{
	long long	tmp;

	tmp = 0;
	if (speci == 'x' || speci == 'X')
	{
		tmp = va_arg(va_ptr, unsigned int);
		if (pf_v->ox[1] == '#' && tmp)
		{
			pf_v->ox[1] = speci;
			pf_v->len_p = 2;
			pf_v->hex_pre = 1;
		}
	}
	else if (speci == 'p' && (pf_v->hex_pre = 1))
	{
		tmp = (unsigned long)va_arg(va_ptr, void *);
		pf_v->len_p = 2;
		pf_v->ox[1] = 'x';
	}
	return (tmp);
}

void				ft_pf_num_conv(t_pf *pf_v, va_list va_ptr, char speci)
{
	long long	tmp;

	if (pf_v->prec >= 0 && !(tmp = 0))
		pf_v->pad = 0;
	if (speci == 'd' || speci == 'i')
	{
		if ((tmp = va_arg(va_ptr, int)) < 0)
		{
			tmp = -tmp;
			pf_v->sign = '-';
		}
		if (pf_v->sign)
			pf_v->len_p++;
	}
	else if (speci == 'u')
		tmp = va_arg(va_ptr, unsigned int);
	else
		tmp = ft_pf_hex(speci, pf_v, va_ptr);
	ft_pf_conv(tmp, speci, pf_v);
}
