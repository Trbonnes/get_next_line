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
	while (buffer[i])
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
	//if (ft_buffline(buffer) == 1)
		while (*buffer != '\n')
		{
			while (*save != '\n' && *save != '\0')
			{
				*lect = *save;
				lect++;
				save++;
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
	//else
		//while (buffer[i] != '\n')
		//{
		//	i = 0;
		//	while (buffer[i])
		//	{
		//		*lect = buffer[i];
		//		i++;
		//		lect++;
		//	}
		//	nb_o = read(fd, buffer, BUFFER_SIZE);
		//	if (nb_o == -1)
		//	{
		//		free(buffer);
		//		if (save != NULL)
		//		free(save);
		//		return (-1);
		//	}
		//}
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
