/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:31:50 by sayi              #+#    #+#             */
/*   Updated: 2020/05/11 14:08:15 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	size_t	dst_len;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	while (n-- && dst_len--)
		*((char *)dst + dst_len) = *((char *)src + n);
	return (dst);
}
