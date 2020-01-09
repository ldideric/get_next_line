/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 12:59:04 by ldideric       #+#    #+#                */
/*   Updated: 2020/01/09 14:54:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	checks(int fd, char **line, char *buffer)
{
	int		ret;

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (buffer[0] == '\0')
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (ret);
		buffer[ret] = '\0';
		ret = (ret > 0) ? 1 : ret;
	}
	return (ret);
}

static char	*eachline(char **buffer, char *str, int ret)
{
	str = ft_strjoin(str, *buffer);
	*buffer = clr_to_nl(*buffer);
	if (ret == 0 && str[ft_strlen(str, TRUE) - 1] != '\n')
	{
		str[ft_strlen(str, FALSE)] = '\n';
		str[ft_strlen(str, FALSE)] = '\0';
	}
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static t_fd		filed[4096];
	int				ret;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 4095)
		return (-1);
	filed[fd].str = malloc(1);
	filed[fd].str[0] = '\0';
	if (filed[fd].buffer == NULL)
		filed[fd].buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (filed[fd].str[ft_strlen(filed[fd].str, TRUE) - 1] != '\n')
	{
		ret = checks(fd, line, filed[fd].buffer);
		if (ret < 0)
			return (-1);
		filed[fd].str = eachline(&filed[fd].buffer, filed[fd].str, ret);
		if (ret == 0)
			break ;
	}
	if (ret == 0)
		free(filed[fd].buffer);
	filed[fd].str[ft_strlen(filed[fd].str, TRUE) - 1] = '\0';
	*line = ft_strdup(filed[fd].str, TRUE);
	free(filed[fd].str);
	return (ret);
}
