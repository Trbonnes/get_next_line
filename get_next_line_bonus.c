/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:44:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/18 08:51:57 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_savefreereturn(char **src, char **dst, int nb_r, int i)
{
	char	*add;
	int		j;

	add = src[0];
	if (nb_r == 0)
	{
		ft_freepointer(dst);
		ft_freepointer(src);
		return (0);
	}
	if (src[0][0] == '\n' && src[0][i + 1] == '\0')
		return (1);
	if (i != 0 || (src[0][0] == '\n' && src[0][1] != '\0'))
		src[0] = src[0] + i + 1;
	ft_freepointer(dst);
	if (!(dst[0] = malloc(sizeof(char) * ft_strlen(src[0]) + 1)))
		return (-1);
	ft_bzero(dst, ft_strlen(src[0]) + 1);
	j = 0;
	i = 0;
	while (src[0][i])
		dst[0][j++] = src[0][i++];
	src[0] = add;
	ft_freepointer(src);
	return (1);
}

int		ft_reread(char **buffer, char **save, char **line, int fd)
{
	int nb_r;

	if ((int)ft_strlen(buffer[0]) != BUFFER_SIZE)
	{
		ft_freepointer(buffer);
		if (!(buffer[0] = malloc(BUFFER_SIZE + 1)))
			return (-1);
	}
	ft_bzero(buffer, BUFFER_SIZE + 1);
	nb_r = read(fd, buffer[0], BUFFER_SIZE);
	if (ft_realloc(line, ft_strlen(line[0]) + BUFFER_SIZE) == -1
	|| ft_error(nb_r, buffer[0], save[0]) == -1)
		return (ft_error(nb_r, buffer[0], save[0]));
	return (nb_r);
}

int		ft_firstread(char **buffer, char **save, int fd)
{
	int nb_r;

	if (!(buffer[0] = malloc(BUFFER_SIZE + 1)))
		return (-1);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	nb_r = read(fd, buffer[0], BUFFER_SIZE);
	if (ft_error(nb_r, buffer[0], save[0]) == -1)
		return (-1);
	return (nb_r);
}

int		ft_init(int fd, char **line)
{
	if (fd < 0)
		return (-1);
	ft_freepointer(line);
	if (!(*line = malloc(BUFFER_SIZE + 1)))
		return (-1);
	ft_bzero(line, BUFFER_SIZE + 1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char *save;
	int			i[3];

	if (ft_init(fd, line) == -1)
		return (-1);
	i[0] = 0;
	i[1] = 0;
	buffer = NULL;
	if (save && save[0] != '\0')
		i[2] = ft_savefreereturn(&save, &buffer, 1, 0);
	else if ((i[2] = ft_firstread(&buffer, &save, fd)) == -1)
		return (-1);
	while (buffer[i[0]] != '\n' && i[2] != 0)
	{
		line[0][i[1]++] = buffer[i[0]++];
		if (buffer[i[0]] == '\0')
		{
			if ((i[2] = ft_reread(&buffer, &save, line, fd)) == -1)
				return (-1);
			i[0] = 0;
		}
	}
	return ((ft_realloc(line, ft_strlen(line[0])) == -1) ?
	ft_error(-1, buffer, save) : ft_savefreereturn(&buffer, &save, i[2], i[0]));
}
