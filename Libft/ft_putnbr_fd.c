/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:58:31 by sayi              #+#    #+#             */
/*   Updated: 2020/04/24 13:52:17 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	unit;
	long	num;
	int		i;

	num = (long)n;
	unit = ft_nfigure_base(num, 10);
	if (num < 0 && (num = -num))
		ft_putchar_fd('-', fd);
	unit = ft_ipow(10, unit - 1);
	i = -1;
	while (++i < 12 && unit)
	{
		ft_putchar_fd((num / unit) + '0', fd);
		num %= unit;
		unit /= 10;
	}
}
