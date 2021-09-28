/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 16:17:27 by sayi              #+#    #+#             */
/*   Updated: 2020/04/19 22:27:24 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstjoin(t_list *lst)
{
	char	*joined;
	char	*tmp;
	int		joined_len;
	int		i;

	joined = 0;
	joined_len = ft_cont_total_len(lst);
	if (!(joined = ft_calloc(sizeof(char), joined_len + 1)))
		return (0);
	i = 0;
	while (lst && (tmp = (char *)lst->content))
	{
		while (i < joined_len && *tmp)
			joined[i++] = *tmp++;
		lst = lst->next;
	}
	return (joined);
}
