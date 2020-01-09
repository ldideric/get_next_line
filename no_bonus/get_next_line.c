/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:55:24 by ldideric       #+#    #+#                */
/*   Updated: 2019/11/28 19:08:40 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*terminatebuf(char *buffer, int a)
{
	int i;

	i = 0;
	if (a == 0 || a == 1)
	{
		if (a == 1)
			while (buffer[i] != '\0' && i < BUFFER_SIZE)
				i++;
		while (i < BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
	}
	else
		buffer[BUFFER_SIZE] = '\0';
	return (buffer);
}

static char	*malloc_free(char *buffer, int ret, int a)
{
	if (a == 0)
	{
		if (buffer == NULL)
		{
			buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
			terminatebuf(buffer, 0);
		}
		else
			terminatebuf(buffer, 1);
	}
	else if (ret == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

static char	*eachline(char **buffer, char *str, int ret)
{
	*buffer = terminatebuf(*buffer, 1);
	*buffer = fixbuf(*buffer);
	str = ft_strjoin(str, *buffer);
	*buffer = clr_to_nl(*buffer);
	if (ret == 0 && str[ft_strlen(str, 1) - 1] != '\n')
	{
		str[ft_strlen(str, 0)] = '\n';
		str[ft_strlen(str, 0)] = '\0';
	}
	return (str);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer = NULL;
	char		*str;
	int			ret;

	if (BUFFER_SIZE < 1)
		return (-1);
	str = malloc(5);
	str[0] = '\0';
	buffer = malloc_free(buffer, 0, 0);
	while (str[ft_strlen(str, 1) - 1] != '\n')
	{
		ret = checks(fd, line, buffer);
		if (ret < 0)
			return (-1);
		str = eachline(&buffer, str, ret);
		if (ret == 0)
			break ;
	}
	str[ft_strlen(str, 0) - 1] = '\0';
	*line = ft_strdup(str, 1);
	buffer = malloc_free(buffer, ret, 1);
	return (ret);
}
