/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:11:47 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/14 15:23:47 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_error(int nb_r, char *buffer, char *save)
{
	if (nb_r == -1)
	{
		free(buffer);
		if (save != NULL)
			free(save);
		return (-1);
	}
	return (0);
}

int	ft_bigone(char **buffer, char **save, char **lect, int nb_r)
{
	while (**buffer != '\n')
	{
		while (**save != '\n' && **save != '\0')
		{
			**lect = **save;
			(*lect)++;
			(*save)++;
			if (**save == '\n')
			{
				(*save)++;
				**lect = '\0';
				return (1);
			}
		}
		if (**buffer == '\0')
		{
			**lect = '\0';
			return (0);
		}
		**lect = **buffer;
		(*lect)++;
		(*buffer)++;
	}
	*save = *buffer;
	(*save)++;
	**lect = '\0';
	if (nb_r == 0)
	{
		free(buffer);
		return (0);
	}
	return (1);
}

int ft_littleone(char **buffer, char **save, char **lect, int nb_r, int fd)
{
	int i;

	while (**lect != '\n')
	{
		i = 0;
		while (**save && **save != '\n' && nb_r != 0)
		{
			**lect = **save;
			(*save)++;
			(*lect)++;
		}
		while ((*buffer)[i] && (*buffer[i]) != '\n' && nb_r != 0)
		{
			**lect = (*buffer)[i];
			i++;
			(*lect)++;
		}
		if ((*buffer)[i] == '\n' || nb_r == 0)
			**lect = '\n';
		else if (nb_r != 0)
		{
			i = 0;
			while ((*buffer)[i])
				(*buffer)[i++] = 0;
			nb_r = read(fd, *buffer, BUFFER_SIZE);
		}
		if (ft_error(nb_r, *buffer, *save) == -1)
			return (-1);
	}
	*save = (*buffer) + i;
	(*save)++;
	**lect = '\0';
	if (nb_r == 0)
	{
		//free(buffer);
		return (0);
	}
	return (1);
}