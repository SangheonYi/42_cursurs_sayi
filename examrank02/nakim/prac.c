#include "gnl.h"

int	ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*str++)
		count++;
	return count;
}

char	*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	char	*ptr;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (0);
	while (*s1)
		ptr[idx++] = *s1++;
	while (*s2)
		ptr[idx++] = *s2++;
	ptr[idx] = '\0';
	return (ptr);
}

char	*ft_substr(char *str, unsigned start, int len)
{
	char	*ptr;
	int		idx;

	idx = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (0);
	while (idx < len)
		ptr[idx++] = str[start++];
	ptr[idx] = '\0';
	return (ptr);
}

int		gnl(char **line)
{
	static char	*str;
	char	*line_ptr;
	char	*tmp;
	char	buf[1024];
	int		readnum;

	readnum = 1;
	while ((line_ptr = ft_strchr(str, '\n')) == NULL
	&& readnum != 0)
	{
		if ((readnum = read(0, buf, 1024)) == -1)
			return (-1);
		buf[readnum] = '\0';
		if (str == NULL)
			tmp = ft_substr(buf, 0, ft_strlen(buf));
		else
			tmp = ft_strjoin(str, buf);
		if (str != NULL)
			free(str);
		str = tmp;
	}
	if (line_ptr != NULL)
	{
		tmp = str;
		*line = ft_substr(str, 0, str - line_ptr);
		str = ft_substr(line_ptr, 0, ft_strlen(line_ptr));
		free(tmp);
		return (1);
	}
	*line = str;
	str = NULL;
	return (0);
}
