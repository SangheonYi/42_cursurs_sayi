/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:13:26 by sayi              #+#    #+#             */
/*   Updated: 2020/06/14 10:07:57 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;
	int		len;

	if (!(len = 0) && s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	if (!(s1 || s2) || !(joined = malloc(
	sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		joined[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	return (joined);
}
