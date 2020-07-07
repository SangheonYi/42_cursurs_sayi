/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:32:04 by sayi              #+#    #+#             */
/*   Updated: 2020/04/20 20:16:11 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ret_ele(char **ret, char const *s, char c)
{
	int		i;
	int		c_idx;
	int		cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			c_idx = 0;
			while ((s + i)[c_idx] && (s + i)[c_idx] != c)
				c_idx++;
			if (!(ret[cnt] = ft_calloc(sizeof(char), c_idx + 1)))
				return (0);
			ft_memmove(ret[cnt], s + i, c_idx);
			cnt++;
			i += c_idx;
			continue ;
		}
		i++;
	}
	return (1);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;

	if (!s || !(ret = (char **)ft_calloc(sizeof(char *), ft_strlen(s) + 1)))
		return (0);
	if (ft_ret_ele(ret, s, c))
		return (ret);
	else
	{
		i = 0;
		while (ret[i])
		{
			free(ret[i]);
			ret[i++] = 0;
		}
		if (ret)
		{
			free(ret);
			ret = 0;
		}
		return (0);
	}
}
