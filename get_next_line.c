#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char			*lect;
	static char		*buffer;
	int				nb_o;

	lect = *line;
	if (*buffer == '\0')
		buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (-1);
	nb_o = read(fd, buffer, BUFFER_SIZE);
	if (nb_o == -1)
		return (-1);
	while (*buffer != '\n' || *buffer != '\0')
	{
		*lect = *buffer;
		lect++;
		buffer++;
	}
	if (nb_o == 0)
		return(0);
	return(1);
}
