/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 11:52:13 by sayi              #+#    #+#             */
/*   Updated: 2020/06/29 18:44:51 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_spec_char(t_pf *pf_v, va_list va_ptr)
{
	pf_v->prec = -1;
	if (!(pf_v->res = ft_calloc(sizeof(char), 2)))
		return (0);
	*pf_v->res = (char)va_arg(va_ptr, int);
	pf_v->len_r = 1;
	return (1);
}

static int	ft_spec_str(t_pf *pf_v, va_list va_ptr)
{
	int	size;

	if (!(pf_v->tmp_cp = va_arg(va_ptr, char *)))
		pf_v->tmp_cp = "(null)";
	size = ft_strlen(pf_v->tmp_cp);
	if (size > pf_v->prec && pf_v->prec >= 0)
		size = pf_v->prec;
	if (!(pf_v->res = ft_calloc(sizeof(char), size + 1)))
		return (0);
	ft_memcpy(pf_v->res, pf_v->tmp_cp, size);
	pf_v->prec = -1;
	return (1);
}

void		ft_pf_speci(t_pf *pf_v, va_list va_ptr)
{
	pf_v->spec = *pf_v->form;
	if (pf_v->spec == 'c')
		ft_spec_char(pf_v, va_ptr);
	else if (pf_v->spec == 's')
		ft_spec_str(pf_v, va_ptr);
	else if (pf_v->spec == 'd' || pf_v->spec == 'i' || pf_v->spec == 'u'
	|| pf_v->spec == 'x' || pf_v->spec == 'X' || pf_v->spec == 'p')
		ft_pf_num_conv(pf_v, va_ptr, pf_v->spec);
	else
	{
		pf_v->res = ft_calloc(sizeof(char), 2);
		*pf_v->res = *pf_v->form;
		pf_v->prec = -1;
	}
	if (pf_v->spec != 'd' && pf_v->spec != 'i')
		pf_v->sign = 0;
	pf_v->form++;
}
