/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 13:16:32 by ldideric       #+#    #+#                */
/*   Updated: 2020/01/09 14:59:57 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			ft_strlen(char *str, int a)
{
	int i;

	i = 0;
	if (str[0] == '\0' && a == TRUE)
		return (1);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	str = malloc((ft_strlen(s1, FALSE) + ft_strlen(s2, FALSE) + 2));
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

char		*ft_strdup(char *s1, int a)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (a == TRUE)
		len = ft_strlen(s1, FALSE);
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
	return (str);
}

char		*clr_to_nl(char *buffer)
{
	char	*new;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	new = ft_strdup(buffer + i, FALSE);
	free(buffer);
	return (new);
}
