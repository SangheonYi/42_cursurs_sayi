#include "gnl.h"

void	ft_s1tos2(char **s1, char *s2)
{
	char	*tmp;

	tmp = *s1;
	printf("s1:%s s2: %s\n", *s1, s2);
	*s1 = s2;
	if (tmp)
	{
		printf("ft_s1tos2 tmp: %s\n", tmp);
		free(tmp);
	}
}

int		ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char c, char *s)
{
	int i = -1;

	if (!s)
		return (0);
	while (s[++i])
	{
		if(s[i] == c)
			return (s + i);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i = -1;
	int j = -1;
	int len = 0;
	char	*joined;

	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	// printf("ft_strjoin len: %d\n", len);
	if (!(s1 || s2) || !(joined = malloc(len + 1)))
		return (0);
	while (s1 && s1[++i])
		joined[++j] = s1[i];
	// printf("ft_strjoin s1: done\n");
	i = -1;
	while (s2 && s2[++i])
		joined[++j] = s2[i];
	joined[++j] = 0;
	// printf("ft_strjoin joined\n");
	return (joined);
}

int		gnl(char **line)
{
	static char	*log;
	char		buf[1024];
	char		*new_line = 0;
	int			bytes = 0;

	if (!line)
		return (-1);
	while (!(new_line = ft_strchr('\n', log))
	&& (bytes = read(0, buf, 1024)) > 0)
	{
		buf[bytes] = 0;
		ft_s1tos2(&log, ft_strjoin(log, buf));
	}
	printf("readed\n");
	if (new_line)
	{
		*new_line = 0;
		*line = ft_strjoin(log, 0);
		// ft_s1tos2(&log, ft_strjoin(new_line + 1, 0));
		ft_s1tos2(&log, new_line + 1);
		printf("conti\n");
		return (1);
	}
	else if (log && *log && !bytes)
	{
		*line = ft_strjoin(log, 0);
		return (1);
	}
	else
		*line = ft_strjoin("", 0);
	printf("newline checked\n");
	if (bytes < 0)
		return (-1);
	if (log)
		free(log);
	log = 0;
	return (0);
}
