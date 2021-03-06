/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:44:38 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/25 14:43:56 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_realloc(char **str, int size)
{
	char	*tmp;
	size_t	j;

	if (size == 0)
		size = 1;
	if (!(tmp = malloc(sizeof(char) * size + 1)))
		return (-1);
	ft_bzero(tmp, size + 1);
	j = -1;
	while (str[0][++j] && str[0][j] != '\n')
		tmp[j] = (str[0][j]);
	if (str[0])
		free(str[0]);
	if (!(str[0] = malloc(sizeof(char) * size + 1)))
		return (-1);
	ft_bzero(str[0], size + 1);
	j = -1;
	while (tmp[++j] != '\0')
		str[0][j] = tmp[j];
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

int		ft_saveandreturn(char **line, t_buffer *lst, int nb_r)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (line[0][i] && line[0][i] != '\n')
	{
		i++;
		k++;
	}
	ft_bzero(lst->buffer, BUFFER_SIZE + 1);
	ft_lstclear(&(lst->next), 1);
	lst->next = NULL;
	while (line[0][i++])
		lst->buffer[j++] = line[0][i];
	if (ft_realloc(line, k) == -1)
		return (-1);
	if (lst->buffer[0] == '\0' && nb_r == 0)
	{
		lst = NULL;
		return (0);
	}
	return (1);
}

void	ft_fullup(char **line, t_buffer **lst)
{
	t_buffer	*tmp;
	int			i;
	int			j;

	j = 0;
	tmp = *lst;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->buffer[i])
			line[0][j++] = tmp->buffer[i++];
		tmp = tmp->next;
	}
}

int		ft_bufferadd(t_buffer **lst, int fd)
{
	t_buffer	*new;
	t_buffer	*tmp;
	int			nb_r;

	if (*lst && ft_strrchr((*lst)->buffer, '\n'))
		return (1);
	if ((new = ft_lstnew()) == NULL)
		return (ft_lstclear(lst, -1));
	if ((nb_r = read(fd, new->buffer, BUFFER_SIZE)) == -1)
		return (ft_lstclear(&new, -1));
	new->next = NULL;
	if (lst == NULL)
		return (-1);
	tmp = *lst;
	if (tmp != 0)
	{
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
	if (ft_strrchr(new->buffer, '\n'))
		return (1);
	return ((nb_r == 0) ? 0 : 2);
}

int		get_next_line(int fd, char **line)
{
	static t_buffer	*lst;
	int				nb_r;

	nb_r = 2;
	if (!line)
		return (-1);
	if (fd < 0)
		return (-1);
	if (BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	while (nb_r != 1 && nb_r != 0)
	{
		if ((nb_r = ft_bufferadd(&lst, fd)) == -1)
			return (-1);
	}
	if (!(line[0] = malloc(sizeof(char) * (ft_lstsize(lst) * BUFFER_SIZE) + 1)))
		return (ft_lstclear(&lst, -1));
	ft_bzero(line[0], ft_lstsize(lst) * BUFFER_SIZE + 1);
	ft_fullup(line, &lst);
	if ((nb_r = ft_saveandreturn(line, lst, nb_r)) == -1)
		return (ft_lstclear(&lst, -1));
	return (nb_r);
}
