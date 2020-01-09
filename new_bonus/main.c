/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 15:46:19 by ldideric       #+#    #+#                */
/*   Updated: 2020/01/09 15:04:37 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		fd[3];
	int		i[3];

	i[0] = 1;
	fd[0] = open("/Users/ldideric/Desktop/Projects/GET_NEXT_LINE/new_bonus/test1.txt", O_RDONLY);
	while (i[0] > 0)
	{
		i[0] = get_next_line(fd[0], &line);
		printf("|%d|%s\n", i[0], line);
		free(line);
	}
	i[1] = 1;
	i[2] = 1;
	fd[1] = open("/Users/ldideric/Desktop/Projects/GET_NEXT_LINE/new_bonus/bonus1.txt", O_RDONLY);
	fd[2] = open("/Users/ldideric/Desktop/Projects/GET_NEXT_LINE/new_bonus/bonus2.txt", O_RDONLY);
	while (i[1] > 0 || i[2] > 0)
	{
		i[1] = get_next_line(fd[1], &line);
		printf("|%d|%s\n", i[1], line);
		free(line);
		i[2] = get_next_line(fd[2], &line);
		printf("|%d|%s\n", i[2], line);
		free(line);
	}
	while(1);
	return (0);
}
