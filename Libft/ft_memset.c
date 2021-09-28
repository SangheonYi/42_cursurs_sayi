/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:22:35 by sayi              #+#    #+#             */
/*   Updated: 2020/04/14 12:22:35 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	val;
	unsigned char	*str;
	size_t			i;

	str = (unsigned char*)s;
	val = c;
	i = 0;
	while (i < n)
	{
		str[i] = val;
		i++;
	}
	return (s);
}
