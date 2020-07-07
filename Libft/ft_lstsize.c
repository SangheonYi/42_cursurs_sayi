/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:12:45 by sayi              #+#    #+#             */
/*   Updated: 2020/04/19 16:48:09 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		return (0);
	size = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
