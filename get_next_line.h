/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:46:43 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/17 12:14:55 by trbonnes         ###   ########.fr       */
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
int		ft_findandreturn(char **line, char **save);
int		ft_realloc(char **str);
int		ft_savelock(char **save);
int		ft_error(int nb_r, char *buffer, char *save);
void	ft_strcat(char **dest, char **src);
size_t	ft_strrlen(const char *s);
size_t	ft_strlen(const char *s);

#endif
