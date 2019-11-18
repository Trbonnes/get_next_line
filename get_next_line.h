/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:46:43 by trbonnes          #+#    #+#             */
/*   Updated: 2019/11/18 09:10:26 by trbonnes         ###   ########.fr       */
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

int		get_next_line(int fd, char **line);
int		ft_savefreereturn(char **src, char **dst, int nb_r, int i);
int		ft_error(int nb_r, char *buffer, char *save);
int		ft_realloc(char **str, int size);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	ft_bzero(char **s, size_t n);
void	ft_freepointer(char **ptr);
int		ft_reread(char **buffer, char **save, char **line, int fd);
int		ft_init(int fd, char **line);

#endif
