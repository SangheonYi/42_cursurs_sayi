/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 23:42:45 by sayi              #+#    #+#             */
/*   Updated: 2020/06/14 10:10:15 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;
	char	*ptr;

	if (!s)
		return (0);
	i = 0;
	ptr = (char*)s;
	chr = (char)c;
	while (ptr[i] && ptr[i] != chr)
		i++;
	if (ptr[i] != chr)
		return (0);
	return (&ptr[i]);
}
