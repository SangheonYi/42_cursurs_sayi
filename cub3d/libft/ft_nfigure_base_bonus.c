/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nfigure_base_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 17:22:12 by sayi              #+#    #+#             */
/*   Updated: 2020/04/19 22:25:16 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nfigure_base(long long n, int base_size)
{
	int	i;

	i = 1;
	while (n / base_size)
	{
		n /= base_size;
		i++;
	}
	return (i);
}
