/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:39:44 by sayi              #+#    #+#             */
/*   Updated: 2020/04/20 14:13:24 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *res_tmp;
	t_list *res;

	if (!lst || !f)
		return (0);
	res = 0;
	while (lst)
	{
		if (!(res_tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, res_tmp);
		lst = lst->next;
	}
	return (res);
}
