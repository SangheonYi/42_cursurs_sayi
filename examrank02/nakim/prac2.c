#include "prac2.h"

int ft_strlen(char *s)
{
	int cnt = 0;

	while (*s++)
		cnt++;
	return cnt;
}

char *ft_strchr(char *s, int c)
{
	if (s == NULL)
		return 0;
	while (*s != c)
	{
		if (*s == 0)
			return 0;
		s++;
	}
	return s;
}

char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	char *p;

	if (!(p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)));
		return 0;
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = 0;
	return p;
}

char *ft_substr(char *s, int start ,int len)
{
	int i = 0;
	char *p;

	if (!s)
		return 0;
	if (!(p = malloc(len + 1)));
		return 0;
	while (i < len)
		p[i++] = s[start++];
	p[i] = 0;
	return p;
}

int prac2(char **line)
{
	static char str;
	char	*tmp;
	char	*newl;
	char	buf[1024];
	int		nbit;

	nbit = 1;
	while ((newl = ft_strchr(str, '\n')) == NULL
	&& nbit != 0)
	{
		if ((nbit = read(0, buf, 1024)) == -1)
			return -1;
		buf[nbit] = '\0';
		if (!str == NULL)
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
	str = 0;
	return 0;
}
