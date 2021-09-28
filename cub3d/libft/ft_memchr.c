/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:20:49 by sayi              #+#    #+#             */
/*   Updated: 2020/04/14 12:20:49 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	to_find;

	to_find = (unsigned char)c;
	ptr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == to_find)
			return (ptr + i);
		i++;
	}
	return (0);
}
