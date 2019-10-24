/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:46:23 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/24 09:38:58 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_strcat(char **dest, char **src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[0][i] != '\0')
		i++;
	while (src[0][j] != '\0')
	{
		dest[0][i + j] = src[0][j];
		j++;
	}
	dest[0][i + j] = '\0';
	ft_bzero(src, BUFFER_SIZE);
}
