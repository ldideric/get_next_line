/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:56:19 by ldideric       #+#    #+#                */
/*   Updated: 2020/01/09 14:28:53 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32
# define TRUE 1
# define FALSE 0

typedef struct	s_fd
{
	int			fd;
	char		*str;
	char		*buffer;
}				t_fd;

int				get_next_line(int fd, char **line);
char			*ft_strdup(char *s1, int a);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str, int a);
char			*clr_to_nl(char *buffer);

#endif
