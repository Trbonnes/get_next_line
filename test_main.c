#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void		ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int	main(int ac, char **av)
{
	int fd;
	int re;
	char *line;

	(void)ac;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	//printf("fd : %d\n", fd);
	re = 1;
	while (re != 0 && re != -1)
	{
		re = get_next_line(fd, &line);
		//system("leaks a.out");
		ft_putendl_fd("valeur de retour : ", 1);
		printf("%d\n", re);
		//printf("%s\n", line);
		ft_putendl_fd(line, 1);
		free(line);
		system("leaks a.out");
	}
	re = get_next_line(fd, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	re = get_next_line(fd, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	re = get_next_line(fd, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	re = get_next_line(99, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	//ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	re = get_next_line(fd, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	re = get_next_line(33, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	//ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	re = get_next_line(fd, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	/*fd = open(av[2], O_RDONLY);
	//printf("fd : %d\n", fd);
	re = get_next_line(fd, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	re = get_next_line(42, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	//ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");
	re = get_next_line(fd, &line);
	//system("leaks a.out");
	//ft_putendl_fd("valeur de retour : ", 1);
	//printf("%d\n", re);
	//printf("%s\n", line);
	ft_putendl_fd(line, 1);
	free(line);
	//system("leaks a.out");*/

	while (1)
		;
	return (0);
}
