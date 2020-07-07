/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:40:53 by sayi              #+#    #+#             */
/*   Updated: 2020/04/14 12:29:06 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	return_value;
	size_t	i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dst);
	return_value = ft_strlen(dst) + ft_strlen(src);
	if (dstsize && dest_len <= dstsize)
	{
		while (dest_len + i < dstsize - 1 && src[i])
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
	}
	if (dest_len > dstsize)
		return (dstsize + ft_strlen(src));
	else
		return (return_value);
}
