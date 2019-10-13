/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:29:14 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/13 14:29:14 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_buffline(char *buffer)
{
	int i;

	i = 0;
	printf("buffline\n");
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			*lect;
	char			*buffer;
	static char		*save;
	int				nb_o;
	int				i;

	lect = *line;
	i = 0;
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
	printf("buffline result : %d\n", ft_buffline(buffer));
	if (ft_buffline(buffer) == 1)
		while (*buffer != '\n')
		{
			printf("seg1\n");
			while (*save != '\n' && *save != '\0')
			{
				*lect = *save;
				lect++;
				save++;
				if (*save == '\n' || *save == '\0')
				{
					save++;
					*lect = '\0';
					return (1);
				}
			}
			*lect = *buffer;
			lect++;
			buffer++;
		}
	else
		while (*lect != '\n')
		{
			i = 0;
			//printf("seg2\n");
			while (buffer[i] && buffer[i] != '\n')
			{
				*lect = buffer[i];
				i++;
				lect++;
			}
			if (buffer[i] == '\n' || nb_o == 0)
				*lect = '\n';
			else if (nb_o != 0)
				nb_o = read(fd, buffer, BUFFER_SIZE);
			//printf("buffer: %s\n", buffer);
			printf("lect: %s\n", lect);
			//printf("nb_o: %d\n", nb_o);
			if (nb_o == -1)
			{
				free(buffer);
				if (save != NULL)
				free(save);
				return (-1);
			}
		}
	//free(save);
	save = buffer;
	save++;
	*lect = '\0';
	if (nb_o == 0)
	{
		free(buffer);
		free(save);
		return (0);
	}
	return (1);
}
