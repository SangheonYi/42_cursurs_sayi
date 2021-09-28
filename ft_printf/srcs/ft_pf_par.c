/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_par.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:44:13 by sayi              #+#    #+#             */
/*   Updated: 2020/05/19 16:12:30 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_digitset(t_pf *pf_v, int *numb)
{
	*numb = ft_atoi(pf_v->form);
	pf_v->form += ft_nfigure_base(*numb, 10);
}

static int	pf_pars_flag(t_pf *pf_v)
{
	if (*pf_v->form == '-' && pf_v->form++)
		pf_v->left = 1;
	else if (*pf_v->form == '0' && pf_v->form++)
		pf_v->pad = 1;
	else if (ft_isdigit(*pf_v->form))
		pf_digitset(pf_v, &pf_v->width);
	else if (*pf_v->form == ' ' && pf_v->form++)
	{
		if (!pf_v->sign)
			pf_v->sign = ' ';
	}
	else if (*pf_v->form == '+' && pf_v->form++)
		pf_v->sign = '+';
	else if (*pf_v->form == '#' && pf_v->form++)
		pf_v->ox[1] = '#';
	else
		return (0);
	return (1);
}

static void	pf_pars_prec(t_pf *pf_v, va_list va_ptr)
{
	pf_v->form++;
	if (*pf_v->form == '*' && pf_v->form++)
	{
		pf_v->prec = va_arg(va_ptr, int);
		return ;
	}
	pf_v->prec = 0;
	if (ft_isdigit(*pf_v->form))
		pf_digitset(pf_v, &pf_v->prec);
}

void		ft_pf_pars(t_pf *pf_v, va_list va_ptr)
{
	while (pf_v->form)
	{
		if (*pf_v->form == '*' && pf_v->form++
		&& (pf_v->width = va_arg(va_ptr, int)) <= 0)
		{
			pf_v->width = -pf_v->width;
			pf_v->left = 1;
		}
		else if (*pf_v->form == '.')
			pf_pars_prec(pf_v, va_ptr);
		else if (!pf_pars_flag(pf_v))
			break ;
	}
}
