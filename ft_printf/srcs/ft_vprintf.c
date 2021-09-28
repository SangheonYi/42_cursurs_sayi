/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:18:33 by sayi              #+#    #+#             */
/*   Updated: 2020/05/19 16:41:10 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_vinit(t_pf *pf_v)
{
	pf_v->pad = 0;
	pf_v->left = 0;
	pf_v->tmp_cp = 0;
	pf_v->strlen = 0;
	pf_v->res = 0;
	pf_v->len_p = 0;
	pf_v->len_r = 0;
	pf_v->sign = 0;
	pf_v->prec = -1;
	pf_v->width = 0;
	pf_v->ox[1] = 'x';
}

static void	ft_pf_put(t_pf *pf_v)
{
	write(1, pf_v->res, pf_v->strlen);
	free(pf_v->res);
	pf_v->cnt += pf_v->strlen;
}

int			ft_vprintf(t_pf *pf_v, va_list ap)
{
	char	chr;
	char	*cp;

	while (1)
	{
		cp = pf_v->form;
		while ((chr = *pf_v->form) != '%' && chr != '\0')
			pf_v->form++;
		if ((pf_v->strlen = pf_v->form - cp) != 0)
			write(1, cp, pf_v->strlen);
		pf_v->cnt += pf_v->strlen;
		if (chr == '\0')
			break ;
		pf_v->form++;
		ft_pf_pars(pf_v, ap);
		ft_pf_speci(pf_v, ap);
		ft_pf_appflag(pf_v);
		if (pf_v->res)
			ft_pf_put(pf_v);
		ft_pf_vinit(pf_v);
	}
	return (pf_v->cnt);
}
