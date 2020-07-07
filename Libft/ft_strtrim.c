/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:24:08 by sayi              #+#    #+#             */
/*   Updated: 2020/04/19 15:34:57 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			head;
	int			len;
	char		*result;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	head = 0;
	while (s1[head] && ft_strchr(set, s1[head]))
		head++;
	while (head < len && ft_strchr(set, s1[len - 1]))
		len--;
	if (!(result = ft_calloc(sizeof(char), len - head + 1)))
		return (0);
	ft_memmove(result, s1 + head, len - head);
	return (result);
}
