/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:55:34 by sayi              #+#    #+#             */
/*   Updated: 2020/04/19 22:26:00 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*nb_array;
	long	unit;
	int		i;

	if (!(nb_array = (char *)ft_calloc(sizeof(char), 12)))
		return (0);
	unit = 1;
	while (n / (unit * 10))
		unit *= 10;
	i = 0;
	while (i < 12 && unit)
	{
		nb_array[i] = (n / unit) + '0';
		n = n % unit;
		unit /= 10;
		i++;
	}
	return (nb_array);
}
