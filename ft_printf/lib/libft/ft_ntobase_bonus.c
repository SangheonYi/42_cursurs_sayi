/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntobase_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:07:48 by sayi              #+#    #+#             */
/*   Updated: 2020/05/13 18:14:54 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			to_base(char *base, long digit, char *result)
{
	int index;

	index = (int)digit;
	*result = base[index];
}

static unsigned int	is_base(char *base)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] < ' ' || base[i] > '~' || base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i > 1)
		return (i);
	else
		return (0);
}

char				*ft_lltobase(long long nbr, char *base)
{
	unsigned int	base_len;
	char			*result;
	long long		unit;
	int				i;
	int				unit_cnt;

	if (!(base_len = is_base(base)))
		return (0);
	unit_cnt = ft_nfigure_base(nbr, base_len);
	unit = ft_ipow(base_len, unit_cnt - 1);
	if (!(result = ft_calloc(sizeof(char), unit_cnt + 2)))
		return (0);
	i = 0;
	while (i < unit_cnt + 2 && unit && base_len)
	{
		to_base(base, nbr / unit, &result[i]);
		nbr %= unit;
		unit /= base_len;
		i++;
	}
	return (result);
}

char				*ft_uitobase(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	char			*result;
	long long		unit;
	int				i;
	int				unit_cnt;

	if (!(base_len = is_base(base)))
		return (0);
	unit_cnt = ft_nfigure_base(nbr, base_len);
	unit = ft_ipow(base_len, unit_cnt - 1);
	if (!(result = ft_calloc(sizeof(char), unit_cnt + 1)))
		return (0);
	i = 0;
	while (i < unit_cnt + 1 && unit && base_len)
	{
		to_base(base, nbr / unit, &result[i]);
		nbr %= unit;
		unit /= base_len;
		i++;
	}
	return (result);
}
