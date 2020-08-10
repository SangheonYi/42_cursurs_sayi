/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipow_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 17:37:20 by sayi              #+#    #+#             */
/*   Updated: 2020/05/12 21:20:19 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_ipow(long long nb, long long power)
{
	long long	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power--)
		result *= nb;
	return (result);
}
