/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cont_total_len_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 16:56:18 by sayi              #+#    #+#             */
/*   Updated: 2020/04/19 22:23:50 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cont_total_len(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		if (!(lst->content))
			return (0);
		else
			len += ft_strlen(lst->content);
		lst = lst->next;
	}
	return (len);
}
