/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trbonnes <trbonnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:52:01 by trbonnes          #+#    #+#             */
/*   Updated: 2019/10/15 08:27:13 by trbonnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int	get_next_line(int fd, char **line);
int	ft_buffline(char *buffer);
int ft_error(int nb_r, char *buffer, char *save);
int	ft_bigone(char **buffer, char **save, char **lect, int nb_r);
int ft_littleone(char **buffer, char **save, char **lect, int fd);

#endif
