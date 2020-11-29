#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **argv)
{
	char *line;
	int fd;
	int fd1;
	char *line1;

	(void)ac;
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		printf("Failed to open The file");
		return (-1);
	}
	if (!(fd1 = open(argv[2], O_RDONLY)))
	{
		printf("Failed to open The file");
		return (-1);
	}
	for (int i = 0; i < 30; i++)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
		get_next_line(fd1, &line1);
		printf("%s\n", line1);
		free(line1);
	}
	return (0);
}
