#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char			*lect;
	char			*buffer;
	static char		*save;
	int				nb_o;

	lect = *line;
	if (*buffer == '\0')
	{
		buffer = malloc(BUFFER_SIZE);
		save = '\0';
	}
	if (buffer == NULL)
		return (-1);
	nb_o = read(fd, buffer, BUFFER_SIZE);
	if (nb_o == -1)
		return (-1);
	while (*buffer != '\n' || *buffer != '\0')
	{
		while (save != '\n' || save != '\0')
		{
			*lect = *save;
			lect++;
			save++;
		}
		if (save == '\n')
			return (1);
		*lect = *buffer;
		lect++;
		buffer++;
	}
	save = buffer;
	if (nb_o == 0)
	{
		free(buffer);
		free(save);
		return (0);
	}
	return (1);
}
