/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:53:22 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/14 12:20:16 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_buffline(char *buffer)
{
	int i;

	i = 0;
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
	int				nb_r;
	int				i;

	lect = *line;
	i = 0;
	printf("size: %d\n", BUFFER_SIZE);
	if (!(buffer = malloc(BUFFER_SIZE)))
		return (-1);
	if (!save)
	{
		if (!(save = malloc(BUFFER_SIZE)))
			return (-1);
		*save = '\0';
	}
	printf("buffer: \"%s\"\n", buffer);
	nb_r = read(fd, buffer, BUFFER_SIZE);
	printf("buffer: \"%s\"\n", buffer);
	if (ft_error(nb_r, buffer, save) == -1)
		return (-1);
	printf("buffline result : %d\n", ft_buffline(buffer));
	printf("save : \"%s\"\n", save);
	if (ft_buffline(buffer) == 1)
		while (*buffer != '\n')
		{
			while (*save != '\n' && *save != '\0')
			{
				*lect = *save;
				lect++;
				save++;
				if (*save == '\n')
				{
					save++;
					*lect = '\0';
					return (1);
				}
			}
			if (*buffer == '\0')
			{
				*lect = '\0';
				return (0);
			}
			*lect = *buffer;
			lect++;
			buffer++;
		}
	else
		while (*lect != '\n')
		{
			i = 0;
			printf("save : \"%s\"\n", save);
			while (*save && *save != '\n' && nb_r != 0)
			{
				*lect = *save;
				save++;
				lect++;
			}
			printf("lect: \"%s\"\n", lect);
			while (buffer[i] && buffer[i] != '\n' && nb_r != 0)
			{
				*lect = buffer[i];
				i++;
				lect++;
			}
			if (buffer[i] == '\n' || nb_r == 0)
				*lect = '\n';
			else if (nb_r != 0)
			{
				i = 0;
				while (buffer[i])
					buffer[i++] = 0;
				nb_r = read(fd, buffer, BUFFER_SIZE);
			}
			printf("buffer: \"%s\"\n", buffer);
			if (ft_error(nb_r, buffer, save) == -1)
				return (-1);
		}
	printf("buffer: \"%s\"\n", buffer);
	save = buffer + i;
	save++;
	printf("save return: \"%s\"\n", save);
	*lect = '\0';
	if (nb_r == 0)
	{
		free(buffer);
		return (0);
	}
	return (1);
}
