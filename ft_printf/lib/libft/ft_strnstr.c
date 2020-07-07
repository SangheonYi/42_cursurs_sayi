/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 23:08:43 by sayi              #+#    #+#             */
/*   Updated: 2020/04/13 23:08:43 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	*hay;

	hay = (char *)haystack;
	needle_len = ft_strlen(needle);
	i = 0;
	if (!needle[i])
		return (hay);
	while (hay[i] && i < len && i + needle_len <= len)
	{
		if (ft_strncmp(&hay[i], needle, needle_len) == 0)
			return (&hay[i]);
		i++;
	}
	return (0);
}
