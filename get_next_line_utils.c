/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 14:19:27 by ldideric       #+#    #+#                */
/*   Updated: 2019/11/28 17:16:48 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *str, int a)
{
	int i;

	i = 0;
	if (str[0] == '\0' && a == 1)
		return (1);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char		*ft_strdup(char *s1, int a)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (a == 1)
		len = ft_strlen(s1, 0);
	else
		len = BUFFER_SIZE;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[len] = '\0';
	free(s1);
	return (str);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1, 0) + ft_strlen(s2, 0) + 2));
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
	{
		str[i] = s2[b];
		i++;
		b++;
		if (str[i - 1] == '\n')
			break ;
	}
	str[i] = '\0';
	str[i + 1] = '\0';
	free(s1);
	return (str);
}

char		*fixbuf(char *buffer)
{
	int		i;
	int		d;
	char	*new;

	i = 0;
	d = 0;
	new = malloc(sizeof(char) * BUFFER_SIZE);
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] != '\0')
		{
			new[d] = buffer[i];
			d++;
		}
		i++;
	}
	while (d < BUFFER_SIZE)
	{
		new[d] = '\0';
		d++;
	}
	free(buffer);
	buffer = ft_strdup(new, 0);
	return (buffer);
}

char		*clr_to_nl(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		buffer[i] = '\0';
		i++;
	}
	if (buffer[i] == '\n')
		buffer[i] = '\0';
	buffer = fixbuf(buffer);
	return (buffer);
}
