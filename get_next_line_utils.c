/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:11:47 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/16 08:56:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_error(int nb_r, char *buffer, char *save)
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

int		ft_bigsave(char **save, char **lect)
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
	return (0);
}

void	ft_littlesave(char **save, char **lect, int nb_r)
{
	while (**save && **save != '\n' && nb_r != 0)
	{
		**lect = **save;
		(*save)++;
		(*lect)++;
	}
}

int		ft_littleread(char **buffer, char **save, int nb_r, int fd)
{
	int i;

	i = 0;
	while ((*buffer)[i])
		((*buffer)[i++]) = 0;
	nb_r = read(fd, *buffer, BUFFER_SIZE);
	if (ft_error(nb_r, *buffer, *save) == -1)
		return (-1);
	return (nb_r);
}
