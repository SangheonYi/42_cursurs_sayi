#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str != c)
	{
		if (!*str)
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
	if (!ptr)
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
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (idx < len)
		ptr[idx++] = str[start++];
	ptr[idx] = '\0';
	return (ptr);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		idx;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (0);
	while (*str)
		ptr[idx++] = *str++;
	ptr[idx] = '\0';
	return (ptr);
}

int		get_next_line(char **line)
{
	static char *str;
	char	buf[1024];
	char	*temp;
	char	*tp;
	int		nread;

	nread = 1;
	while (((tp = ft_strchr(str, '\n')) == NULL) && nread != 0)
	{
		if ((nread = read(0, buf, 1024)) == -1)
			return (-1);
		buf[nread] = '\0';
		if (str == NULL)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(str, buf);
		if (str != NULL)
			free(str);
		str = temp;
	}
	if (tp != NULL)
	{
		temp = str;
		*line = ft_substr(str, 0, tp - str);
		str = ft_strdup(tp + 1);
		free(temp);
		return (1);
	}
	*line = str;
	str = NULL;
	return (0);
}
