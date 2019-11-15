/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:44:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/15 13:42:15 by trbonnes         ###   ########.fr       */
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
		if (dst[0])
		{
			free(dst[0]);
			dst[0] = NULL;
		}
		if (src[0])
		{
			free(src[0]);
			src[0] = NULL;
		}
		return (0);
	}
	//printf("lol\n");
	if (src[0][0] == '\n' && src[0][i + 1] == '\0')
		return (1);
	if (i != 0 || (src[0][0] == '\n' && src[0][1] != '\0'))
		src[0] = src[0] + i + 1;
	//printf("i\n");
	if (dst[0])
	{
		free(dst[0]);
		dst[0] = NULL;
	}
	//printf("lolilol\n");
	if (!(dst[0] = malloc(sizeof(char) * ft_strlen(src[0]) + 1)))
		return (-1);
	ft_bzero(dst, ft_strlen(src[0]) + 1);
	j = 0;
	i = 0;
	//printf("loli\n");
	while (src[0][i])
		dst[0][j++] = src[0][i++];
	dst[0][j] = '\0';
	src[0] = add;
	//printf("lo\n");
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
		{
			free(buffer);
			buffer = NULL;
		}
		if (save)
		{
			free(save);
			save = NULL;
		}
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
	if (!(tmp = malloc(sizeof(char) * i + 1)))
		return (-1);
	j = -1;
	while (str[0][++j] != '\0')
		tmp[j] = (str[0][j]);
	tmp[j] = '\0';
	free(str[0]);
	str[0] = NULL;
	if (!(str[0] = malloc(sizeof(char) * size + 1)))
		return (-1);
	ft_bzero(str, size + 1);
	j = -1;
	while (tmp[++j] != '\0')
		str[0][j] = tmp[j];
	str[0][j] = '\0';
	free(tmp);
	tmp = NULL;
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
	if (*line)
		free(*line);
	*line = NULL;
	if (!(*line = malloc(BUFFER_SIZE + 1)))
		return (-1);
	ft_bzero(line, BUFFER_SIZE + 1);
	i = 0;
	j = 0;
	buffer = NULL;
	if (save && save[0] != '\0')
	{
		//printf("save: \"%s\"\n", save);
		//printf("buffer: \"%s\"\n", buffer);
		nb_r = ft_savefreereturn(&save, &buffer, 1, 0);
		//printf("save: \"%s\"\n", save);
		//printf("buffer: \"%s\"\n", buffer);
	}
	else
	{
		if (!(buffer = malloc(BUFFER_SIZE + 1)))
			return (-1);
		ft_bzero(&buffer, BUFFER_SIZE + 1);
		nb_r = read(fd, buffer, BUFFER_SIZE);
		if (ft_error(nb_r, buffer, save) == -1)
			return (-1);
	}
	while (buffer[i] != '\n' && nb_r != 0)
	{
		line[0][j++] = buffer[i++];
		if (buffer[i] == '\0')
		{
			if (ft_strlen(buffer) != BUFFER_SIZE)
			{
				free(buffer);
				buffer = NULL;
				if (!(buffer = malloc(BUFFER_SIZE + 1)))
					return (-1);
			}
			ft_bzero(&buffer, BUFFER_SIZE + 1);
			nb_r = read(fd, buffer, BUFFER_SIZE);
			if (ft_realloc(line, ft_strlen(line[0]) + BUFFER_SIZE) == -1 || ft_error(nb_r, buffer, save) == -1)
				return (ft_error(nb_r, buffer, save));
			i = 0;
		}
	}
	line[0][j] = '\0';
	//printf("line: %s\n", line[0]);
	if (ft_realloc(line, ft_strlen(line[0])) == -1 )
		return (ft_error(-1, buffer, save));
	//printf("line: %s\n", line[0]);
	//printf("save end: \"%s\"\n", save);
	//printf("buffer end: \"%s\"\n", buffer);
	nb_r = ft_savefreereturn(&buffer, &save, nb_r, i);
	//printf("save end: \"%s\"\n", save);
	//printf("buffer end: \"%s\"\n", buffer);
	return (nb_r);
}
