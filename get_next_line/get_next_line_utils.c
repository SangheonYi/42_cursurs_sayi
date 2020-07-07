/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 20:21:09 by sayi              #+#    #+#             */
/*   Updated: 2020/06/15 17:50:38 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

char	*ft_strchr(char *s, int c)
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

char	*ft_strjoin(char *s1, char *s2)
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

void	ft_s1tos2(char **s1, char *s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = s2;
	free(tmp);
}
