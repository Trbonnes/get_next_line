/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:46:23 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/15 15:27:45 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(char **s, size_t n)
{
	char *ptr;

	ptr = *s;
	while (n > 0)
	{
		*ptr++ = 0;
		n--;
	}
}

void	ft_freepointer(char **ptr)
{
	if (ptr[0])
	{
		free(ptr[0]);
		ptr[0] = NULL;
	}
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
