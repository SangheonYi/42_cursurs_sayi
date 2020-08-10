/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 11:46:23 by sayi              #+#    #+#             */
/*   Updated: 2020/04/24 13:51:44 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*nb_array;
	long	unit;
	long	num;
	int		i;

	num = (long)n;
	unit = ft_nfigure_base(num, 10);
	if (!(nb_array = ft_calloc(sizeof(char), unit + 1 + (n < 0))))
		return (0);
	unit = ft_ipow(10, unit - 1);
	i = -1;
	if (num < 0 && (num = -num))
		nb_array[++i] = '-';
	while (++i < 12 && unit)
	{
		nb_array[i] = (num / unit) + '0';
		num %= unit;
		unit /= 10;
	}
	return (nb_array);
}
