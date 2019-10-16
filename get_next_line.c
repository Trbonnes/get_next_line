/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:53:22 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/16 09:20:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_buffline(char *buffer)
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

int		save_lock(char **save)
{
	if (!*save)
	{
		if (!(*save = malloc(BUFFER_SIZE)))
			return (-1);
		**save = '\0';
	}
	return (0);
}

int		ft_bigone(char **buffer, char **save, char **lect, int nb_r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[0][i] != '\n')
	{
		if (ft_bigsave(save, lect) == 1)
			return (1);
		if (buffer[0][i] == '\0')
		{
			lect[0][i] = '\0';
			return (0);
		}
		lect[0][j++] = buffer[0][i++];
	}
	*save = *buffer + i + 1;
	lect[0][j] = '\0';
	if (nb_r == 0)
		return (0);
	return (1);
}

int		ft_littleone(char **buffer, char **save, char **lect, int fd)
{
	int i;
	int j;
	int nb_r;

	nb_r = 1;
	j = 0;
	while (lect[0][j] != '\n')
	{
		i = 0;
		ft_littlesave(save, lect, nb_r);
		while (buffer[0][i] && (buffer[0][i] != '\n' && nb_r != 0))
			lect[0][j++] = buffer[0][i++];
		if (buffer[0][i] == '\n' || nb_r == 0)
			lect[0][j] = '\n';
		else if (nb_r != 0)
			if ((nb_r = ft_littleread(buffer, save, nb_r, fd)) == -1)
				return (-1);
	}
	*save = *buffer + i + 1;
	lect[0][j] = '\0';
	if (nb_r == 0)
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			*lect;
	char			*buffer;
	static char		*save;
	int				nb_r;

	lect = *line;
	if (!(buffer = malloc(BUFFER_SIZE)))
		return (-1);
	if (save_lock(&save) == -1)
		return (-1);
	nb_r = read(fd, buffer, BUFFER_SIZE);
	if (ft_error(nb_r, buffer, save) == -1)
		return (-1);
	if (ft_buffline(buffer) == 1)
	{
		if (ft_bigone(&buffer, &save, &lect, nb_r) == 1)
			return (1);
		return (0);
	}
	nb_r = ft_littleone(&buffer, &save, &lect, fd);
	if (nb_r == 1)
		return (1);
	else if (nb_r == -1)
		return (-1);
	return (0);
}
