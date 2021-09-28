/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 17:19:20 by sayi              #+#    #+#             */
/*   Updated: 2020/06/14 14:43:35 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 20
# endif

# define ERROR -1
# define END 0
# define NEXT_LINE 1
# define GET_MORE 2

typedef struct	s_gnl
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	char	*new_line;
	char	*head;

	int		fd;
	int		bytes;
	int		ret;
	int		keep_ret;
}				t_gnl;

int				get_next_line(int fd, char **line);
char			*ft_strchr(char *s, int c);
size_t			ft_strlen(char *c);
char			*ft_strjoin(char *s1, char *s2);
void			ft_s1tos2(char **s1, char *s2);

#endif
