/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asc_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 22:08:32 by sayi              #+#    #+#             */
/*   Updated: 2020/04/19 22:23:48 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_asc_init(int c, size_t size)
{
	size_t	i;
	char	*result;

	if (!(result = ft_calloc(sizeof(char), size)))
		return (0);
	i = -1;
	while (++i < size)
		result[i] = c + i;
	return (result);
}
