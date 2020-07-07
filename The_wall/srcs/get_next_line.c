/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 20:27:53 by sayi              #+#    #+#             */
/*   Updated: 2020/06/19 16:49:41 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void	keep_free(int fd, char **keep)
{
	if (keep[fd])
		free(keep[fd]);
	keep[fd] = 0;
}

static void	ft_s1tos2(char **s1, char *s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = s2;
	free(tmp);
}

static int	reading(int fd, char **keep, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*new_line;
	int			bytes;

	while (!(new_line = ft_strchr(keep[fd], '\n'))
	&& (bytes = read(fd, buf, BUFFER_SIZE)) > 0
	&& !(buf[bytes] = 0))
		ft_s1tos2(&keep[fd], ft_strjoin(keep[fd], buf));
	if (new_line && !(*new_line = 0))
	{
		*line = ft_strjoin(keep[fd], 0);
		ft_s1tos2(&keep[fd], ft_strjoin(new_line + 1, 0));
		return (NEXT_LINE);
	}
	else if (!bytes && keep[fd] && *keep[fd])
		*line = ft_strjoin(keep[fd], 0);
	else
		*line = ft_strjoin("", 0);
	return (bytes);
}

int			get_next_line(int fd, char **line)
{
	static char	*keep[OPEN_MAX];
	int			bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	if ((bytes = reading(fd, keep, line)) > 0)
		return (NEXT_LINE);
	if (bytes < 0)
		return (ERROR);
	keep_free(fd, keep);
	return (END);
}
