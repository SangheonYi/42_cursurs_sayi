#include "gnl.h"
#include <stdio.h>

int main()
{
	char *line = 0;

	while (gnl(&line) > 0)
	{
		printf("gnldone\n");
		printf("=============%s\n",line);
		free(line);
	}

	return 0;
}
