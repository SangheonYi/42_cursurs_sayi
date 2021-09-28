/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:03:38 by sayi              #+#    #+#             */
/*   Updated: 2020/04/24 13:53:19 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_swap(void *a, void *b, size_t s)
{
	void	*tmp;

	if (!(tmp = malloc(s)))
		return (0);
	ft_memcpy(tmp, a, s);
	ft_memcpy(a, b, s);
	ft_memcpy(b, tmp, s);
	free(tmp);
	tmp = 0;
	return (1);
}
