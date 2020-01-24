/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:59:34 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 10:46:33 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		ismapline(char **line)
{
	char	*map_line;
	int		width;
	int		i;

	i = 0;
	width = getmap_width(*line);
	map_line = getmap_line(*line, width);
	while (map_line[i])
	{
		if (!ft_includes(map_line[i], "012NSEW"))
		{
			free(map_line);
			free(*line);
			return (0);
		}
		i++;
	}
	free(map_line);
	free(*line);
	return (1);
}

void	getmap_height(t_game *game, char *map)
{
	int		file;
	int		width;
	char	*map_line;
	char	*line;

	file = open(map, O_RDONLY);
	if ((map_line = jumpto_map(file)) != NULL)
	{
		game->map->height++;
		free(map_line);
	}
	while (get_next_line(file, &line) > 0)
	{
		width = getmap_width(line);
		if (width > 1 && ismapline(&line))
			game->map->height++;
		else
			break ;
	}
	width = getmap_width(line);
	if (width > 1 && ismapline(&line))
		game->map->height++;
}
