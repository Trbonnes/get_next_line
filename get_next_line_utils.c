/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:46:23 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/25 11:51:55 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buffer	*ft_lstnew(void)
{
	t_buffer	*new;

	if ((new = malloc(sizeof(t_buffer))) == NULL)
		return (NULL);
	if (new)
	{
		ft_bzero(new->buffer, BUFFER_SIZE + 1);
		new->next = NULL;
	}
	return (new);
}

void		ft_bzero(char *s, size_t n)
{
	char *ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr++ = 0;
		n--;
	}
}

int			ft_strrchr(const char *s, int c)
{
	int end;

	end = 0;
	while (s[end])
	{
		if (s[end] == c)
			return (1);
		end++;
	}
	if (c == 0)
		return (1);
	return (0);
}

int			ft_lstsize(t_buffer *lst)
{
	int i;

	i = 0;
	if (lst != 0)
	{
		while (lst != 0)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}

int			ft_lstclear(t_buffer **lst, int nb_r)
{
	t_buffer *tmp;
	t_buffer *supp;

	if (lst == NULL || *lst == NULL)
		return (nb_r);
	tmp = *lst;
	while (tmp != 0)
	{
		supp = tmp;
		tmp = tmp->next;
		free(supp);
	}
	lst = NULL;
	return (nb_r);
}
