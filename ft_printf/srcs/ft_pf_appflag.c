/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_appflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:54:40 by sayi              #+#    #+#             */
/*   Updated: 2020/05/19 16:11:12 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pf_pad(t_pf *pf_v, int c, int n)
{
	while (n-- > 0)
		*pf_v->tmp_cp++ = c;
}

static void	ft_pf_app(t_pf *pf_v)
{
	int		siz;

	siz = pf_v->prec > pf_v->len_r ? pf_v->prec : pf_v->len_r;
	siz += pf_v->len_p;
	if (!pf_v->pad && !pf_v->left)
		ft_pf_pad(pf_v, ' ', pf_v->width - siz);
	if (pf_v->sign)
		*pf_v->tmp_cp++ = pf_v->sign;
	else if (pf_v->hex_pre)
	{
		*pf_v->tmp_cp++ = pf_v->ox[0];
		*pf_v->tmp_cp++ = pf_v->ox[1];
	}
	if (pf_v->pad && !pf_v->left)
		ft_pf_pad(pf_v, '0', pf_v->width - siz);
	ft_pf_pad(pf_v, '0', pf_v->prec - pf_v->len_r);
	ft_memcpy(pf_v->tmp_cp, pf_v->res, pf_v->len_r);
	pf_v->tmp_cp += pf_v->len_r;
	if (pf_v->left)
		ft_pf_pad(pf_v, ' ', pf_v->width - siz);
}

static char	*app_alloc(t_pf *pf_v, int l_p, int l_r)
{
	int	tmp;

	pf_v->strlen = l_p + l_r;
	pf_v->tmp_cp = 0;
	if (pf_v->prec > l_r || l_p ||
	(pf_v->width > pf_v->strlen && pf_v->width > pf_v->prec))
	{
		tmp = pf_v->width > pf_v->prec + l_p ? pf_v->width : pf_v->prec + l_p;
		pf_v->strlen = tmp > pf_v->strlen ? tmp : pf_v->strlen;
		pf_v->tmp_cp = ft_calloc(sizeof(char), pf_v->strlen + 1);
	}
	return (pf_v->tmp_cp);
}

int			ft_pf_appflag(t_pf *pf_v)
{
	char	*buf;

	if (pf_v->res && *pf_v->res)
		pf_v->len_r = ft_strlen(pf_v->res);
	if (!(buf = app_alloc(pf_v, pf_v->len_p, pf_v->len_r)))
		return (0);
	ft_pf_app(pf_v);
	if (pf_v->res)
		free(pf_v->res);
	pf_v->res = buf;
	return (1);
}
