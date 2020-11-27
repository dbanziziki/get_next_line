#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(int ac, char **argv)
{
	char *line;
	int fd;
	int i;

	(void)ac;
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		printf("Failed to open The file");
		return (-1);
	}
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		printf("[%d] %s\n",i, line);
		free(line);
	}
	return (0);
}
