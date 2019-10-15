/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:53:22 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/15 16:22:25 by trbonnes         ###   ########.fr       */
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
	while (**buffer != '\n')
	{
		if (ft_bigsave(save, lect) == 1)
			return (1);
		if (**buffer == '\0')
		{
			**lect = '\0';
			return (0);
		}
		if (**lect == '\0')
			ft_lectalloc(lect);
		**lect = **buffer;
		(*lect)++;
		(*buffer)++;
	}
	*save = *buffer;
	(*save)++;
	**lect = '\0';
	if (nb_r == 0)
		return (0);
	return (1);
}

int		ft_littleone(char **buffer, char **save, char **lect, int fd)
{
	int i;
	int nb_r;

	nb_r = 1;
	while (**lect != '\n')
	{
		i = 0;
		ft_littlesave(save, lect, nb_r);
		while (((*buffer)[i]) && ((*buffer)[i]) != '\n' && nb_r != 0)
		{
			**lect = ((*buffer)[i++]);
			(*lect)++;
		}
		if ((*buffer)[i] == '\n' || nb_r == 0)
			**lect = '\n';
		else if (nb_r != 0)
			if ((nb_r = ft_littleread(buffer, save, nb_r, fd)) == -1)
				return (-1);
	}
	*save = (*buffer) + i;
	(*save)++;
	**lect = '\0';
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

	*line = NULL; 
	lect = NULL;
	if (ft_lectalloc(&lect) == -1)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE)))
		return (-1);
	if (save_lock(&save) == -1)
		return (-1);
	nb_r = read(fd, buffer, BUFFER_SIZE);
	if (ft_error(nb_r, buffer, save) == -1)
		return (-1);
	if (ft_buffline(buffer) == 1)
	{
		nb_r = ft_bigone(&buffer, &save, &lect, nb_r);
		*line = lect;
		if (nb_r == 1)
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
