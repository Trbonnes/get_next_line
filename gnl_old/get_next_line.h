/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:46:43 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/25 11:51:41 by trbonnes         ###   ########.fr       */
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

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE  0
#  endif
# endif

typedef	struct		s_buffer
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_buffer	*next;
}					t_buffer;

int					ft_realloc(char **str, int size);
int					ft_saveandreturn(char **line, t_buffer *lst, int nb_r);
void				ft_fullup(char **line, t_buffer **lst);
int					ft_bufferadd(t_buffer **lst, int fd);
int					get_next_line(int fd, char **line);
t_buffer			*ft_lstnew(void);
void				ft_bzero(char *s, size_t n);
int					ft_strrchr(const char *s, int c);
int					ft_lstsize(t_buffer *lst);
int					ft_lstclear(t_buffer **lst, int nb_r);

#endif
