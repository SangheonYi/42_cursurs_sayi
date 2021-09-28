/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:03:36 by sayi              #+#    #+#             */
/*   Updated: 2020/04/19 16:46:42 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = 0;
	if (lst && (*lst) && new)
	{
		tmp = ft_lstlast(*lst);
		if (!tmp)
			return ;
		tmp->next = new;
	}
	else if (lst && !(*lst) && new)
		*lst = new;
}
