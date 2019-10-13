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
	printf("nb_o : %d\n", nb_o);
	printf("buffer: %s\n", buffer);
	if (nb_o == -1)
	{
		free(buffer);
		if (save != NULL)
			free(save);
		return (-1);
	}
	while (*buffer != '\n')
	{
		while (*save != '\n' && *save != '\0')
		{
			printf("appel\n");
			printf(" save : %s\n", save);
			*lect = *save;
			lect++;
			save++;
			printf("seg\n");
			if (*save == '\n' || *save== '\0')
			{
				save++;
				return (1);
			}
		}
		*lect = *buffer;
		lect++;
		buffer++;
	}
	free(save);
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
