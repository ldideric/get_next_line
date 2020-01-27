/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:56:19 by ldideric       #+#    #+#                */
/*   Updated: 2020/01/27 12:51:51 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

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
void			*ft_calloc(size_t count);

#endif
