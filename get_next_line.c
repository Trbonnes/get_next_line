#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{
	char			*lect;
	char			*buffer;
	static char		*save;
	int				nb_o;

	lect = *line;
	if (!(buffer = malloc(BUFFER_SIZE)))
		return (-1);
	if (!save)
	{
		if (!(save = malloc(BUFFER_SIZE)))
			return (-1);
		*save = '\0';
	}
	nb_o = read(fd, buffer, BUFFER_SIZE);
	printf("%d\n", 1);
	if (nb_o == -1)
	{
		free(buffer);
		if (save != NULL)
			free(save);
		return (-1);
	}
	printf("%d\n", 2);
	while (*buffer != '\n' || *buffer != '\0')
	{
		printf("%d\n", 35);
		while (*save != '\n' || *save != '\0')
		{
			printf("%d\n", 355);
			*lect = *save;
			lect++;
			save++;
			if (*save == '\n')
				return (1);
		}
		printf("%d\n", 3555);
		*lect = *buffer;
		lect++;
		buffer++;
	}
	printf("%d\n", 3);
	save = buffer;
	save++;
	if (nb_o == 0)
	{
		free(buffer);
		free(save);
		return (0);
	}
	return (1);
}
