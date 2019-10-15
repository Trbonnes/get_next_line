/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:53:22 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/15 08:28:56 by trbonnes         ###   ########.fr       */
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
	int				r;

	lect = *line;
	if (!(buffer = malloc(BUFFER_SIZE)))
		return (-1);
	if (!save)
	{
		if (!(save = malloc(BUFFER_SIZE)))
			return (-1);
		*save = '\0';
	}
	nb_r = read(fd, buffer, BUFFER_SIZE);
	if (ft_error(nb_r, buffer, save) == -1)
		return (-1);
	printf("buffline : %d\n", ft_buffline(buffer));
	if (ft_buffline(buffer) == 1)
	{
		if (ft_bigone(&buffer, &save, &lect, nb_r) == 1)
			return (1);
		else
			return (0);
	}
	else
	{
		r = ft_littleone(&buffer, &save, &lect, fd);
		if (r == 1)
			return (1);
		else if (r == -1)
		{
			free(buffer);
			return (-1);
		}
		else
		{
			free(buffer);
			return (0);
		}
	}
}
