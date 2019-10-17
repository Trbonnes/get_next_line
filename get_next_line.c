/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:44:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/17 11:18:33 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strrlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	ft_strcat(char **dest, char **src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[0][i] != '\0')
	{
		i++;
	}
	while (src[0][j] != '\0')
	{
		dest[0][i + j] = src[0][j];
		j++;
	}
	dest[0][i + j] = '\0';
}

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

int		ft_realloc(char **str)
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
	tmp[++j] = '\0';
	//free(str[0]);
	if (!(str[0] = malloc(i + BUFFER_SIZE + 1)))
		return (-1);
	j = -1;
	while (tmp[++j] != '\0')
		str[0][j] = tmp[j];
	str[0][j] = '\0';
	return (0);
}

int		ft_findandreturn(char **line, char **save)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(line[0] = malloc(ft_strrlen(save[0]) + 1)))
		return (-1);
	while (save[0][i] != '\n' && save[0][i] != '\0')
		line[0][j++] = save[0][i++];
	line[0][j] = '\0';
	if (save[0][i] == '\n')
	{
		*save = *save + i + 1;
		return (1);
	}
	else
		return (0);
}

int		get_next_line(int fd, char **line)
{
	char *buffer;
	static char *save;
	int nb_r;

	*line = 0;
	nb_r = 1;
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!save)
	{
		if (!(save = malloc(BUFFER_SIZE + 1)))
			return (-1);
		*save = '\0';
	}
	while (nb_r > 0)
	{
		if (ft_realloc(&save) == -1)
			return (-1);
		nb_r = read(fd, buffer, BUFFER_SIZE);
		ft_strcat(&save, &buffer);
	}
	if (ft_error(nb_r, buffer, save) == -1)
		return (-1);
	nb_r = ft_findandreturn(line, &save);
	return (nb_r);
}