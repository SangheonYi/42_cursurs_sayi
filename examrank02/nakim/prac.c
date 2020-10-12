// #include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

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
		if (*str == NULL)
			return (0);
		str++;
	}
	return (str);
}

int main() {

	printf("%s\n", ft_strchr("abcde", 'c'));
}
