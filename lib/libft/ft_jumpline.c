/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jumpline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:55:03 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:55:06 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*jumpto_map(int file)
{
	int		width;
	char	*line;
	char	*map_line;

	while (get_next_line(file, &line) > 0)
	{
		width = getmap_width(line);
		if (width > 1)
		{
			map_line = getmap_line(line, width);
			if (ft_strincludes(map_line, "012NSEW"))
				break ;
			free(map_line);
		}
		free(line);
	}
	free(line);
	return (map_line);
}

int		jumpempty(int commands, char *map)
{
	int		file;
	char	*line;

	file = open(map, O_RDONLY);
	jumpto(file, commands);
	while (get_next_line(file, &line) > 0 && getmap_width(line) == 0)
	{
		commands++;
		free(line);
	}
	free(line);
	return (commands);
}

int		jumpto(int file, int commands)
{
	char	*line;
	int		a;

	a = 0;
	while (get_next_line(file, &line) > 0)
	{
		if (a < commands)
		{
			free(line);
			a++;
		}
		else
			break ;
	}
	free(line);
	return (-1);
}

int		new_jumpto(char *file, int line)
{
	int		fd;

	fd = open(file, O_RDONLY);
	jumpto(fd, line);
	return (fd);
}
