#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int main(int ac, char **argv)
{
	char *line;
	int fd;

	(void)ac;
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		printf("Failed to open The file");
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
