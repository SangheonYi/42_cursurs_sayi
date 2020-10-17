#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int	cnt;

	cnt = 0;
	while (*s)
		cnt++;
	return (cnt);
}

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return 0;
	while (*s != c)
	{
		if (*s == '\0')
			return 0;
		s++;
	}
	return s;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return 0;
	i = 0;
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return ptr;
}

char	*ft_substr(char *s, unsigned start, int len)
{
	int		i;
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s) + len + 1))))
		return 0;
	i = 0;
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return ptr;
}

int		gnl3(char **line)
{
	static char *str;
	char	*tmp;
	char	*newl;
	char	buf[1024];
	int		rbit;

	rbit = 1;
	while ((newl = ft_strchr(str, '\n')) == NULL
	&& rbit != 0)
	{
		if ((rbit = read(0, buf, 1024)) == -1)
			return -1;
		if (str == NULL)
			tmp = ft_substr(buf, 0, ft_strlen(buf));
		else
			tmp = ft_strjoin(str, buf);
		if (str != NULL)
			free(str);
		str = tmp;
	}
	if (newl != NULL)
	{
		tmp = str;
		*line = ft_substr(str, 0, newl - str);
		str = ft_substr(newl + 1, 0, ft_strlen(newl + 1));
		free(tmp);
		return 1;
	}
	*line = str;
	str = NULL;
	return 0;
}
