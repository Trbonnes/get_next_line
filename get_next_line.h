/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:46:43 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/19 11:32:03 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef	struct		s_buffer
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_buffer	*next;
}					t_buffer;

int		get_next_line(int fd, char **line);
int		ft_strrchr(const char *s, int c);
void	ft_bzero(char *s, size_t n);
int		ft_error(int nb_r, t_buffer **lst);
int		ft_lstsize(t_buffer *lst);
int		ft_freepointer(char **ptr);
t_buffer	*ft_lstnew();
void	ft_lstclear(t_buffer **lst);

#endif
