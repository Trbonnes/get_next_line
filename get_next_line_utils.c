/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:11:47 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/16 09:56:07 by marvin           ###   ########.fr       */
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
	int i;
	int j;

	i = 0;
	j = 0;
	while (save[0][i] != '\0')
	{
		lect[0][j++] = save[0][i++];
		if (save[0][i] == '\n')
		{
			*save = *save + i + 1;
			lect[0][j] = '\0';
			return (1);
		}
	}
	return (0);
}

void	ft_littlesave(char **save, char **lect, int nb_r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (save[0][i] && save[0][i] != '\n' && nb_r != 0)
		lect[0][j++] = save[0][i++];
}

int		ft_littleread(char **buffer, char **save, int nb_r, int fd)
{
	int i;

	i = 0;
	while (buffer[0][i])
		(buffer[0][i++]) = 0;
	nb_r = read(fd, *buffer, BUFFER_SIZE);
	if (ft_error(nb_r, *buffer, *save) == -1)
		return (-1);
	return (nb_r);
}
