/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:44:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/14 16:59:20 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_savefreereturn(char **src, char **dst, int nb_r, int i)
{
	char *add;

	add = src[0];
	if (nb_r == 0)
		return (0);
	if (i != 0)
		src[0] = src[0] + i + 1;
	if (dst[0])
		free(dst[0]);
	if (!(dst[0] = malloc(sizeof(char) * ft_strlen(src[0] + i + 1) + 1)))
		return (-1);
	i = -1;
	while (src[0][++i])
		dst[0][i] = src[0][i];
	dst[0][i] = '\0';
	src[0] = add;
	if (src[0])
	{
		free(src[0]);
		src[0] = NULL;
	}
	return (1);
}

int		ft_error(int nb_r, char *buffer, char *save)
{
	if (nb_r == -1)
	{
		if (buffer)
			free(buffer);
		if (save)
			free(save);
		return (-1);
	}
	return (0);
}

int		ft_realloc(char **str, int size)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = ft_strlen(str[0]);
	if (!(tmp = malloc(i + 1)))
		return (-1);
	j = -1;
	while (str[0][++j] != '\0')
		tmp[j] = (str[0][j]);
	tmp[j] = '\0';
	free(str[0]);
	if (!(str[0] = malloc(size + 1)))
		return (-1);
	j = -1;
	while (tmp[++j] != '\0')
		str[0][j] = tmp[j];
	str[0][j] = '\0';
	free(tmp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char *save;
	int			nb_r;
	int			i;
	int			j;

	if (fd < 0)
		return (-1);
	*line = NULL;
	if (!(*line = malloc(BUFFER_SIZE + 1)))
		return (-1);
	i = 0;
	j = 0;
	buffer = NULL;
	if (save)
	{
		nb_r = ft_savefreereturn(&save, &buffer, 1, 0);
	}
	else
	{
		if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
		nb_r = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (ft_error(nb_r, buffer, save) == -1)
			return (-1);
	}
	while (buffer[i] != '\n' && nb_r != 0)
	{
		line[0][j++] = buffer[i++];
		if (buffer[i] == '\0')
		{
			ft_bzero(&buffer, ft_strlen(buffer));
			nb_r = read(fd, buffer, BUFFER_SIZE);
			if (ft_realloc(line, ft_strlen(line[0]) + BUFFER_SIZE) == -1 || ft_error(nb_r, buffer, save) == -1)
				return (ft_error(nb_r, buffer, save));
			i = 0;
		}
	}
	if (ft_realloc(line, ft_strlen(line[0])) == -1 )
		return (ft_error(-1, buffer, save));
	nb_r = ft_savefreereturn(&buffer, &save, nb_r, i);
	return (nb_r);
}
