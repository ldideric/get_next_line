/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:56:19 by ldideric       #+#    #+#                */
/*   Updated: 2019/11/28 15:37:43 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			ft_strlen(char *str, int a);
char		*ft_strdup(char *s1, int a);
char		*ft_strjoin(char *s1, char *s2);
char		*fixbuf(char *buffer);
char		*clr_to_nl(char *buffer);

#endif
