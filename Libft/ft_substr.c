/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:19:37 by sayi              #+#    #+#             */
/*   Updated: 2020/04/18 22:58:38 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	s_len;
	size_t	sub_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	sub_len = ft_strlen(s + start);
	sub_len = len < sub_len ? len : sub_len;
	if (!(subs = ft_calloc(sizeof(char), sub_len + 1)))
		return (0);
	i = 0;
	while (i < sub_len && start + i < s_len)
	{
		subs[i] = s[start + i];
		i++;
	}
	return (subs);
}
