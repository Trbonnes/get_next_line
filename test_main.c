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
	char *line;

	(void)ac;
	line = "Bonjour";
	fd = open(av[1], O_RDONLY);
	printf("fd : %d\n", fd);
	re = 1;
	while (re != 0 && re != -1)
	{
		re = get_next_line(fd, &line);
		//system("leaks a.out");
		printf("valeur de retour : %d\n", re);
		printf("%s\n\n", line);
		free(line);
	}
	/*re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);
	re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);
	re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);
	re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);
	re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);
	re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);
	re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);*/
	/*fd = open(av[2], O_RDONLY);
	printf("fd : %d\n", fd);
	re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);
	re = get_next_line(fd, &line);
	printf("valeur de retour : %d\n", re);
	printf("%s\n\n", line);*/

	while (1)
		;
	return (0);
}
