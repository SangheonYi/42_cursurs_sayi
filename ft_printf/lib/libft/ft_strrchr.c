/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:12:41 by sayi              #+#    #+#             */
/*   Updated: 2020/04/14 12:12:41 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*ptr;

	ptr = (char*)s + ft_strlen(s);
	chr = (char)c;
	while (ptr != s && *ptr != chr)
		ptr--;
	if (*ptr != chr)
		return (0);
	return (ptr);
}
