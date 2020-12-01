#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
	char *line2;
	int fd1;
	int fd2;
	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	
	while (get_next_line(fd1, &line) == 1 && get_next_line(fd2, &line2) == 1)
	{
		printf("[fd1: ]%s\n", line);
		printf("[fd2: ]%s\n", line2);
		free(line);
		free(line2);
	}
	return (0);
}