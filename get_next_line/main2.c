
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{

	int fd;
	int ret;
	char *line;

	fd = open("test_line.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	//ret = 1;
	line = 0;
	while (get_next_line(fd, &line))
	{
		if (line)
		{
			printf("[%s]\n", line);
			free(line);
			line = 0;
		}
	}
	printf("[%s]\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("[%s]\n", line);
	free(line);

	close(fd);
return(1);
}
