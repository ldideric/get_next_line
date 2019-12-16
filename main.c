/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 15:46:19 by ldideric       #+#    #+#                */
/*   Updated: 2019/12/10 17:23:38 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open("test1.txt", O_RDONLY);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("|%d|%s\n", i, line);
		free(line);
	}
//	while (1)
//		;
	return (0);
}
