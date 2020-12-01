#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
	int fd1;
	int i;
	(void)ac;

	i = 0;
	fd1 = open(av[1], O_RDONLY);
	while (get_next_line(fd1, &line) == 1)
	{
		i++;
		printf("[%d] %s\n", i, line);
		free(line);
	}
	return (0);
}
