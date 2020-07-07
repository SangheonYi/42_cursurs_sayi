/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:57:15 by sayi              #+#    #+#             */
/*   Updated: 2020/04/24 13:52:44 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	tmp = 0;
	if (lst && del)
	{
		while ((tmp = *lst) != 0)
		{
			del((*lst)->content);
			*lst = (*lst)->next;
			free(tmp);
			tmp = 0;
		}
	}
	*lst = 0;
}
