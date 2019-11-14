/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:44:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/14 12:08:47 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_savefreereturn(char **buffer, char **save, int nb_r)
{

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

	if (*line)
		free(*line);
	i = 0;
	j = 0;
	if (fd < 0)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!(*line = malloc(BUFFER_SIZE + 1)))
		return (-1);
	nb_r = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	if (ft_error(nb_r, buffer, save) == -1)
		return (ft_freeandreturn());
	while (buffer[i] != '\n' && nb_r != 0)
	{
		line[j++] = buffer[i++];
		if (buffer[i] == '\0')
		{
			ft_bzero(&buffer, BUFFER_SIZE);
			nb_r = read(fd, buffer, BUFFER_SIZE);
			if (ft_realloc(line, ft_strlen(*line) + BUFFER_SIZE) == -1 || ft_error(nb_r, buffer, save) == -1)
				return (ft_freeandreturn());
			i = 0;
		}
	}
	i++;
	if (ft_realloc(line, ft_strlen(*line)) == -1 )
		return (ft_freeandreturn());
	nb_r = ft_savefreereturn(&buffer, &save, nb_r);
	return (nb_r);
}
