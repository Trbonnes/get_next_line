#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int fd;
	int re;
	char **line;

	(void)ac;
	line = malloc(10000);
	*line = malloc(10000);
	fd = open(av[1], O_RDONLY);
	printf("fd : %d\n", fd);
	re = get_next_line(fd, line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line[0]);
	*line = malloc(10000);
	re = get_next_line(fd, line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line[0]);
	*line = malloc(10000);
	re = get_next_line(fd, line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line[0]);
}
