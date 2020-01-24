/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:59:34 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:59:35 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
		if (width > 1)
		{
			map_line = getmap_line(line, width);
			game->map->height++;
			free(map_line);
		}
		else
			break ;
		free(line);
	}
	free(line);
}
