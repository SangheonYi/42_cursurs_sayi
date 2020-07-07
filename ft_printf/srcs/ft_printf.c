/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:35:10 by sayi              #+#    #+#             */
/*   Updated: 2020/05/18 17:22:34 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_pf	*pf_v;
	va_list	va_ptr;
	int		cnt;

	if (!(pf_v = ft_calloc(sizeof(t_pf), 1)))
		return (0);
	pf_v->ox[0] = '0';
	pf_v->ox[1] = 'x';
	pf_v->prec = -1;
	pf_v->form = (char *)format;
	va_start(va_ptr, format);
	cnt = ft_vprintf(pf_v, va_ptr);
	ft_putstr_fd(pf_v->res, 1);
	va_end(va_ptr);
	if (pf_v)
		free(pf_v);
	return (cnt);
}
